#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo và gán chuỗi như yêu cầu trong comment
    char fullName[30] = "Mai Thành Tài"; 
    
    int i = 0;
    
    // Vòng lặp chạy đến khi gặp ký tự kết thúc chuỗi '\0'
    while (fullName[i] != '\0') 
    {
        if (fullName[i] != ' ') // Nếu ký tự khác dấu cách (space)
        {
            // LƯU Ý: Trong hình dùng "%s" là sai, phải dùng "%c" để in một ký tự
            printf("%c", fullName[i]); 
        }
        else 
        {
            // Nếu gặp dấu cách thì xuống dòng
            printf("\n");
        }
        i++;
    }
    
    return 0;
}