#include <bits/stdc++.h>

#define N 10
#define M 20
#define pi pair<int,int>
#define S second
#define F first

using namespace std;

void lru(vector<int>& required_pages,int frame_size){
    cout<<"Least Recently Used Cache"<<endl;
    unordered_map<int,int> umap;
    int T = 0;
    int page_faults = 0;
    for(int k = 0;k<required_pages.size();k++){
        int i = required_pages[k];
        if(umap.count(i)){
            cout<<"Found Page: "<<i<<endl;
            umap[i] = T++;
        }else{
            page_faults++;
            cout<<"Page not Found: "<<i<<" (Page Fault)"<<endl;
            if(umap.size()==frame_size){
                int least_recently_used_value = T,least_recently_used_page = -1;
                for(auto i: umap){
                    if(i.S<least_recently_used_value){
                        least_recently_used_value = i.S;
                        least_recently_used_page = i.F;
                    }
                }
                cout<<"Removed Page: "<<least_recently_used_page<<endl;
                umap.erase(least_recently_used_page);
            }
            umap[i] = T++;
            cout<<"Inserted Page: "<<i<<endl;
        }
        cout<<"Current Cache"<<endl;
        for(auto i: umap){
            cout<<"("<<i.F<<","<<i.S<<")"<<" ";
        }
        cout<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
    }
    cout<<"Total Page Faults: "<<page_faults<<endl;
    cout<<endl<<endl<<endl;

}

void optimum(vector<int>& required_pages,int frame_size){

    #define MAX required_pages.size();
    
    cout<<"Optimum Cache"<<endl;
    unordered_map<int,int> umap;
    int page_faults = 0;

    for(int k = 0;k<required_pages.size();k++){
        int i = required_pages[k];
        if(umap.count(i)){
            cout<<"Found Page: "<<i<<endl;           
            umap[i] = MAX;
            for(int j =k+1;j<required_pages.size();j++){
                if(required_pages[j]==i){
                    umap[i] = j;
                    break;
                }
            }
        }else{
            page_faults++;
            cout<<"Page not Found: "<<i<<" (Page Fault)"<<endl;
            if(umap.size()==frame_size){
                int optimum_value = -1,least_optimum_page = -1;
                for(auto i: umap){
                    if(i.S>optimum_value){
                        optimum_value = i.S;
                        least_optimum_page = i.F;
                    }
                }
                cout<<"Removed Page: "<<least_optimum_page<<endl;
                umap.erase(least_optimum_page);
            }        
            umap[i] = MAX;
            for(int j =k+1;j<required_pages.size();j++){
                if(required_pages[j]==i){
                    umap[i] = j;
                    break;
                }
            }
            cout<<"Inserted Page: "<<i<<endl;
        }
        cout<<"Current Cache"<<endl;
        for(auto i: umap){
            cout<<"("<<i.F<<","<<i.S<<")"<<" ";
        }
        cout<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
    }
    cout<<"Total Page Faults: "<<page_faults<<endl;
}

int main(){
    srand(time(NULL));
    vector<int> required_pages;    
    for(int i = 0;i<M;i++){
        required_pages.push_back(rand()%N);
    }

    lru(required_pages,3);
    optimum(required_pages,3);
}