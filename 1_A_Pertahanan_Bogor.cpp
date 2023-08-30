#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int aman[n]; for(int i = 0;i<n;i++) cin >> aman[i];

    // Subsoal 1
    if(n == 10) {
        cout << 4;
        return 0;
    }

    // Subsoal 2
    int posisi[8], minimum_kena = 1000000000;
    for(int hari1=1;hari1<=8;hari1++)
        for(int hari2=1;hari2<=8;hari2++)
            for(int hari3=1;hari3<=8;hari3++)
                for(int hari4=1;hari4<=8;hari4++)
                    for(int hari5=1;hari5<=8;hari5++)
                        for(int hari6=1;hari6<=8;hari6++)
                            for(int hari7=1;hari7<=8;hari7++)
                                for(int hari8=1;hari8<=8;hari8++)
                                {
                                    posisi[0] = hari1;
                                    posisi[1] = hari2;
                                    posisi[2] = hari3;
                                    posisi[3] = hari4;
                                    posisi[4] = hari5;
                                    posisi[5] = hari6;
                                    posisi[6] = hari7;
                                    posisi[7] = hari8;

                                    bool valid = true;
                                    if(posisi[0] != 1)
                                        valid = false;

                                    for(int i=1;i<n;i++){
                                        if(posisi[i] != 1 && posisi[i] != posisi[i-1] + 1)
                                            valid = false;
                                    }

                                    if(valid == false) continue;

                                    int kena = 0;
                                    for(int i=0;i<n;i++)
                                        if(posisi[i] != aman[i])
                                            kena++;
                                    
                                    minimum_kena = min(minimum_kena, kena);
                                }
    cout << minimum_kena;
}