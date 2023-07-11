#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main()
{
    int num;
    cout<<"1. Create File\n2.Rename\n3.Delete\n4.Copy\n5.Move"<<endl;
    cout<<"Enter number: ";
    cin>>num;
    cin.ignore();


    if(num==1)
    {
        string name;
        getline(cin, name);
        ofstream newFile(name.c_str());
        cout<<"File Created"<<endl;
        newFile<<"Hello World";
        newFile.close();
    }
    else if(num == 2)
    {
        string oldName, newName;
        getline(cin, oldName);
        getline(cin, newName);
        int renamed = rename(oldName.c_str(), newName.c_str());
        if(renamed)
        {
            cout<<"Rename failed"<<endl;;
        }
        else cout<<"Renamed";

    }
    else if(num == 3)
    {
        string fileName;
        getline(cin, fileName);
        int deleted = remove(fileName.c_str());
        if(deleted)
        {
            cout<<"Deletion failed";
        }
        else cout<<"File Deleted";
    }
    else if(num == 4)
    {
        string from, to;
        getline(cin, from);
        getline(cin, to);
        ifstream sourceFile(from.c_str(), ios::binary);
        ofstream destinationFile(to.c_str(), ios::binary);
        string line;
        if(sourceFile and destinationFile)
        {
            while(getline(sourceFile, line))
            {
                destinationFile << line <<"\n";
            }
            sourceFile.close();
            cout<<"File copied successfully.";
        }
        else cout<<"Copy failed";

    }
    else if(num == 5)
    {
        string from, to;
        getline(cin, from);
        getline(cin, to);
        ifstream sourceFile(from.c_str());
        ofstream destinationFile(to.c_str());
        string line;
        if(sourceFile and destinationFile)
        {
            while(getline(sourceFile, line))
            {
                destinationFile<<line<<"\n";
            }
            sourceFile.close();
            cout<<"File Moved successfully"<<endl;
            remove(from.c_str());
        }
        else cout<<"Move failed";


    }
}