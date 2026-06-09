/*
ID: david25
LANG: C++14
TASK: combo
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

int main(){
    set<int> res;
    
    int N;
    fin >> N;

    int a, b, c;
    fin >> a >> b >> c;

    for(int ia = -2; ia <= 2; ia++){
        for(int ib = -2; ib <= 2; ib++){
            for(int ic = -2; ic <= 2; ic++){
                int an = (N + a + ia) % N;
                int bn = (N + b + ib) % N;
                int cn = (N + c + ic) % N;

                res.insert(
                    (an << 16) + (bn << 8) + cn 
                );
            }
        }
    }

    fin >> a >> b >> c;

    for(int ia = -2; ia <= 2; ia++){
        for(int ib = -2; ib <= 2; ib++){
            for(int ic = -2; ic <= 2; ic++){
                int an = (N + a + ia) % N;
                int bn = (N + b + ib) % N;
                int cn = (N + c + ic) % N;

                res.insert(
                    (an << 16) + (bn << 8) + cn 
                );
            }
        }
    }

    fout << res.size() << '\n';


    return 0;
}