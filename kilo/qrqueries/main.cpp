#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ifstream fin("orqueries.in");
ofstream fout("orqueries.out");

struct frac{
    int numa;
    int numi;
};


bool operator<(const frac& a, const frac& b){
    if(1LL * a.numa * b.numi < 1LL * b.numa * a.numi){
        return 1;
    }
    return 0;
}

bool operator==(const frac& a, const frac& b){
    if(1LL * a.numa * b.numi == 1LL * b.numa * a.numi){
        return 1;
    }
    return 0;
}

set<frac> axa[32];

int L;

int getchecked(frac l, frac r){
    int rez = 0;
    for(int i = 0; i < 32; i++){
        auto lowb = axa[i].lower_bound(l);
        if(lowb == axa[i].end()){
            continue;
        }

        frac sug = *lowb;
        
        if(sug < r || sug == r){
            rez += 1 << i;
        }
    }

    return rez;

}

void addpoint(frac pos, int c){
    int bit = 0;
    while(c){
        if(c & 1){
            axa[bit].insert(pos);
        }
        c >>= 1;
        bit++;
    }
}

int main(){

    int Q; fin >> Q;

    for(int i = 1; i <= Q; i++){
        int c; fin >> c;
        if(c == 1){
            int a, b, c;
            fin >> a >> b >> c;
            a ^= L;
            b ^= L;
            addpoint({a, b}, c);
            //cout << a << ' ' << b << " add\n";
            //cout.flush();
        }
        if(c == 2){
            int a1, b1, a2, b2;
            fin >> a1 >> b1 >> a2 >> b2;

            a1 ^= L;
            b1 ^= L;
            a2 ^= L;
            b2 ^= L;

            frac f1 = {a1, b1};
            frac f2 = {a2, b2};

            if(f2 < f1){
                swap(f1, f2);
            }

            //cout << f1.numa << ' ' << f1.numi << ' ';
            //cout << f2.numa << ' ' << f2.numi << '\n';

            int rez = getchecked(f1, f2);

            L = rez;
            fout << L << '\n';
        }
    }


    return 0;
}