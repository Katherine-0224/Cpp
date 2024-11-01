#include <iostream>
using namespace std;
// Declaration
struct X; // 前置声明，跟编译器说X是一个东西，其余没有别的信息

struct Y{
    void f(X* x);
};

//Definition
struct X{
private:
    int i;
public:
    void initialize();
    friend void g(X*, int); //Global friend
    friend void Y::f(X*); //Struct member friend
    friend struct Z; // entire struct is a friend
    friend void h();
};

void X:: initialize(){
    i=0;
}

void g(X* x, int i){
    x->i =i;
}

void Y::f(X* x){
    x->i =47;
}

struct Z{
private:
    int j;
};
