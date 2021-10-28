#include <bits/stdc++.h>

using namespace std;

template<typename T>

class CustomStack{
    private:
        T* ptr;
        int size;
        int top = -1;
    public:
        CustomStack(int s){
            ptr = new T[s];
            size = s;
        }
        void push(T v){
            if(is_full()){
                return;
            }
            top++;
            ptr[top] = v;
        }
        bool is_empty(){
            return top==-1;
        }
        bool is_full(){
            return top==size-1;
        }
        T pop(){
            if(is_empty()){
                return NULL;
            }
            T val = ptr[top];
            top--;
            return val;
        }
        T get_top(){
            if(is_empty()){
                return NULL;
            }
            return ptr[top];
        }
        int get_size(){
            return top + 1;
        }
};

int main(){
    CustomStack<int>* stack = new CustomStack<int>(5);
    cout<<"Created custom stack."<<endl;
    cout<<"Is stack empty? "<<stack->is_empty()<<endl;
    stack->push(5);
    stack->push(4);
    cout<<"Stack Top Value: "<<stack->get_top()<<endl;
    cout<<"Stack size: "<<stack->get_size()<<endl;
    int val = stack->pop();
    cout<<"Popped value from stack: "<<val<<endl;
    cout<<"New size: "<<stack->get_size()<<endl;
}