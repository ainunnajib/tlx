#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 9: n <= 200,000
    // like subtask 8 but separate the t=1 & t=2

    int tv1[n+1], tv2[n+1];

    vector<int> w1, w2;
    for(int i=0;i<p;i++){
        if(t[i] == 1)
            w1.push_back(w[i]);
        else
            w2.push_back(w[i]);
    }
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    int j = w1.size()-1, nyala = 0;
    for(int i=n;i>0;i--){
        while(j >= 0 && i == w1[j]){
            nyala = 1 - nyala;
            j--;
        }
        tv1[i] = nyala;
    }

    j = 0, nyala = 0;
    for(int i=1;i<=n;i++){
        while(j < w2.size() && i == w2[j]){
            nyala = 1 - nyala;
            j++;
        }
        tv2[i] = nyala;
    }

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        cout << (tv1[max(x,y)] + tv2[min(x,y)])%2 << endl;
    }
}