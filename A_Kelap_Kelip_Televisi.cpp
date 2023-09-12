#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 6: ada 2 perubahan
    // di titik yang sama tapi satu t = 1, satu t = 2

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        
        if(x == w[0] && y == w[0])
            cout << 0 << endl;
        else if(x <= w[0] && y <= w[0])
            cout << 1 << endl;
        else if(x >= w[0] && y >= w[0])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}