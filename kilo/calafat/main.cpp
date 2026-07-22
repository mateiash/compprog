#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ifstream fin("calafat.in");
ofstream fout("calafat.out");

int a[200'005];

map<int, int> lastseen;

ll aib[200'005];

ll lsb(ll x){
    return x & (-x);
}

void update(int pos, ll val){
    while(pos < 200'005){
        aib[pos] += val;
        pos += lsb(pos);
    }
}

ll query(int pos){
    ll r = 0;
    while(pos){
        r += aib[pos];
       pos -= lsb(pos);
    }
    return r;
}

ll ans[200'005];

int main(){
    int N, M;
    
    fin >> N >> M;

    for(int i = 1; i <= N; i++){
        fin >> a[i];
    }

    set<
        pair<pair<int, int>, int>> qs;
    
    for(int i = 1; i <= M; i++){
        int l, r; fin >> l >> r;
        qs.insert({{r, l}, i});
    }
    
    for(int i = 1; i <= N; i++){
        int el; el = a[i];

        if(lastseen[el] == 0){
            lastseen[el] = i;
            goto fini;
        }

        update(lastseen[el], i - lastseen[el]);
        lastseen[el] = i;

        fini:
        for(auto it = qs.lower_bound({{i, -1}, -1}); 
            it != qs.lower_bound({{i, 999999}, 999999}); it++){
            
            ans[it->second] = 
                query(i) - query(it->first.second - 1);
        }
    }

    for(int i = 1; i <= M; i++){
        fout << ans[i] << '\n';
    }

    //cout << '\n';

    return 0;
}
