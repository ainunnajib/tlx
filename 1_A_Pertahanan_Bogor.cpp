#include <iostream>
using namespace std;

// Subsoal 1, 2 & 3, N <= 17
int n;
int aman[200000]; 

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

    if(n <= 17){
        cout << kena_berapa_kali(0, 1);
        return 0;
    }

    // Subtask 4: posisi aman sama setiap hari, selalu di titik yang sama
    bool semua_sama = true;
    for(int i = 1;i<n;i++){
        if(aman[i] != aman[0]){
            semua_sama = false;
            break;
        }
    }
    if(semua_sama){
        int posisi_aman = aman[0];
        cout << n - n/posisi_aman;
        return 0;
    }
    
    // Subtask 5: posisi aman hanya ada 2 macam yaitu 1 atau 2
    // kalau posisi aman berikutnya = 1, balik aja
    // kalau posisi aman berikutnya = 2, dan sebelumnya balik, mengalir aja
    // kalau posisi aman 2 masih muncul berturutan setelah mengalir, dibagi dua saja
    int kena = 0;
    if(aman[0] != 1) kena++;
    int dua_berturut = 0;
    for(int i=1;i<n;i++){
        if(aman[i] == 2) dua_berturut++;
        else {
            kena += dua_berturut/2;
            dua_berturut = 0;
        }
    }
    kena += dua_berturut/2;

    cout << kena;
}