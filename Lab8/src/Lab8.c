#include <stdio.h>
#include <string.h>

struct sinhVien {
    char maSV[7];       // Kiểu dữ liệu nguyên thủy
    char hoTen[30];
    float diem;
    char thanhTuu[10];  // Thành tựu Pass/Fail
};

// Hàm tìm thành tựu theo điểm
void timThanhTuu(struct sinhVien ds[], int n) {
    for(int i = 0; i < n; i++) {
        if(ds[i].diem >= 5)
            strcpy(ds[i].thanhTuu, "Pass");
        else
            strcpy(ds[i].thanhTuu, "Fail");
    }
}

// Hàm xuất danh sách sinh viên
void xuatDSSV(struct sinhVien ds[], int n) {
    printf("\n%-10s %-15s %-6s %-8s\n", "MaSV", "Ho ten", "Diem", "Ket qua");
    for(int i = 0; i < n; i++) {
        printf("%-10s %-15s %-6.1f %-8s\n",
               ds[i].maSV, ds[i].hoTen, ds[i].diem, ds[i].thanhTuu);
    }
}

int main() {

    // Constructor tạo sẵn 4 sinh viên
    struct sinhVien sd21301[5] = {
        {"PS98765", "Teo",    6},
        {"PS65432", "Ty",     8},
        {"PS45678", "Lionel", 7},
        {"PS11111", "CR7",    10}
    };

    int n = 4;

    // Gọi hàm tìm thành tựu
    timThanhTuu(sd21301, n);

    // Gọi hàm xuất DSSV
    xuatDSSV(sd21301, n);

    return 0;
}