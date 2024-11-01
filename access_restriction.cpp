#include<iostream>
using namespace std;
class A{
private:
	int i;
    int *p;
public:
	A(){
		i=0;
		cout << "A::A()" << endl;
	}
	~A(){
		cout << "A::~A(), i= " <<i<< endl;
	}
	void set(int ii){
		i=ii;
	}
	void f(){
		cout << "hello" << endl;;
	}
    // 同一个类的对象可以相互访问private变量
    void g(A* q){
        cout << q->i << endl; //100
    }
};

int main(){
	A*p=new A[10];
	for(int i=0;i<10;i++){
		p[i].set(i);
	}
    A b;
    b.set(100);
    p[0].g(&b);
	delete[] p;
	return 0;
}