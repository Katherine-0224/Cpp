#include <iostream>
using namespace std;
// case 1
class Fi{
public:
    Fi(){}
};

class Fee{
public:
    Fee(int){}
    Fee(const Fi&){}
};

// case 2
class Cargo{
public:
    Cargo& operator=(const Cargo&){
        cout << "inside Cargo::operator=()"<<endl;
        return *this;
    }
};

class Truck{
    Cargo b;
};

// case 3: 当参数是自身可能会发生的危险情况
// class A{
// char *p;
// A& operator=(const A& that){
//     delete p; 
//     p = new [strlen(that.p)+1]; // 指向已被收回的内存空间
//     strcpy(p, that.p);
//     return *this;
// }
// };

// case 4: 类型转换
class One{
public:
    One(){}
};

class Two{
public:
    // Two(const One&){}
    // explicit 禁止类型的自动转换
    explicit Two(const One&){} 
};

void f(Two){}

// case 5
class Orange;
class Apple{
public:
    operator Orange() const; // convert Apple to Orange
};

class Orange{
public: 
    Orange(Apple); // convert Apple to Orange
    // explicit Orange(Apple); // 这样可以避免报错
};

void f(Orange){}

int main(){
    // case 1
    Fee fee =1; // Fee(int)
    Fi fi;
    Fee fum = fi; // Fee(Fi)
    fum = fi;

    // case 2
    Truck a,b;
    a=b; // inside Cargo::operator=()
 
    // case 4
    One one;
    // f(one); // One -> Two -> f()
    f(Two(one)); // OK

    // case 5
    Apple apple;
    // f(apple); // 有两个转换函数，系统不知道用哪个，所以会报错
    return 0;
}