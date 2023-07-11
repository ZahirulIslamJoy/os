#include<iostream>
#include<queue>

using namespace std;

void calculateRoundRobin (int brusttime[],int total_process, int quantum){
    queue<int> readyQueue;
    int remaining[total_process];
    int waiting[total_process]={0};
    int turnaround[total_process]={0};

    //remainging time for each process
    for(int i=0;i<total_process;i++){
        remaining[i]=brusttime[i];
        readyQueue.push(i);
    }

    int current_time=0;
    while (!readyQueue.empty()){
        int currentProcess=readyQueue.front();
        readyQueue.pop();

        int processTime=min(quantum,remaining[currentProcess]);

        remaining[currentProcess]=remaining[currentProcess]-processTime;

        if(remaining[currentProcess] >0){
            readyQueue.push(currentProcess);
        }

        current_time=current_time+processTime;

        if(remaining[currentProcess]==0){
            turnaround[currentProcess]=current_time;
        }
        cout << "P" << currentProcess << " " << current_time << " ";


    }

     for (int i = 0; i < total_process; i++) {
        waiting[i] = turnaround[i] - brusttime[i];
    }

    cout << "\n\nProcess\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < total_process; i++) {
        cout << i << "\t" << waiting[i] << "\t\t" << turnaround[i] << endl;
    }
    
    

}


int main(){
    int total_process;
    cout<<"Enter The total number of process"<<endl;
    cin>>total_process;

    int brust_time[total_process],quantum;

    for(int i=0 ; i< total_process;i++){
        cout<<"Brust Time of process"<<i+1<<endl;
        cin>>brust_time[i];
    }

    cout<<"Enter the number of quantam"<<endl;
    cin>>quantum;
    calculateRoundRobin(brust_time,total_process,quantum);

    return 0;
}
