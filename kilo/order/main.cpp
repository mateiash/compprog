#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("order.in");
ofstream fout("order.out");

int findfirstdigit(ll& pos){
    ll sum = ilogb(pos) + 1;

}

int main(){

    int Q; fin >> Q;

    for(int cer = 0; cer < Q; cer++){
        int type; fin >> type;
        if(type == 1) return 0;
        
        ll pos; fin >> pos;
        
        cout << sum << '\n';
    }

    return 0;
}