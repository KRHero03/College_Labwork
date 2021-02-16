/*
    Author : KRHero
    IDE: VSCode
*/

#include <bits/stdc++.h>

using namespace std;


int main(){
    cout<<"Enter a Test Hamming Code:- "<<endl;
    string s;
    cin >> s;
    int m = s.size();
    vector<int> arr;
    arr.push_back(0);
    for(auto i: s) arr.push_back(i-'0');

    int idx = 0;
    int cnt = 1;
    while(cnt<=pow(log2(m+1),2)){
        int parity = 0;
        for(int i = 1;i<arr.size();i++){
            if((i&cnt)!=0) parity ^= arr[i];
        }
        if(parity) idx += cnt;
        cnt *= 2;
    }
    arr[idx] = arr[idx]==1?0:1;
    vector<int> ans;
    for(int i = 1;i<arr.size();i++) ans.push_back(arr[i]);

    cout<<"Input Hamming Code:- "<<s<<endl;
    cout<<"Error Position:- "<<idx<<endl;
    cout<<"Corrected Hamming Code:- ";
    for(auto i: ans) cout<<i;
    cout<<endl;
    
}