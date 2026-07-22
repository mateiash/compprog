#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

struct nod{
    ll mic;
    ll mare;
};
nod segtree[8'000'005];


struct opps{
    ll mic;
    ll mare;
};


opps lazy[8'000'005];

nod merge(nod a, nod b){
    return {
        min(a.mic, b.mic),
        max(a.mare, b.mare)
    };
}

opps combine(opps a, opps b){
    if(a.mare <= b.mic) return {b.mic, b.mic};
    if(b.mare <= a.mic) return {b.mare, b.mare};
    return {max(a.mic, b.mic), min(a.mare, b.mare)};
}

void pushdown(ll v, ll l, ll r){
    opps operatie = lazy[v];
    lazy[v] = {LLONG_MIN, LLONG_MAX};

    if(l != r){
        lazy[2*v] = combine(lazy[2*v], operatie);
        lazy[2*v + 1] = combine(lazy[2*v + 1], operatie);
    }

    if(segtree[v].mare <= operatie.mic)
        segtree[v] = {operatie.mic, operatie.mic};
    else if (operatie.mare <= segtree[v].mic)
        segtree[v] = {operatie.mare, operatie.mare};
    else
        segtree[v] = {
            max(segtree[v].mic, operatie.mic), 
            min(segtree[v].mare, operatie.mare)};
}

void update(ll v, ll l, ll r, ll ql, ll qr, opps operatie){
    pushdown(v, l, r);
    if(r < ql || qr < l) return;

    if(operatie.mic <= segtree[v].mic &&
        operatie.mare >= segtree[v].mare   
    ){
        return;
    }
    if(ql <= l && r <= qr){
        lazy[v] = operatie;
        pushdown(v, l, r);
        return;
    }

    int mid = (l + r)/2;
    update(2*v, l, mid, ql, qr, operatie);
    update(2*v + 1, mid + 1, r, ql, qr, operatie);
    segtree[v] = merge(segtree[2*v], segtree[2*v + 1]);
    //cout << l << ' ' << r << " updated\n";
}

ll qr = 0;
ll const QRESET = 0;
void query(int v, int l, int r, int pos){
    pushdown(v, l, r);
    if(pos < l || pos > r) return;
    if(l == r){
        qr = segtree[v].mare;
        return;
    }

    int mid = (l + r)/2;
    query(2*v, l, mid, pos);
    query(2*v + 1, mid + 1, r, pos);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int type; cin >> type;

        if(type == 1){
            int l, r, h; cin >> l >> r >> h;
            update(1, 1, n, l + 1, r + 1, {h, LLONG_MAX});
        } else {
            int l, r, h; cin >> l >> r >> h;
            update(1, 1, n, l + 1, r + 1, {LLONG_MIN, h});

        }
        /*
        for(int i = 1; i <= n; i++){
            qr = QRESET;
            query(1, 1, n, i);
            cout << qr << ' ';
        }
        cout << '\n';
        */
    }

    for(int i = 1; i <= n; i++){
        qr = QRESET;
        query(1, 1, n, i);
        cout << qr << '\n';
    }
    //cout << '\n';

    return 0;
}
