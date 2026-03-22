#include <stdio.h>
#include <string.h>
//Bài 2

int main() {
    char chuoi[100];
    char luaChon;

    while (1) {
        int soNguyenAm = 0;
        int soPhuAm = 0;
        int soDauCach = 0;

        printf("Nhap chuoi: ");
        fgets(chuoi, sizeof(chuoi), stdin);

        // Xoa ky tu '\n' neu co
        int doDaiChuoi = strlen(chuoi);
        if (chuoi[doDaiChuoi - 1] == '\n') {
            chuoi[doDaiChuoi - 1] = '\0';
            doDaiChuoi--;
        }

        for (int i = 0; i < doDaiChuoi; i++) {
            char kyTu = chuoi[i];

            if (kyTu == ' ') {
                soDauCach++;
            }
            else if ((kyTu >= 'A' && kyTu <= 'Z') ||
                     (kyTu >= 'a' && kyTu <= 'z')) {

                if (kyTu == 'a' || kyTu == 'e' || kyTu == 'i' ||
                    kyTu == 'o' || kyTu == 'u' ||
                    kyTu == 'A' || kyTu == 'E' || kyTu == 'I' ||
                    kyTu == 'O' || kyTu == 'U') {

                    soNguyenAm++;
                } else {
                    soPhuAm++;
                }
            }
        }

        printf("So nguyen am: %d\n", soNguyenAm);
        printf("So phu am: %d\n", soPhuAm);
        printf("So dau cach: %d\n", soDauCach);
        printf("Do dai chuoi: %d\n", doDaiChuoi);

        // Hoi tiep tuc hay thoat
        printf("\nNhan Enter de tiep tuc, nhap 0 roi Enter de thoat: ");
        luaChon = getchar();

        // Neu nhap 0 thi thoat
        if (luaChon == '0') {
            printf("\nThoat chuong trinh.\n");
            break;
        }

        // Xoa ky tu '\n' con lai trong bo dem
        getchar();
        printf("\n");
    }

    return 0;
}
