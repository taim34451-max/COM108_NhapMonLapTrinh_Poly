#include <stdio.h>
#include <math.h>

// Kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int choice, n;

    do {
        // Hiển thị menu đầy đủ
        printf("=== CHUONG TRINH KIEM TRA SO NGUYEN TO ===\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Thoat chuong trinh\n");
        printf("Chon chuc nang (1-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap n: ");
                scanf("%d", &n);
                if (laSoNguyenTo(n))
                    printf("%d la so nguyen to.\n", n);
                else
                    printf("%d khong phai so nguyen to.\n", n);
                break;  

            case 2:
                printf("Thoat chuong trinh.\n");
                break;

            default:3
                printf("Lua chon khong hop le. Vui long chon 1 hoac 2.\n");
                break;
        }
        printf("\n"); // Xuống dòng cho đẹp

    } while (choice != 2);

    return 0;
}