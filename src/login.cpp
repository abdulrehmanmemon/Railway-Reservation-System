#include "login.h"
#include <iostream>
using namespace std;

void login::set_i(string Id){
    id = Id;
}
void login::set_p(string Pa){
    password = Pa;
}
string login::get_i(){
    return id;
}
string login::get_p(){
    return password;
}
