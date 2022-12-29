#ifndef T_DETAIL_H
#define T_DETAIL_H
#include <iostream>
using namespace std;

class T_Detail
{
    public:
        int t_no;
        string t_name;
        string bp;
        string dest;
        int c1;
        float c1fare;
        int c2;
        int n_o_s;
        string *stop;
        float c2fare;
        int d,m,y;
        string route;
        T_Detail *nptr;

        void getDetail();
        void stops();
        void displaydetail();
};

#endif // T_DETAIL_H
