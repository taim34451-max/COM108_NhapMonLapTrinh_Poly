#include <stdio.h>
//Bài 1

int main() {
    int n;
    int luaChon;

    while (1) {
        // Nhap so nguyen duong
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);

        printf("Cac so chinh phuong <= %d la:\n", n);
        for (int i = 1; i * i <= n; i++) {
            printf("%d ", i * i);
        }

        // Hoi tiep tuc hay thoat
        printf("\n\nNhan Enter de tiep tuc, nhap 0 roi Enter de thoat: ");

        getchar();              // xoa '\n' con lai
        luaChon = getchar();    // doc lua chon

        if (luaChon == '0') {
            printf("\nThoat chuong trinh.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
