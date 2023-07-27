#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// const  int i = 10;          // bien i duoc luu o phân vùng TEXT
//        int a = 10;          // biến toàn cục, giá trị khởi tạo khác 0, được lưu ở phân vùng DATA
// static int b = 20;          //static toàn cục, được lưu ở phân vùng DATA
/*
    void   test(){
        static int c = 30;          //Static cục bộ (tức là nằm trong hàm), được lưu ở phân vùng DATA
}*/

/*     //   BSS   ////
    int a = 0;                  //Khởi tạo bằng 0
                                                    //ĐƯỢC LƯU Ở PHÂN VÙNG BSS, KHỞI TẠO NGAY LẦN ĐẦU
    static int b;               //Không khởi tạo
*/
/*     //   PHÂN VÙNG STACK   //
void tong(int a, int b){        //int a, int b: InputParameter / int c: Biến cục bộ -> CÁC BIẾN NÀY ĐƯỢC LƯU Ở PHÂN VÙNG STACK.
    int c;
    c = a+b;
    printf("dia chi a: %p\n", &a);
    printf("dia chi b: %p\n", &b);
    printf("dia chi c: %p\n", &c);
}
*/
/*
void test1(){
    uint8_t array[5];
    printf("Dia chi: %p\n", array);
}
*/
/*
void test2(){
    uint8_t *array = (uint8_t *)malloc(sizeof(uint8_t)*5);
}
*/
int main()
{
/*     //PHÂN VÙNG STACK ///
    tong(6, 9);  // int a = 6   //0xc1
                 // int b = 9   //0xc5
                 // int c       //0xa3
    printf("--------\n");
    tong(2, 7);
*/
    uint8_t array = {1, 7, 3, 5, 9};
    printf("Dia chi: %d\n", *array);
/*
    uint16_t *ptr = (uint16_t *)malloc(sizeof(uint16_t)*5);
    for(int i = 0; i < 5; i++){
        ptr[i] = 2*i;
    }
    for(int i =0; i < 5; i++){
        printf("i = %d\n", ptr[i]);
    }
    printf("-----------\n");
    ptr = realloc(ptr, sizeof(uint16_t)*7);
        for(int i = 0; i < 7; i++){
        ptr[i] = 3*i;
    }
    for(int i =0; i < 7; i++){
        printf("i = %d\n", ptr[i]);
    }
    free(ptr);
*/
    return 0;
}
