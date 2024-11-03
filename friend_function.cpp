#include <iostream>
using namespace std;

class MyClass {
private:
    int privateVar;  // 私有成员变量

public:
    MyClass(int value) : privateVar(value) {}

    // 声明友元类
    friend class FriendClass;
};

class FriendClass {
public:
    void accessPrivateVar(const MyClass& obj) {
        cout << "Accessing privateVar from friend class: " << obj.privateVar << endl;
    }
};

int main() {
    MyClass obj(42);
    FriendClass friendObj;
    friendObj.accessPrivateVar(obj);  // 调用友元类的方法
    return 0;
}
