#include<stdio.h>

int main(){
    const char *s1 = "hello, world";
    char s2[] = "hello, world";
    printf("s1=%p\n",s1); // s1=0x1001d7f94 （代码）
    printf("s2=%p\n",s2); // s2=0x16fc2b1d8 (堆栈)
    printf("main=%p\n",main); // main=0x1001d7eb4
    return 0;
}


