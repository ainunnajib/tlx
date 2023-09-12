#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n, p; cin >> n >> p;
    int t[p], w[p];
    for(int i=0;i<p;i++) cin >> t[i] >> w[i];

    //Subtask 10: ultimate solution
    // like subtask 9 but cannot use array
    // use map, record sparsely, binary search

    map<int, int> tv1, tv2;

    vector<int> w1, w2;
    for(int i=0;i<p;i++){
        if(t[i] == 1)
            w1.push_back(w[i]);
        else
            w2.push_back(w[i]);
    }
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    int nyala = 0;
    for(int j = w1.size()-1; j >= 0; j--){
        nyala = 1 - nyala;
        tv1[w1[j]] = nyala;
    }
    tv1[n+1] = 0;

    nyala = 0;
    for(int j = 0; j < w2.size(); j++){
        nyala = 1 - nyala;
        tv2[-w2[j]] = nyala;
    }
    tv2[0] = 0;

    int q; cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        cout << (tv1.lower_bound(max(x,y))->second + tv2.lower_bound(-min(x,y))->second)%2 << endl;
    }
}