// #include <stdio.h> //Khai bao su dung thu vien
#include <stdio.h>
#include <stdlib.h> // can cho system()

int main()
{
    float a, b;

    // Nhap vao hai so tu ban phim
    printf("Nhap so thu nhat: ");
    scanf("%f", &a);
    printf("Nhap so thu hai: ");
    scanf("%f", &b);

    // Tinh tong va hieu
    float tong = a + b;
    float hieu = a - b;

    // Hien thi ket qua
    printf("Tong cua hai so la: %0.2f\n", tong);
    printf("Hieu cua hai so la: %0.2f\n", hieu);
    system("pause"); // hoac getch();
    return 0;
    
}