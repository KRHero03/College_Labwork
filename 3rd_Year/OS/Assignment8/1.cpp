#include <bits/stdc++.h>

using namespace std;

unordered_map<string,bool> fileSystem;

void insertFile(){
    cout<<"Enter File Name: ";
    string fileName;
    cin >> fileName;
    fileSystem[fileName] = 1;
    cout<<"File "<<fileName<<" inserted in Master File Directory!"<<endl;
}

void displayFiles(){
    if(fileSystem.size()==0){
        cout<<"No Files in Master File Directory!"<<endl;
        return;
    }
    cout<<"Displaying all Files in Master File Directory: "<<endl;
    for(auto i: fileSystem){
        cout<<i.first<<endl;
    }
}

void deleteFile(){
    cout<<"Enter File Name: ";
    string fileName;
    cin >> fileName;
    if(fileSystem.find(fileName)==fileSystem.end()){
        cout<<"File "<<fileName<<" not found in Master File Directory!"<<endl;
        return;
    }
    fileSystem.erase(fileName);
    cout<<"File "<<fileName<<" deleted!"<<endl;

}

void searchFile(){
    cout<<"Enter File Name: ";
    string fileName;
    cin >> fileName;
    if(fileSystem.find(fileName)==fileSystem.end()){
        cout<<"File "<<fileName<<" not found in Master File Directory!"<<endl;
        return;
    }
    cout<<"File "<<fileName<<" found in Master File Directory!"<<endl;

}

void printMenu(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"User Options:"<<endl;
    cout<<"1. Create File"<<endl;
    cout<<"2. Display All Files"<<endl;
    cout<<"3. Delete File"<<endl;
    cout<<"4. Search File"<<endl;
    cout<<"5. Exit Program"<<endl;
    cout<<">> ";
}

int main(){
    cout<<"Single Level Directory System"<<endl;
    int choice=-1;
    while(choice!=5){
        printMenu();
        cin >> choice;
        if(choice==1){
            insertFile();
        }else if(choice==2){
            displayFiles();
        }else if(choice==3){
            deleteFile();
        }else if(choice==4){
            searchFile();
        }else if(choice==5){
            break;
        }else{
            cout<<"Invalid Choice!"<<endl;
        }

    }
}