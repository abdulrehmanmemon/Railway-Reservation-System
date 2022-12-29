#ifndef RESER_H
#define RESER_H
#include <iostream>
#include <T_Detail.h>
#include <login.h>

class reser : public T_Detail, public login
{
  public:
        reser *nptr;
        int pnr;
        int tno;
        string tname;
        string board;
        string destination;
        string pname;
        int age;
        string clas;
        string reser_time;
        int nosr;
        int con1,con2,con3;
        int con1s,con2s,con3s;
        float amount;
        friend float value(reser *rcptr,T_Detail *cptr);

        void get_login();
        void displayid();
        void getresdet();
        void displayresdet();
        void display_not_reser();
        void reset();
};

#endif // RESER_H
