#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int u[m], v[m];
    for(int i=0;i<m;i++)
        cin >> u[i] >> v[i];
    
    // Subtask 2: N <= 50, M <= 100
    int jawaban = 0;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
        {
            set<int> terhubung[n+1];
            // setiap semut terhubung kepada dirinya sendiri
            for(int semut=l;semut<=r;semut++)
                terhubung[semut].insert(semut);

            for(int i=0;i<m;i++){
                int a = u[i], b = v[i];
                // kalau tidak termasuk range, lanjut
                if(a < l || a > r || b < l || b > r)
                    continue;
                // a terhubung ke b
                terhubung[a].insert(b);
                terhubung[b].insert(a);
                // untuk semua yang terhubung ke a
                // kita hubungkan ke b
                for(auto x : terhubung[a]){
                    terhubung[b].insert(x);
                    terhubung[x].insert(b);
                }
                // untuk semua yang terhubung ke b
                // kita hubungkan ke a
                for(auto x : terhubung[b]){
                    terhubung[a].insert(x);
                    terhubung[x].insert(a);
                }
            }

            int kesepian = 0;
            for(int semut=l;semut<=r;semut++)
                if(terhubung[semut].size() < 3)
                    kesepian++;

            jawaban += kesepian;
        }
    
    cout << jawaban;
}