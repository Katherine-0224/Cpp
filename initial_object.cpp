#include<iostream>
using namespace std;

class X{
public:
	X();
};

// 构造函数不可为空
// 未构造的函数不可直接析构
X::X(){}

//void f(int i){
//	if(i<10){
//		goto jump1;
//	}
//	X x1;
//	jump1:
//		switch(i){
//		case 1:
//			X x2;
//			break;
//		}
//}
