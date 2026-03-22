#include <stdio.h>
#include <stdbool.h> //Boolearn
bool laNguyenTo(float y){
    if(y!=(int)y) return false; //y là số có phần thập phân, ví dụ 5.8
    if(y<=1) return false; //số NT phải lớn hơn hoặc = 1 không phải là NT
    //y sẽ là số tự nhiên >=2
    for(int k=2; k<y/2; k++)
    return true;
}
int main(){
    float x;
    printf("Nhập một số bất kì: ");
    scanf("%f",&x);
    if(laNguyenTo(x)) printf("%.0f là số nguyên tố\n",x);
    else printf("%.1f không phải số nguyên tố\n",x);
    return 0;
}