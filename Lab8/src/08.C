#include <stdio.h>  // Thu vien nhap xuat co ban
#include <string.h> // Thu vien de lay do dai chuoi

struct XeMay {
    char hang[50], ten[50];
    float gia;
};

void bai1() {
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("So chinh phuong: ");
    for (int i = 0; i * i <= n; i++) printf("%d ", i * i);
    printf("\n");
}

void bai2() {
    char s[100];
    int nA = 0, pA = 0, dC = 0;
    printf("Nhap chuoi: ");
    fflush(stdin); gets(s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') dC++;
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            // Kiem tra nguyen am (ca hoa va thuong)
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
                s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') nA++;
            else pA++;
        }
    }
    printf("Nguyen am: %d, Phu am: %d, Khoang cach: %d, Do dai: %d\n", nA, pA, dC, len);
}

void bai3() {
    struct XeMay ds[3];
    for (int i = 0; i < 3; i++) {
        printf("Xe %d - Hang: ", i+1); fflush(stdin); gets(ds[i].hang);
        printf("Xe %d - Ten: ", i+1); gets(ds[i].ten);
        printf("Xe %d - Gia: ", i+1); scanf("%f", &ds[i].gia);
    }
    for (int i = 0; i < 3; i++)
        printf("%s | %s | %.2f\n", ds[i].hang, ds[i].ten, ds[i].gia);
}

int main() {
    int chon;
    do {
        printf("\n1.Bai 1 | 2.Bai 2 | 3.Bai 3 | 0.Thoat\nChon: ");
        scanf("%d", &chon);
        if (chon == 1) bai1();
        else if (chon == 2) bai2();
        else if (chon == 3) bai3();
        
        if (chon != 0) {
            printf("\nBam 1 de tiep tuc, 0 de thoat: ");
            scanf("%d", &chon);
            if (chon == 0) break;
        }
    } while (chon != 0);
    return 0;
}