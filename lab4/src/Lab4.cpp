#include <stdio.h>

int main() {
    int x;
    int i = 1;
    int sum = 0;

    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    while(i <= x) {
        if(i % 2 == 0) { // dòng này kiểm tra số chẵn 
            sum += i;   // cộng số chẵn vào tổng
        }
        i++; // tăng i thêm 1
    }

    printf("Tong cac so chan tu 1 đến %d la: %d\n", x, sum);

    return 0;
}0