## PROGRAMMING C




<details>

<summary>Biến</summary>

- Một biến trong C là tên của vị trí bộ nhớ. Nó được sử dụng để lưu trữ dữ liệu. Giá trị của nó có thể được thay đổi và nó có thể được sử dụng lại nhiều lần. Mỗi biến trong C có một loại dữ liệu cụ thể, xác định kích thước của bộ nhớ của biến; phạm vi các giá trị có thể được lưu trữ trong bộ nhớ đó.Tên của một biến có thể bao gồm các chữ cái, chữ số và ký tự gạch dưới

## Cách khai báo cú pháp sử dụng biến

`kiểu_dữ_liệu tên_biến = giá_trị;`

##### Ví dụ:

- Biến số nguyên : `int a = 10;`
- Biến số thực (dấu chấm động có độ chính xác đơn)   : `float a = 10.3;`
- Biến số thực (dấu chấm động độ chính xác kép): `double a = 1.2345;`
- Biến ký tự     : `char a = 'abc';`
- Biến boolean   : `int True = 1;`
- Biến mảng : `int a[]= {2, 6, 4, 8, 10};`
- Biến con trỏ : `int *ptr = NULL;`

## Cách hoạt động biến Static
### Đối với static cục bộ.
- Được lưu ở phần vùng DATA nếu có khởi tạo giá trị hoặc phân vùng BSS nếu không khởi tạo giá trị và sẽ tồn tại hết vòng đời của chương trình.
- Vẫn giữ nguyên giá trị và không bị thu hồi vùng nhớ.
##### Ví dụ:
```c
#include <stdio.h>
void test(){
    static int a = 1;  //0xc1. 
    printf("a = %d\n", a);
    a++;
}
int main(){
    test();  // 1
    test();  // 2. Vì là static nên sẽ không lấy lại giá trị ban đầu mà sẽ thực hiện lệnh tiếp theo.
}
```
### Đối với static toàn cục
- Static toàn cục chỉ được sử dụng trong file.c chứa nó mà thôi, không thể truy cập sang các file.c khác trong 1 folder.
##### Ví dụ:
- trong File chứa:
`main.c`
```c
#include <stdio.h>

extern void test(); //extern sử dụng để lấy dữ liệu từ file test.c

extern int a;// Lỗi vì không thể lấy biến a từ test.c do static toàn cục.Nếu trong test.c thay static int a = 1 thành int a = 1 thì chương trình đúng.

int main(){
    test(); // a = 1
    a = 10  // a = 10
    test(); // a = 11
    return 0;
}
```
`test.c`
```c
#include <stdio.h>

static int a = 1; //Static toàn cục -> DATA
//int a=1;
void test(){
    printf("a=%d\n", a); 
    a++;
}
```

</details>

<details>

<summary>Pointer</summary>

- là biến dùng để trỏ đến địa chỉ của một biến khác chứa giá trị của biến đó.

### Cú pháp con trỏ.
`Kiểu_dữ_liệu* tên_con_trỏ`
#### Ví dụ:
- `int *ptr; // Con trỏ kiểu số nguyên`
- `float *ptr; // Con trỏ kiểu số thực`
- `void *ptr; // Con trỏ không có kiểu dữ liệu trả về` 
- `int *ptr[]; // Con trỏ kiểu mảng có kiểu số nguyên`
- `void *ptr[]; // Con trỏ kiểu mảng không có kiểu dữ liệu trả về`

### Lưu ý khi sử dụng con trỏ.
#### Kiểu dữ liệu của biến chứa giá trị khi ta tạo một con trỏ thì con trỏ đó cũng phải giống kiểu dữ liệu của biến đó.

#### Ví dụ:
```c
int a = 10; // a là biến có kiểu dữ liệu số nguyên
char b = 'c' // y là biến có kiểu dữ liệu ký tự
int *ptr = &a; // ptr là con trỏ trỏ đến địa chỉ biến a và con trỏ phải là con trỏ kiểu dữ liệu số nguyên nên chương trình đúng.
float *ptrr = &b // ptrr là con trỏ trỏ đến địa chỉ biến b nhưng mà con trỏ có kiểu dữ liệu khác kiểu dữ liệu biến b nên chương trình sai.
```

### Con trỏ NULL

Con trỏ NULL là con trỏ có địa chỉ 0x00 đây là con trỏ ứng dụng rất nhiều vào các dự án thực tế vì tính ổn định và dễ kiểm soát chương trình và khi các biến con trỏ mà ta không sử dụng thì nên gán NULL.

#### Ví dụ:
```c
int *ptr; // đây là con trỏ chưa khởi tạo và trỏ đến một địa chỉ bất kì.
int *ptrr = NULL; // đây là con trỏ có giá trị 0x00.
```
### Pointer to Pointer

Là một con trỏ trỏ đến địa chỉ của một con trỏ khác. Sử dụng rất nhiều vào các bài toán Linker list.

#### Ví dụ:
```c
 int a = 20;
 int *ptr = &a;
 int **ptp = &ptr;
 printf("Gia tri của a la: %d\n, *ptr"); // a = 10;
 printf("Dia chi của a la: %d\n", ptr); // Địa chỉ a: 0x
 printf("Gia tri cua a la: %d\n", **ptp); // a = 10;
 printf("Dia chi cua a la: %d\n", ptp); // Địa chỉ a: 0x
```

### Con trỏ hàm



</details>

<details>

<summary>Phân Vùng Nhớ</summary>

|          Stack          |
| :---------------------: |
|            ↓            |
|            ↑            |
|          Heap           |
| Bss(Uninitialized data) |
| Data(Initialized data)  |
|          Text           |

##### Text:
- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
- Chứa khai báo hằng số trong chương trình (.rodata)
##### Ví dụ
```c
#include <stdio.h>
const int i = 10;  // Biến i được lưu ở phân vùng text, chỉ đọc và không thể thay đổi giá trị
int main(){
    printf("i = %d\n, i");
    return 0;
}
```
##### Data:
- Quyền truy cập là read-write.
- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình. 
##### Ví dụ
```c
#include <stdio.h>
int a = 10;        // biến toàn cục, giá trị khởi tạo khác 0, được lưu ở phân vùng DATA
static int b = 20; //static toàn cục, được lưu ở phân vùng DATA
void test(){
    static int c = 30; //Static cục bộ(tức là nằm trong hàm), được lưu ở phân vùng DATA
}
int main(){
    printf("%d\n%d", a, b);
    test();
    //Khi thoát chương trình thì các biến này sẽ bị thu hồi lại.
    return 0;
}
```
##### Bss
- Quyền truy cập là read-write.
- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
- Được giải phóng khi kết thúc chương trình.
##### Ví dụ
```c
#include <stdio.h>
    int a = 0;    //Khởi tạo bằng 0 -> BSS
    static int b; //Static toàn cục không khởi tạo -> BSS
void test(){
    static int c; //Static cục bộ không khởi tạo -> BSS
}
int main(){
    printf("%d\n%d\n", a, b);
    test();
    return 0;
}
```
##### Stack
- Quyền truy cập là read-write.
- Được sử dụng cấp phát cho biến local, input parameter của hàm,…
- Sẽ được giải phóng khi ra khỏi block code/hàm
##### Ví dụ
```c
#include <stdio.h>
void tong(int a, int b){        //int a, int b: InputParameter. Được lưu ở phân vùng Stack
    int c;                      //int c: Biến cục bộ. Được lưu ở phân vùng stack
    c=a+b;
    printf("Tong a va b: %d\n", a+b);
    printf("dia chi a: %p\n", &a);
    printf("dia chi b: %p\n", &b);
    printf("dia chi c: %p\n", &c);
}
int main(){
    tong(5, 6); // Khởi tạo int a = 5, int b = 6, int c và có các địa chỉ tương ứng
    tong(2, 5); // Thu hồi địa chỉ các biến a,b,c của phép tính tong(5,6) và khởi tạo lại sử dụng lại các địa chỉ đó.
    return 0;
}
```
##### Heap
- Quyền truy cập là read-write.
- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
- Sẽ được giải phóng khi gọi hàm free,…
##### Ví dụ
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    uint16_t *ptr = (uint16_t *)malloc(sizeof(uint16_t)*5); //Cần 5 ô nhớ và uint16_t -> 2 byte/1 ô nhớ. Vậy malloc cần 5x2 = 10 byte.
    for(int i = 0; i < 5; i++){
        ptr[i] = 2*i;
    }
    for(int i = 0; i < 5; i++){
        printf("i = %d\n", ptr[i]);
    }
    ptr =(uint16_t *)realloc(ptr, sizeof(uint16_t)*7); //Thay đổi 5 ô nhớ thành 7 ô nhớ bằng realloc
    for(int i = 0; i < 7; i++){
        ptr[i] = 2*i;
    }
    for(int i = 0; i < 7; i++){
        printf("i = %d\n", ptr[i]);
    }
    free(ptr); //Thu hồi vùng nhớ
    return 0;
}
```

</details>

<details>

<summary>StructUnion</summary>

</details>

<details>

<summary>Compiler</summary>

</details>

<details>

<summary>MacroFunction</summary>

</details>
