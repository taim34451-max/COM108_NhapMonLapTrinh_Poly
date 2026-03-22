#include <stdio.h>
#include <stdlib.h>
int main() {
    float diem;
    do {
        printf("Mời Bạn Nhập Điểm (0 - 10): ");
        scanf("%f", &diem);
        if (diem < 0 || diem > 10)
            printf("Sai Rồi! Vui Lòng Nhập Từ 0 Đến 10!\n");c
    } while (diem < 0 || diem > 10);
    if (diem < 5)
        printf("Kết Quả: Rớt\n");
    else
        printf("Kết Quả: Đậu\n");
    system("pause");
    return 0;
}
