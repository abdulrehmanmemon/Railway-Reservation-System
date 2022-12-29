#include "reser.h"
#include <iostream>
using namespace std;

void reser::get_login()
{
    cout << "\nEnter your id:";
    cin >> id;
    cout << "Enter the Password: ";
    cin >> password;
    cout << "\n";
}
void reser::displayid()
{
    cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
    cout << "|" << id << "\t\t" << "|" << password << "\n\n";
}
void reser::getresdet()
{
    cout<<"Passenger name:";
    cin >> pname;
    cout<<"Passenger age:";
    cin>>age;
    cout<<"\nEnter 1 for each concession category if you deserve that concession else enter 0\n";
    cout<<"1.Military\n2.Senior citizen\n";
    cout<<"3.Children below 5 yrs\n";
    cout<<"\nconcession category 1 : ";
    cin>>con1;
    cout<<"\nconcession category 2 : ";
    cin>>con2;
    cout<<"\nconcession category 3 : ";
    cin>>con3;
    do
    {
        if (con1==1)
        {
            cout<<"\nEnter the number of seats for concession category 1 : ";
            cin>>con1s;
            while(con1s<=0)
            {
                cout<<"\nEnter Correct Number of seats: ";
                cin>>con1s;
            }
        }
        if(con1==0)
            con1s=0;
        if (con2==1)
        {
            cout<<"\nEnter the number of seats for concession category 2 : ";
            cin>>con2s;
            while(con2s <= 0)
            {
                cout<<"\nEnter Correct Number of seats: ";
                cin>>con2s;
            }
        }
        if(con2==0)
            con2s=0;
        //
        if (con3==1)
        {
            cout<<"\nEnter the number of seats for concession category 3 : ";
            cin>>con3s;
            while(con3s <= 0)
            {
                cout<<"\nEnter Correct Number of seats: ";
                cin>>con3s;
            }
        }
        if(con3==0)
            con3s=0;
        if (nosr<(con1s+con2s+con3s))
            cout<<"\nEnter correct Number of seats\n";
    }while(nosr<(con1s+con2s+con3s));

    cout<<"…………END OF GETTING DETAILS…………\n";
}
void reser::displayresdet()
{
    cout<<"Pnr no: "<<pnr;
    cout<<"\nP ID: "<<id;
    cout<<"\nTrain no: "<<tno;
    cout<<"\nTrain name: "<<tname;
    cout<<"\nBoarding point: "<<board;
    cout<<"\nDestination pt: "<<destination;
    cout<<"\nNo of seats reserved: "<<nosr;
    cout<<"\nPassenger name: "<<pname;
    cout<<"\nPassenger age: "<<age;
    cout<<"\nClass : "<<clas;
    cout<<"\nDate of reservation: "<<reser_time;
    if (con1==1)
    cout<<"\nYour concession category is : 1 with "<<con1s<<" seats ";
    if (con2==1)
    cout<<"\nYour concession category is : 2 with "<<con2s<<" seats ";
    if(con3==1)
    cout<<"\nYour concession category is : 3 with "<<con3s<<" seats ";
    cout<<"\nPayment of : "<<amount;
    cout<<"\n*****\n";
}
void reser::display_not_reser()
{
	cout<<"\nPassenger No : "<<pnr;
	cout<<"\nPassenger ID : "<<id;
	cout<<"\nThe user has not made any reservations yet";
	cout<<"\n*****\n";
}
void reser::reset()
{
    tno=0;
    tname="0";
    board="0";
    destination="0";
    pname="0";
    age=0;
    clas="0";
    reser_time="0";
    nosr=0;
    con1=0;con2=0;con3=0;
    con1s=0;con2s=0;con3s=0;
    amount=0;
}
