#include <iostream>
using namespace std;

// Subsoal 1, 2 & 3, N <= 17
int n;
int aman[17]; 

int kena_berapa_kali(int hari, int posisi){
    int kena = 0;
    if(posisi != aman[hari]) kena++;

    if(hari == n-1) return kena;

    int kena_berapa_kalau_ikut_arus = kena_berapa_kali(hari+1, posisi+1);
    int kena_berapa_kalau_balik = kena_berapa_kali(hari+1, 1);

    return kena + min(kena_berapa_kalau_ikut_arus, kena_berapa_kalau_balik);
}

int main(){
    cin >> n;
    for(int i = 0;i<n;i++) cin >> aman[i];

    cout << kena_berapa_kali(0, 1);
}