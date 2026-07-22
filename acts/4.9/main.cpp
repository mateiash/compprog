#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<ll, ll> ip;

ll a[100'005];
ip segtree[400'005];

ip merge(ip a, ip b){
    return {a.first + b.first, 
        max(a.second, b.second)
    };
}

void build(int v, int l, int r){
    if(l == r){
        segtree[v] = {a[l], a[l]};
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    segtree[v] = merge(
        segtree[2*v],
        segtree[2*v + 1]
    );
}

void update_m(int v, int l, int r, int ql, int qr, ll val){
    if(r < ql || qr < l) return;

    if(segtree[v].second < val) return;
    if(l==r){
        segtree[v] = {segtree[v].first % val, segtree[v].first % val};
        return;
    }

    int mid = (l + r)/2;

    update_m(2*v, l, mid, ql, qr, val);
    update_m(2*v + 1, mid + 1, r, ql, qr, val);
    segtree[v] = merge(
        segtree[2*v], segtree[2*v + 1]
    );
}

void update_v(int v, int l, int r, int pos, ll val){
    if(pos < l || pos > r) return;

    if(l == r) {
        segtree[v] = {val, val};
        return;
    }
    int mid = (l + r)/2;
    update_v(2*v, l, mid, pos, val);
    update_v(2*v + 1, mid + 1, r, pos, val);
    segtree[v] = merge(
        segtree[2*v], segtree[2*v + 1]
    );
}

ll queryresult = 0;
const ll QUERYRESET = 0;
void query(int v, int l, int r, int ql, int qr){
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr){
        queryresult += segtree[v].first;
        return;
    }
    if(l == r) return;

    int mid = (l + r)/2;
    query(2 * v, l, mid, ql, qr);
    query(2 * v + 1, mid + 1, r, ql, qr);
}



int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int type; cin >> type;

        if(type == 1){
            ll l, r; cin >> l >> r;
            queryresult = QUERYRESET;
            query(1, 1, n, l , r);
            cout << queryresult << '\n';
            
        } else if(type == 2){
            ll l, r, x;
            cin >> l >> r >> x;
            update_m(1, 1, n, l, r, x);
            
        } else {
            ll pos, val; cin >> pos >> val;
            update_v(1, 1, n, pos, val);
        }
        /*
        cout << "op " << i << endl;
        for(int i = 1; i <= n; i++){
            queryresult = QUERYRESET;
            query(1, 1, n, i, i);
            cout << queryresult << ' ';
        }
        cout << endl << endl;
        */
        }

    return 0;
}
