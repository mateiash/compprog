#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("dulciuri.in");
ofstream fout("dulciuri.out");

#define AIBSIZE 1'000'005

ll aibV[AIBSIZE];
ll aibH[AIBSIZE];

ll lsb(ll x){
    return x & (-x);
}

void upd(ll* aib, ll pos, ll val){
    for(; pos < AIBSIZE; pos += lsb(pos)){
        aib[pos] += val;
    }
}

ll query(ll* aib, ll pos){
    ll r = 0;
    while(pos){
        r += aib[pos];
        pos -= lsb(pos);
    }
    return r;
}

int main(){
    int Q; fin >> Q;

    for(int q = 0; q < Q; q++){
        int C; fin >> C;

        if(C == 1){
            int p, v;
            fin >> p >> v;
            p += 1;
            upd(aibV, p, v);
            continue;
        }
        if(C == 2){
            int p, v;
            fin >> p >> v;
            p += 1;
            upd(aibH, p, v);
            continue;
        }
        /*
        for(int i = 1; i < 10; i++){
            cout << aibV[i] << '\n';
        }
        */
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        
        x1++; y1++; /*x2++; y2++;*/

        double doneony = y2 - y1 + 1;
        double doneonx = x2 - x1 + 1;
        /*
        cout << "\n";
        cout << x1 << ' ' << y1 << '\n';
        cout << x2 << ' ' << y2 << '\n';
        */
        double sumony = query(aibH, y2) - query(aibH, y1 - 1);
        double sumonx = query(aibV, x2) - query(aibV, x1 - 1);

        if(y2 - y1 + 1 == 0) {
            doneony = 1;
            sumony = query(aibH, y1) - query(aibH, y1 - 1);
        }
        if(x2 - x1 + 1 == 0) {
            doneonx = 1;
            sumonx = query(aibV, x1) - query(aibV, x1 - 1);
        }

        double r = sumonx/doneonx + sumony/doneony;
        fout << setprecision(13) << r << '\n';        
    }

    return 0;
}