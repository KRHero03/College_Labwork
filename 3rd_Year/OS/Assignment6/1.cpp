#include <bits/stdc++.h>
#define N 10
#define pii pair<int, pair<int,pair<int, int>>>
#define F first
#define S second
using namespace std;

struct Node
{
    int start;
    int end;
    bool occupied = false;
    int pid;
    Node *next;
    Node *prev;
    Node(int s, int e, bool o = false, int pid = -1, Node *n = NULL, Node *p = NULL)
    {
        this->start = s;
        this->end = e;
        this->next = n;
        this->occupied = o;
        this->prev = p;
        this->pid = pid;
    } 
};

struct Process
{
    int pid, arrival_time, burst_time, memory_requirement;
    Process(int p, int a, int b, int m)
    {
        this->pid = p;
        this->arrival_time = a;
        this->burst_time = b;
        this->memory_requirement = m;
    }
};

void print_linked_list(Node* main_memory){
    Node* head=main_memory;
    cout<<"Start\t\tEnd\t\tOccupied\tPID"<<endl;
    while(head){
        cout<<head->start<<"\t\t"<<head->end<<"\t\t"<<head->occupied<<"\t\t"<<head->pid<<"\t\t"<<endl;
        head = head->next;
    }
    return;
}

Node* find_first_fit_node(Node* main_memory,int mem_req){
    Node* head = main_memory;
    while(head){
        if(head->end - head->start+1>=mem_req && head->occupied==false) return head;
        head = head->next;
    }
    return NULL;
}

Node* find_best_fit_node(Node* main_memory,int mem_req){
    Node* head = main_memory;
    Node* req = NULL;
    while(head){
        if(head->end - head->start+1>=mem_req && head->occupied==false){
            if(!req) req = head;
            else if(req->end-req->start>head->end-head->start) req = head;
        }
        head = head->next;
    }
    return req;
}

Node* find_worst_fit_node(Node* main_memory,int mem_req){
    Node* head = main_memory;
    Node* req = NULL;
    while(head){
        if(head->end - head->start+1>=mem_req && head->occupied==false){
            if(!req) req = head;
            else if(req->end-req->start<head->end-head->start) req = head;
        }
        head = head->next;
    }
    return req;
}

Node* find_occupied_node(Node* main_memory,int pid){
    Node* head =  main_memory;
    while(head){
        if(head->pid==pid) return head;
        head = head->next;
    }
    return NULL;
}

void fit_algorithm(vector<Process *> &processes,int arg = 0)
{
    Node *main_memory = new Node(0, 19);
    if(arg==0)
        cout<<"First Fit Memory Allocation Algorithm"<<endl;
    else if(arg==1)
        cout<<"Best Fit Memory Allocation Algorithm"<<endl;
    else if(arg==2)
        cout<<"Worst Bit Memory Allocation Algorithm"<<endl;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(auto i: processes) pq.push({i->arrival_time,{1,{i->memory_requirement,i->pid}}});
    set<int> free_times;
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        int a_time = top.F;
        int is_entry = top.S.F;
        int mem_req = top.S.S.F;
        int pid = top.S.S.S;
        Process* p = processes[pid];

        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"Current Process at Queue Head: "<<p->pid<<endl;
        if(is_entry){
            Node* result;
            if(arg==0) result = find_first_fit_node(main_memory,mem_req);
            else if(arg==1) result = find_best_fit_node(main_memory,mem_req);
            else if(arg==2) result = find_worst_fit_node(main_memory,mem_req);
            if(!result){
                pii t1 = pq.top();
                pq.push({*free_times.begin(),{1,{mem_req,pid}}});
                cout<<"Not Slot Found!"<<endl;
            }else{
                int end = result->end;
                Node* next = result->next;
                result->occupied = true;
                result->pid = p->pid;
                result->end = result->start + mem_req - 1;
                int start = result->end + 1;
                Node* new_node = new Node(start,end);
                result->next = new_node;
                new_node->prev = result;
                if(next && next->occupied==false){
                    new_node->end = next->end;
                    new_node->next = next->next;
                    if(next->next)
                        next->next->prev = new_node;
                }else{
                    new_node->next = next;
                    if(next)
                        next->prev = new_node;
                }
                pq.push({a_time+p->burst_time,{0,{mem_req,pid}}});
                free_times.insert(a_time+p->burst_time);
                cout<<"Slot Found!"<<endl;
            }
        }else{
            free_times.erase(a_time);
            Node* occupied_node = find_occupied_node(main_memory,p->pid);
            Node* prev_node = occupied_node->prev;
            Node* next_node = occupied_node->next;
            if(!prev_node || prev_node->occupied==true){
                if(next_node->occupied==false){
                    occupied_node->end = next_node->end;
                    occupied_node->next = next_node->next;
                    if(next_node->next) next_node->next->prev = occupied_node;
                    occupied_node->occupied = false;
                    occupied_node->pid = -1;
                    free(next_node);
                    cout<<"Removed Node! Merged with Next Node!"<<endl;
                }else{
                    occupied_node->occupied = false;
                    occupied_node->pid = -1;
                    cout<<"Removed Node! No Merging!"<<endl;
                }
                
            }
            else if(!next_node || next_node->occupied==true){
                if(prev_node->occupied==false){
                    prev_node->end = occupied_node->end;
                    prev_node->next = occupied_node->next;
                    if(occupied_node->next) occupied_node->next->prev = prev_node;
                    free(occupied_node);
                    cout<<"Removed Node! Merged with Prev Node!"<<endl;
                }else{
                    occupied_node->occupied = false;
                    occupied_node->pid = -1;
                    cout<<"Removed Node! No Merging!"<<endl;
                }
            }else{
                prev_node->end = next_node->end;
                prev_node->next = next_node->next;
                if(next_node->next) next_node->next->prev = prev_node;
                free(next_node);
                free(occupied_node);
                cout<<"Removed Node! Merged with Prev Node and Next Node!"<<endl;
            }
            
        }
        cout<<"Main Memory Status"<<endl;
        print_linked_list(main_memory);
    }
    
}

int main()
{
    srand(time(NULL));
    vector<Process *> processes;
    for (int i = 0; i < N; i++)
    {
        processes.push_back(new Process(i, rand() % 10, rand() % 10+1, rand() % 10+1));
    }

    cout<<"Processes:"<<endl;
    cout<<"PID\t\tA.Time\tB.Time\tMemory Requirement"<<endl;
    for(auto i: processes) cout<<i->pid<<"\t\t"<<i->arrival_time<<"\t\t"<<i->burst_time<<"\t\t"<<i->memory_requirement<<"\t\t"<<endl;

    fit_algorithm(processes,2);
}