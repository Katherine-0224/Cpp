#include <stdio.h>
#include<cstring> // cpp中的字符串函数库
class Person{
public:
    Person(const char *s){
        name = new char[::strlen(s)+1];
        ::strcpy(name,s);
    }
    Person(const Person& w){ // 拷贝构造
        name = new char[::strlen(w.name)+1];
        ::strcpy(name,w.name);
    }
    ~Person(){
        delete [] name;
    }
    void print();
    char *name;
};

int main(){
    Person p1("John");
    Person p2(p1);
    // 会导致重复析构
    printf("p1.name=%p\n", p1.name); // p1.name=0x152f05580
    printf("p2.name=%p\n", p2.name); // p2.name=0x152f05580
    // 加入拷贝构造
    printf("p1.name=%p\n", p1.name); // p1.name=0x139005620
    printf("p2.name=%p\n", p2.name); // p2.name=0x139005630

    return 0;
}