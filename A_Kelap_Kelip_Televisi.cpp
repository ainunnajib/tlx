#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 7: n <= 200,000, T always 1
    // selalu pojok kiri atas --> radial ke kanan bawah
    // hati-hati titik yang sama bisa diupdate berkali-kali

    int tv[n+1];
    sort(w, w+p);
    int j = p-1, nyala = 0;
    for(int i=n;i>0;i--){
        while(i == w[j]){
            nyala = 1 - nyala;
            j--;
        }
        tv[i] = nyala;
    }

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        cout << tv[max(x, y)] << endl;
    }
}