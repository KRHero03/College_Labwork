/*
    Author : KRHero
    IDE: VSCode
*/

#include <bits/stdc++.h>

using namespace std;


int main(){
    cout<<"Please enter Input Code:-"<<endl;
    string s;
    cin >> s;
    int n = s.size();
    int pCount = ceil(log2(n+1));
    vector<int> parityBits(pCount,0);

    vector<int> res;
    int p = 1;
    int idxParity = 0,idxInput = 0;
    res.push_back(0);
    while(p<=parityBits.size()+n){
        if(__builtin_popcount(p)==1){
            res.push_back(parityBits[idxParity++]);
        }else{
            res.push_back((s[idxInput++]-'0'));
        }
        p++;
    }
    p = pow((int)log2(res.size()),2);
    int cnt = 1;
    while(cnt<=p){
        for(int i=1;i<res.size();i++){
            if((i&cnt)!=0) res[cnt] ^= res[i];
        }
        cnt*=2;
    }
    vector<int> ans;
    for(int i = 1;i<res.size();i++) ans.push_back(res[i]);
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"Input Code:- ";
    cout<<s<<endl;
    cout<<"Input Code Size:- "<<s.size()<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"Transmitted Code:- ";
    for(auto i: ans) cout<<i;
    cout<<endl;
    cout<<"Transmitted Code Size:- "<<ans.size()<<endl;

    

}