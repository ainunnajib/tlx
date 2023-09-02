#include <iostream>
#include <cstring>
using namespace std;

int n;
int aman[200000]; 

int main(){
    cin >> n;
    for(int i = 0;i<n;i++) cin >> aman[i];

    int kena[n+1]; memset(kena, 0, sizeof(kena));
    // kena[y] berarti posisi kapal di y, looping hari ke hari 1-n

    // hari pertama dulu, hari = 0
    if(aman[0] != 1) kena[1] = 1;
    for(int posisi = 2; posisi <= n; posisi++) kena[posisi] = 1000000000;
    int kena_minimum = kena[1];

    // hari-hari berikutnya, berdasarkan hari sebelumnya
    for(int hari = 1; hari < n; hari++){
        // balik
        if(aman[hari] != 1) kena_minimum++;
        int kena_kalau_balik = kena_minimum;

        // mengalir saja
        for(int posisi = n; posisi > 1; posisi--){
            if(aman[hari] == posisi)
                kena[posisi] = kena[posisi-1];
            else
                kena[posisi] = kena[posisi-1] + 1;

            kena_minimum = min(kena_minimum, kena[posisi]);
        }

        // update kena[1]
        kena[1] = kena_kalau_balik;
    }

    int jawaban = 1000000000;
    for(int posisi = 1; posisi <= n; posisi++)
        jawaban = min(jawaban, kena[posisi]);
    
    cout << jawaban;
}