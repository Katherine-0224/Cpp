#include <iostream>
using namespace std;

inline int f(int i){
    return i*2;
}
int main(){
    int a=4;
    int b=f(a); // 等同于 int b=a*2;
    return 0;
}

