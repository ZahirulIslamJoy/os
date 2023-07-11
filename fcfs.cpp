#include<unistd.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
   int process_number,process,sum=0;
    vector<int> parray;
    vector<int> arrival_array;
    vector<int> waiting;
    int b=1;
   cout<<"Enter the number of process:";
   cin>>process_number;
   for( int i=1;i<=process_number;i++){
        cout<<"Enter Brust Time of process:"<<b<<"\n";
        cin>>process;
       parray.push_back(process);
        b++;
   }
    for(int i=0;i<parray.size();i++)
    {
        //arrival_array.push_back(parray[i-1]+parray[i]);
        sum=sum+parray[i];
        arrival_array.push_back(sum);

    }
    //arival checking
     /*for(int i=0;i<arrival_array.size();i++)
    {
        cout<<arrival_array[i]<<" ";
    }*/
    for( int i=0;i<parray.size();i++){
        waiting.push_back(arrival_array[i]-parray[i]);
    }
     int j=1,sum1=0;
     for(int i=0;i<waiting.size();i++)
    {
        cout<<"waiting time of process "<<j<<": "<<waiting[i];
        cout<<"\n";
        j++;
    }
     for(int i=0;i<waiting.size();i++)
    {
        sum1=sum1+waiting[i];

    }
    int size1=waiting.size();
     float x= ( double(sum1))/size1;
     cout<<"Average Waiting time: "<<x<<"\n";

     //grant chart
     puts("------------Grant Chart--------\n");
     for(int i=0;i<process_number;i++){
        cout<<"---------|";
     }
     cout<<"\n";
     for(int i=1;i<=process_number;i++){
        cout<<"Process "<<i<<" ";
     }
     cout<<"\n";
     for(int i=0;i<process_number;i++){
        cout<<"---------|";
     }
     cout<<"\n";
     cout<<"0";
     for(int i=0;i<arrival_array.size();i++)
    {
        cout<<"       "<<arrival_array[i]<<" ";
    }

}
