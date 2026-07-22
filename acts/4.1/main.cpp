#include <bits/stdc++.h>
#include <climits>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[100'005];
ll segtree[400'005];

const ll nope = LLONG_MAX;
struct op{
    ll set;
    ll add;
};
op propagation[400'005];


ll merge(ll a, ll b){
    return a + b;
}

op combine(op a, op b){
    if(b.set!=nope) return b;
    return {a.set, a.add + b.add};
}


void build(int v, int l, int r){
    propagation[v] = {nope, 0};
    if(l == r){
        segtree[v] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);

    segtree[v] = merge(
        segtree[2*v], segtree[2*v + 1]
    );
}

void pushdown(int v, int l, int r){
    op operation = propagation[v];
    if(operation.set != nope){
        segtree[v] = (r - l + 1) * operation.set;
    }
    segtree[v] += (r - l + 1) * operation.add;
    propagation[v] = {nope, 0};
    if(l == r) return;

    propagation[2*v] = combine(
        propagation[2*v], operation
    );
    propagation[2*v + 1] = combine(
        propagation[2*v + 1], operation
    );
}

void update(int v, int l, int r, int ql, int qr, op operation){
    pushdown(v, l, r);
    if(qr < l || r < ql) return;

    if(ql <= l && r <= qr){
        propagation[v] = operation;
        pushdown(v, l, r);
        return;
    }
    if(l == r) return;
    int mid = (l + r)/2;
    update(2*v, l, mid, ql, qr, operation);
    update(2*v + 1, mid + 1, r, ql, qr, operation);
    segtree[v] =
        merge(segtree[2*v], segtree[2*v + 1] );
}

ll queryresult = 0;
const ll QUERYRESET = 0;
void query(int v, int l, int r, int ql, int qr){
    pushdown(v, l, r);
    if(qr < l || r < ql) return;

    if(ql <= l && r <= qr){
        queryresult += segtree[v];
        return;
    }
    if(l == r) return;

    int mid = (l + r)/2;
    query(2*v,      l, mid, ql, qr);
    query(2* v + 1, mid + 1, r, ql, qr);
}

int main(){
    int n, m;

    cin >> n >> m;

    // for(int i = 1; i <= n; i++){
    //     cin >> a[i];
    // }
    build(1, 1, n);
    
    for(int i = 1; i <= m; i++){
        int type; cin >> type;

        if(type == 1) {
            int l, r, val;
            cin >> l >> r >> val;

            update(1, 1, n, l + 1, r, {val, 0});
        } else if(type == 2) {
            int l, r, val;
            cin >> l >> r >> val;

            update(1, 1, n, l + 1, r, {nope, val});
        } else {
            int l, r; cin >> l >> r;
            queryresult = QUERYRESET;

            query(1, 1, n, l + 1, r);
            cout << queryresult << '\n';
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
