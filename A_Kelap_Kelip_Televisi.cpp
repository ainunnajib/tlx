#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 4: n, p, q <= 2000
    // observe that we can separate T = 1 vs T = 2
    // O(n*p) solution
    // treat T = 1 & T = 2 separately
    // take the diagonal for each
    // for each Q, 
    //   check max(x, y) in diagonal 1
    //   check min(x, y) diagonal 2

    int tv1[n], tv2[n];
    memset(tv1,0,sizeof(tv1)); //tv mati semua di awal
    memset(tv2,0,sizeof(tv2)); //tv mati semua di awal

    for(int i=0;i<p;i++){
        if(t[i] == 1){
            for(int x=0;x<w[i];x++){
                tv1[x] = 1 - tv1[x];
            }
        } else {
            for(int x=w[i]-1;x<n;x++){
                tv2[x] = 1 - tv2[x];
            }
        }
    }

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        x--; y--;
        cout << (tv1[max(x, y)] + tv2[min(x, y)])%2 << endl;
    }
}