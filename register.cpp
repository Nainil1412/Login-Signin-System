#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string usn;
int tm;
void valid(string str)
{
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid(usn);
    }
}

int main()
{
    int choice,i,exit=0;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    cout<<endl;
    cout<<"********** Welcome!! **********\n";
    while(exit==0)
    {
        cout<<"\nChoose one option:\n\n1. Press 1 to select SignIn/LogIn\n2. Press 2 to select SignUp/Register\n3. Exit\n";
        cout<<"\nEnter your optopn : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username : ";
            cin>>usn;
            cout<<"\nEnter your password : ";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in....\nYOUR PROFILE SAYS:\n";
                cout<<"User-name : "<<usern<<endl;
                cout<<"Name : "<<line<<endl;
                getline(filei,line);
                cout<<"Introduction : "<<line<<endl;
                filei.close();
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name : ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username : ";
            cin>>usn;
            tm=0;
            valid(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password : ";
            cin>>psd;
            fname=usn+".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered..";
            cout<<"\nAdd Information about your self and press enter when you are done : ";
            cin.ignore();
            getline(cin,bio);
            fileo<<bio<<endl;
            cout<<"\nYour bio is saved as: "<<bio;
            fileo.close();
        }
        else if (choice==3)
        {
            exit=1;
        }
        
        
    }
    cout<<"\n********** Thank you!! **********\n";
}
