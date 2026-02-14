#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

// first is like usual tge second is like halves ig
pair<int, int> anly(int n){
    int cp = n;
    int nrbits = 0;
    int nrtotal = -1;

    while(cp){
        nrtotal++;
        nrbits += cp & 1;
        cp >>= 1;
    }
    
    if(nrbits > 2){
        return {nrtotal + 1 , 0};
    }

    if(nrbits == 2){
        if(n & 1){
            return {nrtotal , 1};
        } else {
            return {nrtotal + 1 , 0};
        }
    }
    
    return {nrtotal, 0};


}

//ofstream fout("debug.out");

int sp[300'005];
int sphalf[300'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        int q; cin >> q;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            auto res =  anly(el);
            sp[i] = sp[i - 1] + res.first;
            sphalf[i] = sphalf[i - 1] + res.second;
        }

        for(int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;

            cout << (sp[y] - sp[x-1]) + 
                (sphalf[y] - sphalf[x-1])/2 << '\n';
        }

        cout << '\n';
    }

    return 0;
}
