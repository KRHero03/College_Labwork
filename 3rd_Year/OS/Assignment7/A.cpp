#include <bits/stdc++.h>
#define N 10
#define MAX_TRACKS 200
using namespace std;

int get_next_track(vector<int>&tracks,int head,vector<int> &mask){
    int idx = -1;
    int seek_time = MAX_TRACKS + 2;
    for(int i = 0;i<tracks.size();i++){
        if(mask[i]) continue;
        if(abs(head-tracks[i])<seek_time){
            idx = i;
            seek_time = abs(head-tracks[i]);
        }
    }
    return idx;
}

void sstf(vector<int> tracks,int initial_head){
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Shortest Seek Time First Algorithm"<<endl;
    int seek_time = 0;
    vector<int> mask(tracks.size(),0);    
    int completed = 0;
    while(completed<tracks.size()){
        int next_track = get_next_track(tracks,initial_head,mask);
        seek_time += abs(tracks[next_track]-initial_head);
        cout<<"Seeked Track "<<next_track<<" at Position: "<<tracks[next_track]<<endl;
        cout<<"Seek Time: "<<abs(tracks[next_track]-initial_head)<<endl;
        initial_head = tracks[next_track];
        mask[next_track] = 1;
        completed++;
    }
    cout<<"Total Seek Time: "<<seek_time<<endl;

}

void scan(vector<int> tracks,int initial_head){
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Scan Algorithm"<<endl;
    tracks.push_back(0);
    tracks.push_back(MAX_TRACKS-1);
    sort(tracks.begin(),tracks.end());
    int seek_time = 0;
    int idx = lower_bound(tracks.begin(),tracks.end(),initial_head + 1) - tracks.begin();
    idx--;
    for(int i = idx;i>=0;i--){
        cout<<"Seeked Track "<<i<<" at Position: "<<tracks[i]<<endl;
        cout<<"Seek Time: "<<abs(tracks[i]-initial_head)<<endl;
        seek_time += abs(tracks[i]-initial_head);
        initial_head = tracks[i];        
    }
    for(int i = idx+1;i<tracks.size();i++){
        cout<<"Seeked Track "<<i<<" at Position: "<<tracks[i]<<endl;
        cout<<"Seek Time: "<<abs(tracks[i]-initial_head)<<endl;
        seek_time += abs(tracks[i]-initial_head);
        initial_head = tracks[i];   
    }
    cout<<"Total Seek Time: "<<seek_time<<endl;
}

int main(){
    srand(time(NULL));
    vector<int> tracks;
    for(int i = 0;i<N;i++){
        tracks.push_back(rand()%MAX_TRACKS);
    }
    vector<int> displayTracks = tracks;
    sort(displayTracks.begin(),displayTracks.end());
    cout<<"Tracks: ";
    for(auto i: displayTracks) cout<<i<<" ";
    cout<<endl;
    sstf(tracks,100);
    scan(tracks,100);
}
