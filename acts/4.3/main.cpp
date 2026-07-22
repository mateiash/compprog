#include <bits/stdc++.h>
#include <climits>

#define ll long long
#define ull unsigned long long

using namespace std;

struct node {
    ll sum;
    ll max;
    ll maxcnt;
    ll secondmax;    
};

ll a[300'005];
node segtree[4*300'000 + 5];

ll lazy[4*300'000 + 5];


node merge(node a, node b){
    node n;
    n.sum = a.sum + b.sum;
    n.max = max(a.max, b.max);
    if(a.max > b.max){
        n.maxcnt = a.maxcnt;
        n.secondmax = max(a.secondmax, b.max);
    } else if (a.max < b.max){
        n.maxcnt = b.maxcnt;
        n.secondmax = max(a.max, b.secondmax);
    } else {
        n.maxcnt = a.maxcnt + b.maxcnt;
        n.secondmax = max(a.secondmax, b.secondmax);
    }

    return n;

}

void build(int v, int l, int r){
    lazy[v] = LLONG_MAX;
    if(l == r){
        segtree[v] = {a[l], a[l], 1, LLONG_MIN};
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);

    segtree[v] = merge(segtree[2*v], segtree[2*v + 1]);
}

void pushdown(int v, int l, int r){
    ll x = lazy[v]; lazy[v] = LLONG_MAX;
    if(l != r){
        lazy[2*v] = min(x, lazy[2*v]);
        lazy[2*v + 1] = min(x, lazy[2*v + 1]);
    }
    if(x >= segtree[v].max) return;

    segtree[v].sum -= 
        (segtree[v].max - x) * segtree[v].maxcnt;
    segtree[v].max = x;
}

void update(int v, int l, int r, int ql, int qr, ll q){
    pushdown(v, l, r);
    if(r < ql || qr < l || q >= segtree[v].max) return;
    if((ql <= l && r <= qr) && q > segtree[v].secondmax){
        lazy[v] = q;
        pushdown(v, l, r);
        return;
    }

    if(l == r){
        segtree[v] = {
            min(segtree[v].sum, q),
            min(segtree[v].sum, q)
        };
        return;
    }

    int mid = (l + r)/2;
    update(2*v, l, mid, ql, qr, q);
    update(2*v + 1, mid + 1, r, ql, qr, q);
    segtree[v] = merge(segtree[2*v], segtree[2*v + 1]);
}

ll q = 0;
const ll QR = 0;
void query(int v, int l, int r, int ql, int qr){
    pushdown(v, l, r);
    if(r < ql || qr < l) return;

    if(ql <= l && r <= qr){
        q += segtree[v].sum;
        return;
    }
    int mid = (l + r)/2;
    query(2*v, l, mid, ql, qr);
    query(2*v + 1, mid + 1, r, ql, qr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1 , n, l, r, x);
            continue;
        }

        int l, r;
        cin >> l >> r;
        q = QR;
        query(1, 1, n, l, r);
        cout << q << '\n';
    }

    return 0;
}
