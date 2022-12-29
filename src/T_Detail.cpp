#include "T_Detail.h"
#include <iostream>
using namespace std;

void T_Detail::getDetail()
{
    cout << "\nTrain Name: ";
    cin >> t_name;
    cout<<"\nEnter Number of Stops: ";
    cin>>n_o_s;
    stop=new string[n_o_s];

    for(int i=0;i<n_o_s;i++){
        n:
        cout<<"\nEnter the Name of Stop: ";
        cin>>stop[i];
        for (int j=0;j<i;j++){
            if (stop[i]==stop[j])
            {
                cout<<"\nExisting Stop is written again Enter again\n";
                goto n;
            }
        }
    }
    cout << "\nNo of seats in first class: ";
    cin >> c1;
    while(c1<=0){
        cout<<"\nEnter approperiate Number of seats: ";
        cin>>c1;
    }
    cout<<"\nfirst class fare per ticket: ";
    cin>> c1fare;
    while(c1fare<=0){
        cout<<"\nEnter approperiate fare: ";
        cin>>c1fare;
    }
    cout << "\nNo of seats in second class: ";
    cin >> c2;
    while(c2<=0){
        cout<<"\nEnter approperiate Number of seats: ";
        cin>>c2;
    }
    cout<<"\nsecond class fare per ticket: ";
    cin>> c2fare;
    while(c2fare<=0){
        cout<<"\nEnter approperiate fare: ";
        cin>>c2fare;
    }
    cout<<"Date of travel:";
    cout<<"\nDay : ";
    cin>>d;
    while (d>31 || d<=0)
    {
        cout<<"\nEnter the approperiate Number of Days : ";
        cin>>d;
    }
    cout<<"\nMonth : ";
    cin>>m;
    while(m>12 || m<=0)
    {
        cout<<"\nEnter the approperiate Number of Months : ";
        cin>>m;
    }
    cout<<"\nYear : ";
    cin>>y;
    while(y<=0){
        cout<<"\nEnter the approperiate Number of Years : ";
        cin>>y;
    }
    cout<<"\nEnter the route details: ";
    cin.ignore();
    getline(cin,route);
}
void T_Detail::stops()
{
    stop = new string[n_o_s];
}
void T_Detail::displaydetail()
{
    cout << "\n|Train No." << "\t" << "|Train Name" <<"\t";
    cout << "|F-Class" << "\t"<< "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" <<"\t";
    cout << "|Day" << "-" << "Month" << "-" << "Year" << "\t\t"<<"|Route"<<"\n";
    cout << "|" << t_no << "\t\t" << "|" << t_name << "\t\t";
    cout << "|" << c1 << "\t\t" << "|"<< c1fare << "\t\t" << "|" << c2<< "\t\t" << "|" << c2fare <<"\t\t";
    cout << "|" << d << "-" << m << "-" << y << "\t\t"<<"|"<<route<<"\n";
    cout<<"\n|Stops";
    for(int i=0;i<n_o_s;i++){
        cout<<"\t\t|"<<stop[i];
    }
    cout<<"\n";
}
