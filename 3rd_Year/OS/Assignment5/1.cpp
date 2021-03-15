#include <bits/stdc++.h>

#define ll long long int
#define N 5
using namespace std;

class Process{
    public:
        ll pid,process_time,arrival_time,waiting_time,turnaround_time,completion_time;
        Process(ll i,ll pt,ll at){
            this->pid = i;
            this->process_time = pt;
            this->arrival_time = at;

        }

        void debug(){
            cout<<this->pid<<" "<<this->arrival_time<<" "<<this->process_time<<endl;
        }
    
};

struct CompareProcessTime {
    bool operator()(Process* const& p1, Process* const& p2)
    {
        return p1->process_time > p2->process_time;
    }
};

int main(){
    vector<Process*> processes;
    unordered_map<int,Process*> mapping;
    for(int i = 0;i<N;i++){
        processes.push_back(new Process(i,rand()%10,rand()%30));
        mapping[i] = processes[i];
    }
    cout<<"Processes"<<endl;
    cout<<"Process ID\tArrival Time\tProcess Time"<<endl;
    for(auto i: processes) cout<<i->pid<<"\t\t"<<i->arrival_time<<"\t\t"<<i->process_time<<endl;

    sort(processes.begin(),processes.end(),[&](Process* a,Process* b){
        return a->arrival_time<b->arrival_time;
    });

    cout<<endl;
    cout<<"Processes after Sorting based on Arrival Time"<<endl;
    cout<<"Process ID\tArrival Time\tProcess Time"<<endl;
    for(auto i: processes) cout<<i->pid<<"\t\t"<<i->arrival_time<<"\t\t"<<i->process_time<<endl;

    priority_queue<Process*,vector<Process*>,CompareProcessTime> readyQ;

    int current_time = processes[0]->arrival_time;
    int i = 0;
    while(i<N && processes[i]->arrival_time==current_time) {
        readyQ.push(processes[i]);
        i++;
    }
    while(!readyQ.empty() || i<N){
        if(readyQ.empty()){
            current_time = processes[i]->arrival_time;
            while(i<N && processes[i]->arrival_time==current_time) {
                readyQ.push(processes[i]);
                i++;
            }
        }
        Process* top = readyQ.top();
        readyQ.pop();
        top->completion_time = current_time + top->process_time;
        top->turnaround_time = top->completion_time - top->arrival_time;
        top->waiting_time = top->turnaround_time - top->process_time;
        current_time = top->completion_time;
        while(i<N && processes[i]->arrival_time<=current_time){
            readyQ.push(processes[i]);
            i++;
        }
        cout<<"Current Process PID: "<<top->pid<<endl;
        cout<<"Ready Q after Completion of Process: ";         
        priority_queue<Process*,vector<Process*>,CompareProcessTime> c = readyQ;
        while(!c.empty()){
            cout<<c.top()->pid<<" ";
            c.pop();
        }
        cout<<endl;
    }


    cout<<"Processes after Completion"<<endl;
    cout<<"Process ID\tArrival Time\tProcess Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;
    for(auto i: processes) cout<<i->pid<<"\t\t"<<i->arrival_time<<"\t\t"<<i->process_time<<"\t\t"<<i->completion_time<<"\t\t"<<i->turnaround_time<<"\t\t"<<i->waiting_time<<endl;



}