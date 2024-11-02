int* f(int* x){
    (*x)++;
    return x;
}

// same effect as in f()
int& g(int& x){
    x++;
    return x;
}

int x;
// 不能双重引用
// int &a=x;
// int &b=a;

int& h(){
    int q;
    // return q; //Error
    return x; // x是全局变量
}

int main(){
    int a=0;
    f(&a); // a=1
    g(a); // a=2
    h()=16; // x=16 (reference 可以做左值)
    return 0;
}

