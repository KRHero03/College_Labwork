#include <bits/stdc++.h>

using namespace std;

template<typename T>

class CustomVector{
    public:
        T* ptr;
        int s;
        CustomVector(int size){
            ptr = new T[s];
            s = size;
        }
        CustomVector(int size, T d){
            ptr = new T[s];
            s = size;
            for(int i = 0;i<s;i++) ptr[i] = d;
        }
        void modify(int p,T v){
            if(!(p>=0 && p<s)) return;
            ptr[p] = v;
        }
        int size(){
            return s;
        }    
};

int main(){
    CustomVector<int>* new_vec = new CustomVector<int>(5,0);

    cout<<"Created new Custom Vector."<<endl;
    for(int i = 0;i<5;i++) cout<<new_vec->ptr[i]<<" ";
    cout<<endl;

    new_vec->modify(2,4);
    cout<<"Modified value in Custom Vector"<<endl;
    for(int i = 0;i<5;i++) cout<<new_vec->ptr[i]<<" ";
    cout<<endl;



}