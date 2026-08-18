#include <climits>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

ifstream fin("lexicografic.in");
ofstream fout("lexicografic.out");

#define ll long long

ll a[250'005];

ll lsb(ll x) {
    return (x & (-x));
}

ll aib[250'005];

void update(int pos, int val){
    while(pos < 250'005){
        aib[pos] += val;
        pos += lsb(pos);
    }
}

ll query(int sum){
    int pos = 0;
    int last = 0;
    for(int step = 1 << 20; step >= 1; step >>= 1){
        if(pos + step >= 250'005) continue;
        if(last + aib[pos + step] < sum){
            last += aib[pos + step];
            pos += step;
        }
    }
    return pos;
}

ll sum(int pos){
    ll r = 0;
    while(pos > 0){
        r += aib[pos];
        pos -= lsb(pos);
    }
    return r;
}

ll segtree[1'000'005];
void build(ll v, ll l, ll r){
    if(l == r){
        segtree[v] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    segtree[v] = min(segtree[2*v], segtree[2*v + 1]);
}
 
void update(ll v, ll l, ll r, ll pos, ll val){
    if(pos < l || r < pos) return;
    if(l == r){
        segtree[v] = val;
        return;
    }
 
    int mid = (l + r)/2;
    update(2*v, l, mid, pos, val);
    update(2*v + 1, mid + 1, r, pos, val);
    segtree[v] = min(segtree[2*v], segtree[2*v + 1]);
 
}
 
const ll qreset = LLONG_MAX;
ll qans = qreset;
void query(ll v, ll l, ll r, ll ql, ll qr){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        qans = min(qans, segtree[v]);
        return;
    }
 
    int mid = (l + r)/2;
    query(2*v, l, mid, ql, qr);
    query(2*v + 1, mid + 1, r, ql, qr);
 
}



int main(){
    int t;
    fin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n, k;
        fin >> n >> k;

        for(int i = 1; i <= n; i++){
            fin >> a[i];
        }
        fill(aib + 1, aib + 250'005, 0);

        map<ll, vector<ll>> pos;
        for(int i = n; i >= 1; i--){
            pos[a[i]].push_back(i);
            update(i, 1);
        }

        build(1, 1, n);

        vector<ll> ans;
        while(k > 0 && ans.size() < n){
            qans = qreset;
            ll pointer = query(min(k + 2, 250'003LL));
            pointer = min(pointer, n);
            query(1, 1, n, 1, pointer);

            ans.push_back(qans);
            ll position = pos[qans].back(); pos[qans].pop_back();

            update(1, 1, n, position, LLONG_MAX);
            k -= sum(position) - 1;
            //cout << "pulled " << qans << " from " << position << "(" << sum(position) << ")" <<endl;
            //cout << k << " k now" << endl;
            update(position, -1);
        }
    
        for(auto el : ans){
            fout << el << ' ';
        }
        for(int i = 1; i <= n; i++){
            qans = qreset;
            query(1, 1, n, i, i);
            if(qans != LLONG_MAX){
                fout << qans << ' ';
            }
        } fout << "\n";
        

    }

    return 0;
}