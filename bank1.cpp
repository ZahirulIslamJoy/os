#include<unistd.h>
#include<bits/stdc++.h>

using namespace std;

int allocation[100][100];
int maxs[100][100];
int need[100][100];
int avaliable[100];
int complete[100];
vector<int> store;

void input(int res,int pro){
    cout<<"Enter allocation resorces"<<endl;
    for(int i=0;i<pro;i++){
        for(int j=0;j<res;j++){
            cin>>allocation[i][j];
        }
    }
    cout<<"Enter max resouces"<<endl;
    for(int i=0;i<pro;i++){
        for(int j=0;j<res;j++){
            cin>>maxs[i][j];
            need[i][j]=maxs[i][j]-allocation[i][j];
        }
    }
    cout<<"Enter avaliable resouces"<<endl;
    for(int i =0 ;i <res ;i++){
        cin>>avaliable[i];
    }
     for(int i =0 ;i <pro ;i++){
        complete[i]=false;
    }
}

void bankarsCalc(int res ,int pro){
    int avaliable1[100];
    for(int i=0;i<res;i++){
        avaliable1[i]=avaliable[i];
    }
    bool found=true;
    while(found){
        found =false;
        for(int i=0 ;i <pro ;i++){
            if(!complete[i]){
                int j;
                for(j=0;j<res;j++){
                    if(need[i][j] >avaliable1[j]){
                        break;
                    }
                }
                if(j==res){
                     for (int k = 0; k < res; k++)
                    {
                        avaliable1[k] += allocation[i][k];
                    }
                        complete[i]=true;
                        store.push_back(i+1);
                        found=true;
                }
              
            }                
        }
    }

   if (store.size() == pro)
    {
        cout << "Safe sequence:";
        for (int i = 0; i < pro; i++)
        {
            cout << " " << store[i]; // Print the safe execution sequence
        }
        cout << endl;
    }
    else
    {
        cout << "Unsafe state" << endl;
    }

}

void calculateagain( int newp[],int res,int pro){
    for(int i=0;i<res;i++){
        avaliable[i]-=newp[i];
        allocation[1][i] +=newp[i];
        need[1][i] -=newp[i];
    }

    bankarsCalc(res,pro);

}

int main(){
    freopen("./a.txt", "r", stdin);
    int total_resource,total_process;
    int newPro[100];
    cout<<"Enter the total resource"<<endl;
    cin>>total_resource;
    cout<<"Enter the total process"<<endl;
    cin>>total_process;
    input(total_resource,total_process);
    bankarsCalc(total_resource,total_process);
    cout<<"Enter new process"<<endl;
    for(int i =0 ;i <total_resource ;i++){
        cin>>newPro[i];
    }
    calculateagain(newPro,total_resource,total_process);
}