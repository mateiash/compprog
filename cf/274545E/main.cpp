#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[100'005];
ll segtree[400'005];

ll propagation[400'005];

void build(ll node, ll l, ll r){
    if(l == r){
        segtree[node] = a[l];
        return;
    }
    ll mid = (l + r)/2;
    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    segtree[node] = segtree[2*node] + segtree[2*node + 1];
}

const ll QUERYRESET = 0;
ll queryresult = QUERYRESET;
void query(ll node, ll l, ll r, ll ql, ll qr){
    if(propagation[node]){
        segtree[node]+=(r - l + 1)*propagation[node];
        if(l != r){
            propagation[2*node] += propagation[node];
            propagation[2*node + 1] += propagation[node];
        }
        propagation[node] = 0;
    }
    if(ql <= l && r <= qr){
        queryresult += segtree[node];
        return;
    }
    ll mid = (l + r)/2;
    if(l > qr || r < ql) return;
    query(2*node, l, mid, ql, qr);
    query(2*node + 1, mid + 1, r, ql, qr);
}

void update(ll node, ll l, ll r, ll ql, ll qr, ll val){
    if(propagation[node]){
        segtree[node] += (r - l + 1)*propagation[node];
        if(l != r){
            propagation[2*node] += propagation[node];
            propagation[2*node + 1] += propagation[node];
        }
        propagation[node] = 0;
    }
    if(ql <= l && r <= qr){
        segtree[node] += (r - l + 1)*val;
        if(l != r){
            propagation[2*node] += val;
            propagation[2*node + 1] += val;
        }
        return;
    }
    ll mid = (l + r)/2;
    if(l > qr || r < ql) return;
    update(2*node, l, mid, ql, qr, val);
    update(2*node + 1, mid + 1, r, ql, qr, val);
    segtree[node] = segtree[2*node] + segtree[2*node + 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int ops; cin >> ops;
        if(ops == 2){
            ll q; cin >> q;
            queryresult=QUERYRESET;
            q++;
            query(1, 1, n, q, q);
            cout << queryresult << '\n';
            cout.flush();
            continue;
        }
        ll l, r, val;
        cin >> l >> r >> val;
        l++;
        update(1, 1, n, l, r, val);
        
    }

    return 0;
}
