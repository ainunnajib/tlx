#include <iostream>
#include <cstring>
using namespace std;

// Subsoal 1, 2 & 3, N <= 17
int n;
int aman[200000]; 

int main(){
    cin >> n;
    for(int i = 0;i<n;i++) cin >> aman[i];

    // Subtask 6: N <= 200
    if(n <= 200){
        int kena[n][n+1]; memset(kena, 0, sizeof(kena));
        // kena[x][y] berarti hari ke-x posisi kapal di y

        // hari pertama dulu, hari = 0
        if(aman[0] == 1) kena[0][0] = 0;
        else kena[0][1] = 1;
        for(int posisi = 2; posisi <= n; posisi++) kena[0][posisi] = 1000000000;
        
        // hari-hari berikutnya, berdasarkan hari sebelumnya
        for(int hari = 1; hari < n; hari++){
            for(int posisi = 1; posisi <= n; posisi++) kena[hari][posisi] = 1000000000;

            for(int posisi = 1; posisi <= n; posisi++){
                for(int posisi_sebelumnya = 1; posisi_sebelumnya <= n; posisi_sebelumnya++){
                    if(posisi != posisi_sebelumnya + 1 && posisi != 1)
                        continue;

                    int kenasekarang = 0;
                    if(posisi != aman[hari]) kenasekarang = 1;

                    kena[hari][posisi] = min(kena[hari][posisi], kenasekarang + kena[hari-1][posisi_sebelumnya]);
                }
            }
        }

        int jawaban = 1000000000;
        for(int posisi = 1; posisi <= n; posisi++)
            jawaban = min(jawaban, kena[n-1][posisi]);
        
        cout << jawaban;

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