#include <stdio.h>
#include <string.h>

#define SO_XE 3

struct XeMay {
    char hangSX[50];
    char tenXe[50];
    float giaBan;
};

int main() {
    struct XeMay xe[SO_XE];
    int luaChon;

    while (1) {

        // ===== NHAP THONG TIN XE =====
        for (int i = 0; i < SO_XE; i++) {
            printf("\nNhap thong tin xe thu %d\n", i + 1);

            printf("Hang san xuat: ");
            fgets(xe[i].hangSX, sizeof(xe[i].hangSX), stdin);
            xe[i].hangSX[strcspn(xe[i].hangSX, "\n")] = '\0';

            printf("Ten xe: ");
            fgets(xe[i].tenXe, sizeof(xe[i].tenXe), stdin);
            xe[i].tenXe[strcspn(xe[i].tenXe, "\n")] = '\0';

            printf("Gia ban: ");
            scanf("%f", &xe[i].giaBan);

            // Xoa buffer sau scanf
            while (getchar() != '\n');
        }

        // ===== XUAT THONG TIN XE =====
        printf("\n===== THONG TIN XE MAY =====\n");
        for (int i = 0; i < SO_XE; i++) {
            printf("\nXe thu %d\n", i + 1);
            printf("Hang san xuat: %s\n", xe[i].hangSX);
            printf("Ten xe: %s\n", xe[i].tenXe);
            printf("Gia ban: %.2f\n", xe[i].giaBan);
        }

        // ===== LUA CHON TIEP TUC / THOAT =====
        printf("\nNhan Enter de quay lai, nhap 0 roi Enter de thoat: ");
        luaChon = getchar();

        if (luaChon == '0') {
            printf("\nThoat chuong trinh.\n");
            break;
        }
    }

    return 0;
}
