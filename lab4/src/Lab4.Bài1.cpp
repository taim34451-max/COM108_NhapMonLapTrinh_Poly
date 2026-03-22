#include <iostream>
using namespace std;

int main() {
    int min, max;
    int i;
    float tong = 0, bienDem = 0, trungBinh = 0;
    
    cout << "Nhap gia tri min: ";
    cin >> min;
    cout << "Nhap gia tri max: ";
    cin >> max;
    
    i = min;
    
    while (i <= max) {
        if (i % 2 == 0) {
            tong += i;
            bienDem++;
        }
        i++;
    }
    
    if (bienDem > 0) {
        trungBinh = tong / bienDem;
    }
    
    cout << "Trung binh tong cac so chia het cho 2 tu " << min << " den " << max << " la: " << trungBinh << endl;
    
    return 0;
}