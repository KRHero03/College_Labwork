
#include <bits/stdc++.h>
using namespace std;

template<class T>

void custom_swap(T& a,T& b){
    T p = a;
    a = b;
    b = p;
}

int main(){
    int a = 9, b = 10;
    cout<<"A: "<<a<<" B: "<<b<<endl;
    custom_swap(a,b);
    cout<<"After swapping - A: "<<a<<" B: "<<b<<endl;
    char a_c = 'P',b_c='Q';
    cout<<"A_C: "<<a_c<<" B_C: "<<b_c<<endl;
    custom_swap(a_c,b_c);
    cout<<"After swapping - A_C: "<<a_c<<" B_C: "<<b_c<<endl;

}