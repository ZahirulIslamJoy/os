#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int process,brust,single_process=0,wait=0,turnaround=0,twait=0,tturn=0;
    vector< pair <int,int>> pbrust;
    vector<int>store;
    cout<<"Enter the Number of process:";
    cin>>process;
    cout<<"Enter Brust time of each process"<<endl;
    for(int i=0;i<process;i++){
        cin>>brust;
        single_process=single_process+1;
        pbrust.push_back(make_pair(brust,single_process));
    }
    //process and brust time
    for(int i=0;i<pbrust.size();i++){
        cout<<"P"<<pbrust[i].second<<":"<<""<<pbrust[i].first<<" ";
        cout<<endl;
    }
    //sorting the pair vector
    sort(pbrust.begin(),pbrust.end());
    //counting the waiting time
    cout<<"process"<<"  waiting"<<"  turnaround"<<endl;
    for(int i=0;i<pbrust.size();i++){
        twait=twait+wait;
        turnaround=turnaround+pbrust[i].first;
        tturn=tturn+turnaround;
        cout<<"   "<<"P"<<pbrust[i].second<<"       "<<wait<<"         "<<turnaround<<endl;
        wait=wait+pbrust[i].first;
        store.push_back(turnaround);
    }
     float avgwait= double(twait)/ (process);
     float avgturn=double(tturn)/ (process);
     
    cout<<"Average Waiting time is:"<<avgwait<<endl;
    cout<<"Average Turnaround time is:"<<avgturn;
   
    // Grant Chart
    cout<<endl; 
    puts("-----------Grant Chart---------");
    cout<<endl;
    for(int i=0;i<process;i++){
        cout<<"..........|";
    }
    cout<<endl;
    for(int i=0;i<pbrust.size();i++){
        cout<<" Process"<<" "<<pbrust[i].second<<" ";
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