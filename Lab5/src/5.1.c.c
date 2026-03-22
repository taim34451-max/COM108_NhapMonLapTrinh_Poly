#include <stdio.h>
#include <stdlib.h> // Thư viện cần thiết cho lệnh system("pause")

// 1. Cập nhật hàm để nhận vào 3 tham số: x, y, z
int tong3So(int x, int y, int z) {
    int tong = x + y + z;
    return tong;
}

int main() {
    // 2. Khai báo thêm biến c
    int a, b, c;
    
    printf("Nhập số a: "); scanf("%d", &a);
    printf("Nhập số b: "); scanf("%d", &b);
    
    // 3. Nhập giá trị cho c
    printf("Nhập số c: "); scanf("%d", &c);

    // 4. Gọi hàm tong3So và truyền đủ 3 tham số
    printf("Tổng a + b + c = %d\n", tong3So(a, b, c));

    system("pause"); 
    return 0;
}