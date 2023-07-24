## PROGRAMMING C




<details>

<summary>Biến</summary>

- Một biến trong C là tên của vị trí bộ nhớ. Nó được sử dụng để lưu trữ dữ liệu. Giá trị của nó có thể được thay đổi và nó có thể được sử dụng lại nhiều lần. Mỗi biến trong C có một loại dữ liệu cụ thể, xác định kích thước của bộ nhớ của biến; phạm vi các giá trị có thể được lưu trữ trong bộ nhớ đó.Tên của một biến có thể bao gồm các chữ cái, chữ số và ký tự gạch dưới

### Cách khai báo cú pháp sử dụng biến

`kiểu_dữ_liệu tên_biến = giá_trị;`

##### Ví dụ:

- Biến số nguyên : `int a = 10;`
- Biến số thực (dấu chấm động có độ chính xác đơn)   : `float a = 10.3;`
- Biến số thực (dấu chấm động độ chính xác kép): `double a = 1.2345;`
- Biến ký tự     : `char a = 'abc';`
- Biến boolean   : `int True = 1;`
- Biến mảng : `int a[]= {2, 6, 4, 8, 10};`
- Biến
- Biến
- Biến

</details>

<details>

<summary>Pointer</summary>

- là biến dùng để trỏ đến địa chỉ của một biến khác chứa giá trị của biến đó.

### Cú pháp con trỏ.
`Kiểu_dữ_liệu* tên_con_trỏ`
#### Ví dụ:
`int *ptr; // Con trỏ kiểu số nguyên
 float *ptr; // Con trỏ kiểu số thực
 void *ptr; // Con trỏ không có kiểu dữ liệu trả về 
 int *ptr[]; // Con trỏ kiểu mảng có kiểu số nguyên
 void *ptr[]; // Con trỏ kiểu mảng không có kiểu dữ liệu trả về`

### Một số lưu ý khi sử dụng con trỏ.
#### Kiểu dữ liệu của biến chứa giá trị khi ta tạo một con trỏ thì con trỏ đó cũng phải giống kiểu dữ liệu của biến đó.

#### Ví dụ:
- `int a = 10; // a là biến có kiểu dữ liệu số nguyên`
- `int *ptr = &a; // ptr là con trỏ trỏ đến địa chỉ biến a và con trỏ phải là con trỏ kiểu dữ liệu số nguyên`



</details>

<details>

<summary>Phân Vùng Nhớ</summary>

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
