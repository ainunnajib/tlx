#include <iostream>
#include <climits>
using namespace std;

int main(){
    int maxgap = 0;
    int cur, prev, x;
    bool up;
    
    cin >> prev;
    cin >> cur;
    while(prev==cur && cin >> cur);
    if(cur>prev) {
        up = true;
        maxgap = cur - prev;
    } else if(cur<prev) {
        up = false;
        maxgap = prev - cur;
    }

    while(cin >> x){
        if(cur==x) continue;
        if((up && x<cur) || (!up && x>cur)){
            up = !up;
            prev = cur;
        }
        cur = x;
        maxgap = max(maxgap, abs(cur-prev));
    }

    cout << maxgap;
}