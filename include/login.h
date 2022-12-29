#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
using namespace std;

class login
{
    protected:
        string id;
        string password;
    public:
        void set_i(string Id);
        void set_p(string Pa);
        string get_i();
        string get_p();
};
#endif // LOGIN_H
