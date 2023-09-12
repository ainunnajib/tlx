#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 5: hanya ada 1 perubahan

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        
        if(t[0] == 1){
            if( x <= w[0] && y <= w[0] ) cout << 1 << endl;
            else cout << 0 << endl;
        } else {
            if( x >= w[0] && y >= w[0] ) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}