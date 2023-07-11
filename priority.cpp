#include<bits/stdc++.h>
using namespace std;

int main(){
    int process,brust,priority,wait=0,turn=0,twait=0,tturn=0;
    vector < pair<int,pair<int,int>>>vect;
    vector<int>store;
    freopen("priority.txt","r",stdin);
    cout<<"Enter The number of process:";
    cin>>process;
    for( int i=0;i<process;i++){
        cout<<"Enter brust time and priority  process:"<<i+1<<endl;
        cin>>brust>>priority;
        vect.push_back(make_pair(priority,make_pair(i+1,brust)));
    }
    
    int s = vect.size();
    cout<<"Process Brusttime and Priority"<<endl;
    for(int i=0;i<vect.size();i++){
        cout<<"P"<<vect[i].second.first<<" "<<vect[i].second.second<<" "<<vect[i].first<<endl;
    }
    sort(vect.begin(),vect.end());
    //waiting time
    cout<<"Process waiting  turnaroud"<<endl;
    for( int i=0;i<s;i++){
        turn=turn+vect[i].second.second;
         twait=twait+wait;
        cout<<"P"<<vect[i].second.first<<"        "<<wait<<"          "<<turn<<endl;
        wait=wait+vect[i].second.second;
        tturn=tturn+turn;
        store.push_back(turn);
    }
    float avgw=double(twait)/(process);
    float avgt=double(tturn)/(process);
    cout<<endl;
    cout<<"Average Waiting Time is:"<<avgw<<endl;
    cout<<"Average Turnaround Time is:"<<avgt<<endl;
    cout<<endl; 
    puts("-----------Grant Chart---------");
    cout<<endl;
    for(int i=0;i<process;i++){
        cout<<"..........|";
    }
    cout<<endl;
    for(int i=0;i<s;i++){
        cout<<" Process"<<" "<<vect[i].second.first<<" ";
    }
    cout<<endl;
     for(int i=0;i<process;i++){
        cout<<"..........|";
    }
    cout<<endl;
    cout<<"0";
    for( int i=0;i<store.size();i++){
        cout<<"         "<<store[i];
    }
}