#include <stdio.h>

int Tong(int a, int b){
    printf("tong %d va %d la: %d\n", a, b, a+b);
    return a+b;
}
float Hieu(float a, float b){
    printf("Hieu %f va %f la: %f\n", a, b, a-b);
    return a-b;
}
void Tich(int a, int b){
    printf("Tich %d va %d la: %d\n", a, b, a*b);
}
void tinhtoan(int(*ptrTinhtoan)(int ,int), int a, int b){
    ptrTinhtoan(a,b);
}

int main (){

    void *ptr[] = {&Tong, &Tich, &Hieu};

    ((void(*)(int, int))ptr[0])(5, 5);

    ((void(*)(float, float))ptr[2])(10.3 , 5.1);

    ((void(*)(int, int))ptr[1])(5, 9);

    tinhtoan(&tong, 3, 4);

    return 0;
}
