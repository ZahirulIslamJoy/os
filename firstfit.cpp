#include<bits/stdc++.h>

using namespace std;

int main(){
    int total_holes,process_size,x;
    cout<<"Total Memory holes"<<endl;
    cin>>total_holes;
    vector <int> holes_size;
    cout<<"Enter the the Memory holes size"<<endl;
    for(int i=0 ;i<total_holes;i++){
        cin>>x;
        holes_size.push_back(x);
    }
     cout<<"Enter the the process size"<<endl;
     cin>>process_size;
     cout<<endl;
     for(int i=0 ;i<total_holes;i++){
        if(holes_size[i]>=process_size){
            cout<<"The process will allocate into "<<holes_size[i]<<" mb memory hole";
            break;
        }      
    }
     cout<<"No hole avaliable"<<endl;
}