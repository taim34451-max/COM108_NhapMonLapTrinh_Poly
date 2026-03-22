#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10], n;//n là số phần tử thực tế của mảng
    printf("Nhập số phần tử mảng(<=10): "); scanf("%d",&n);
    for (int i = 0; i < n; i++) //ví dụ n=3, a[0], a[1], a[2]
    {
        printf("Nhập PT mảng: ");
        scanf("%d",&a[i]);
    }
    printf("Mảng vừa nhập: \n");
    for (int i = 0; i < n; i++) //Yêu cầu 2
        printf("a[%d]: %d\n",i, a[i]);
    printf("Những PT mảng chia hết cho 3: \n");
    for (int i = 0; i < n; i++) //Yêu cầu 3
        if(a[i]%3==0) printf("a[%d]: %d\n",i, a[i]);
    system("pause");
    return 0;
}

