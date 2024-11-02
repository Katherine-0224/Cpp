#include <iostream>
using namespace std;

// 函数参数
// // void f(int & i){
// //     cout<<i<<endl;
// // }

// void f(const int & i){
//     cout<<i<<endl;
// }

// int main(){
//     int i=3;
//     f(i*3);
//     return 0;
// }

// 函数返回
class A{
public:
    int i;
    A():i(0){}
};

A f(){
    A a;
    return a;
}

int g(){
    int i=10;
    return i;
}

int main(){
    f().i=10;
    // g()=10; //不可以因为函数返回的是一个值(本地变量消失)，所以不能更改
}
