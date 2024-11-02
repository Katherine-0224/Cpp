#include <iostream>
#include <string>
using namespace std;

static int objectCount = 0;

class HowMany{
public:
    HowMany(){
        objectCount++; 
        print("HowMany()");
    }
    HowMany(int i){
        objectCount++; 
        print("HowMany(int)");
    }
    // copy constructor
    HowMany(const HowMany& o){
        objectCount++; 
        print("HowMany(HM)");
    }
    // const string& msg="": 这是一
    // 使用 const string& 的引用类型可以避免传值的拷贝，提高性能，const 确保在函数内部不会修改 msg 的值。
    void print(const string& msg=""){
        if(msg.size()!=0)
            cout<<msg<<": ";
        cout<<"objectCount= "<< objectCount<< endl; 
    }
    ~HowMany(){
        objectCount--;
        print("~HowMany()");
    }
};

// pass and return by value
HowMany f(HowMany x){ 
    cout << "begin of f" << endl; 
    x.print("x argument inside f()"); 
    cout << "end of f" << endl;
    return x;
}

int main(){
    HowMany h; 
    h.print("after construction of h"); 
    HowMany h2=f(h);
    HowMany h3(10); // 等同于 HowMany h3=10;
    h.print("after call to f()");
}

// 程序中 HowMany x和HowMany h2绕过构造函数直接构造，所以最后析构完成 objectCount=-2
// HowMany(): objectCount= 1
// after construction of h: objectCount= 1
// begin of f
// x argument inside f(): objectCount= 1
// end of f
// ~HowMany(): objectCount= 0
// HowMany(int): objectCount= 1
// after call to f(): objectCount= 1
// ~HowMany(): objectCount= 0
// ~HowMany(): objectCount= -1
// ~HowMany(): objectCount= -2

// 加入HowMany(const HowMany& o){ objectCount++; print("HowMany(HM)");} 后
// HowMany(): objectCount= 1
// after construction of h: objectCount= 1
// HowMany(HM): objectCount= 2
// begin of f
// x argument inside f(): objectCount= 2
// end of f
// HowMany(HM): objectCount= 3
// ~HowMany(): objectCount= 2
// HowMany(int): objectCount= 3
// after call to f(): objectCount= 3
// ~HowMany(): objectCount= 2
// ~HowMany(): objectCount= 1
// ~HowMany(): objectCount= 0