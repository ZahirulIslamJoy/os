#include <iostream>
#include <vector>

using namespace std;

int allocation[100][100];
int maxs[100][100];
int available[100];
int need[100][100];
bool complete[100];

void input(int resource, int process)
{
    cout << "Enter the allocation matrix:" << endl;
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the max matrix:" << endl;
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            cin >> maxs[i][j];
            need[i][j] = maxs[i][j] - allocation[i][j];
        }
    }

    cout << "Enter the available matrix:" << endl;
    for (int i = 0; i < resource; i++)
    {
        cin >> available[i];
    }

    for (int i = 0; i < process; i++)
    {
        complete[i] = false;
    }
}

void safeSequence(int resource, int process)
{
    int available1[100];
    for (int i = 0; i < resource; i++)
    {
        available1[i] = available[i];
    }
    vector<int> safe;
    bool found = true; // Initialize found as true to enter the loop
    while (found)
    {
        found = false; // Reset found to false for each iteration
        for (int i = 0; i < process; i++)
        {
            if (!complete[i])
            {
                int j;
                for (j = 0; j < resource; j++)
                {
                    if (need[i][j] > available1[j])
                    {
                        break;
                    }
                }

                if (j == resource)
                {
                    for (int k = 0; k < resource; k++)
                    {
                        available1[k] += allocation[i][k];
                    }
                    complete[i] = true;
                    safe.push_back(i + 1); // Add the process to the safe sequence
                    found = true;
                }
            }
        } 
        cout<<"value "<<found<<endl;
    }

    if (safe.size() == process)
    {
        cout << "Safe sequence:";
        for (int i = 0; i < process; i++)
        {
            cout << " " << safe[i]; // Print the safe execution sequence
        }
        cout << endl;
    }
    else
    {
        cout << "Unsafe state" << endl;
    }
}

int main()
{
    freopen("./bank.txt","r",stdin);
    int numOfRes, process_num;
    cout << "Enter the number of resources: ";
    cin >> numOfRes;
    cout << "Enter the total number of processes: ";
    cin >> process_num;
    input(numOfRes, process_num);
    safeSequence(numOfRes, process_num);
    return 0;
}
