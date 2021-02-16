/*
   Author : KRHero
   IDE: VSCode
*/


#include <bits/stdc++.h>

#define DLE 10
#define STX 2
#define ETX 3
using namespace std;

bool validateData(string& s){
    if(!s.size()) return false;
    return true;
}

string frame(string& s){
    string res;
    res += DLE;
    res += STX;

    for(int i = 0;i<s.size();i++){
        res += s[i];
        if(s[i]==DLE) res += DLE;
    }

    res += DLE;
    res += ETX;
    return res;
}

string deframe(string& s){
    string res = "";
    if(s.size()<4) return NULL;

    if(s[0]!=DLE && s[1]!=STX) return NULL;
    if(s[s.size()-2]!=DLE && s[s.size()-1]!=ETX) return NULL;
    for(int i = 2;i<s.size()-2;i++){
        res += s[i];
        if(s[i]==DLE){
            if(i+1<s.size() && s[i]!=DLE) return NULL;
            else{
                i++;
                continue;
            }

        }
    }

    return res;
}

void print(string& s){

    for(auto i: s) cout<<(int)i<<" ";
    cout<<endl;
}

int main(){
    string s;
    cout<<"Enter Data to be Framed:- ";
    cin >> s;
    if(!validateData(s)){
        cout<<"Data is not valid! Please enter valid Data!";
        return 0;
    }

    string framedData = frame(s);

    cout<<"Framed Data:- "<<endl;
    cout<<framedData<<endl;
    print(framedData);
    cout<<endl;

    string deframedData = deframe(framedData);
    
    if(deframedData.empty()){
        cout<<"Invalid Framed Data!"<<endl;
        return 0;
    }

    cout<<"Deframed Data:- "<<endl;
    cout<<deframedData<<endl;
    print(deframedData);
    cout<<endl;

    if(!s.compare(deframedData)){
        cout<<"Original Data and Deframed Data matched Successfully!"<<endl;
    }else{
        cout<<"Original Data and Deframed Data did not match!"<<endl;
    }

    return 0;

}
/*
Enter Data to be Framed:- asdwqewqe
Framed Data:- 

asdwqewqe

10 2 97 115 100 119 113 101 119 113 101 10 3 

Deframed Data:- 
asdwqewqe
97 115 100 119 113 101 119 113 101 

Original Data and Deframed Data matched Successfully!
*/