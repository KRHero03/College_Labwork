#include <bits/stdc++.h>

using namespace std;

bool validateData(string& s){
    if(!s.size()) return false;
    for(int i = 0;i<s.size();i++){
        if(s[i]!='1' && s[i]!='0') return false;
    }
    return true;
}

string frame(string& s){
    string res = "";
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        res += s[i];
        if(s[i]=='1'){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt==5){
            res += '0';
            cnt = 0;
        }
    }
    return res;
}

string deframe(string& s){
    string res = "";
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        res += s[i];
        if(s[i]=='0'){
            cnt = 0;
        }else{
            cnt++;
        }
        if(cnt==5){
            if(i+1<s.size() && s[i+1]!='0') return NULL;
            i++;
            cnt = 0;
        }
    }
    return res;
}

int main(){
    string s;
    cout<<"Enter Data to be Framed:- ";
    cin >> s;
    if(!validateData(s)){
        cout<<"Data is not valid! Please enter valid Data!"<<endl;
        return 0;
    }

    string framedData = frame(s);

    cout<<"Framed Data:- "<<framedData<<endl;

    string deframedData = deframe(framedData);
    
    if(deframedData.empty()){
        cout<<"Invalid Framed Data!"<<endl;
        return 0;
    }

    cout<<"Deframed Data:- "<<deframedData<<endl;

    if(!s.compare(deframedData)){
        cout<<"Original Data and Deframed Data matched Successfully!"<<endl;
    }else{
        cout<<"Original Data and Deframed Data did not match!"<<endl;
    }

    return 0;

}

/*
Enter Data to be Framed:- 0110111111100111110111111111100000
Framed Data:- 01101111101100111110011111011111000000
Deframed Data:- 0110111111100111110111111111100000
Original Data and Deframed Data matched Successfully!
*/