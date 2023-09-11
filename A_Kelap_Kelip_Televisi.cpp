#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 3: n, p, q <= 200
    // we can do brute force O(n^2 * p)
    // maximum = 200^2 * 200 = 8,000,000

    int tv[n][n];
    memset(tv,0,sizeof(tv)); //tv mati semua di awal

    for(int i=0;i<p;i++){
        if(t[i] == 1){
            for(int x=0;x<w[i];x++){
                for(int y=0;y<w[i];y++){
                    tv[x][y] = 1 - tv[x][y];
                }
            }
        } else {
            for(int x=w[i]-1;x<n;x++){
                for(int y=w[i]-1;y<n;y++){
                    tv[x][y] = 1 - tv[x][y];
                }
            }
        }
    }

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        cout << tv[x-1][y-1] << endl;
    }
}