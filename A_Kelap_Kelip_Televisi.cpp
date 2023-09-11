#include <iostream>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    int q; cin >> q;
    while(q--){
        // Subtask 2: flip everything every time
        // odd times --> all on
        // even times --> all off

        cout << p%2 << endl;
    }
}