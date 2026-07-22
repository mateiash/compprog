#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("bvarcolaci.in");
ofstream fout("bvarcolaci.out");

struct node {
    int sum;
};

struct op {
    int add;
    int add2;
    bool reset;
};

node segtree[2'000'005];
op lazy[2'000'005];

node merge(node a, node b){
    return {a.sum + b.sum};
}

op combine(op a, op b){
    if(!a.reset && !b.reset) return {a.add + b.add, a.add2 + b.add2, 0};
    if(a.reset && !b.reset) return {a.add + b.add, a.add2 + b.add2,1};
    if(!a.reset && b.reset) return {b.add, b.add2, 1};
    if(a.reset && b.reset) return {b.add, b.add2, 1};
    return {42, 1};
}

void pushdown(int v, int l, int r){
    op o = lazy[v];
    lazy[v] = {0, 0, 0};

    if(l != r){
        lazy[2*v] = combine(lazy[2*v], o);
        op no = o;
        if(o.add != 0)
            no.add = o.add + (l + r)/2 + 1 - l;
        lazy[2*v + 1] = combine(lazy[2*v + 1], no);
    }
    if(o.reset) 
        segtree[v].sum = 0;
    if(o.add != 0)
        segtree[v].sum += (o.add - 1) * (r - l + 1) + (r - l + 1) * (r - l + 2) / 2;
    segtree[v].sum += o.add2 * (r - l + 1);
    
}

void update(int v, int l, int r, int ql, int qr){
    pushdown(v, l, r);
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        op o = {0, 0, 0};
        o.add = 1 + l - ql;
        lazy[v] = o;
        pushdown(v, l, r);
        return;
    }
    if(l == r) return;

    int mid = (l + r)/2;
    update(2*v, l, mid, ql, qr);
    update(2*v + 1, mid + 1, r, ql, qr);
    segtree[v] = merge(segtree[2*v], segtree[2*v + 1]);
}

void update2(int v, int l, int r, int ql, int qr, int val){
    pushdown(v, l, r);
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        op o = {0, 0, 0};
        o.add2 = val;
        lazy[v] = o;
        pushdown(v, l, r);
        return;
    }
    if(l == r) return;

    int mid = (l + r)/2;
    update2(2*v, l, mid, ql, qr, val);
    update2(2*v + 1, mid + 1, r, ql, qr, val);
    segtree[v] = merge(segtree[2*v], segtree[2*v + 1]);
}

ll q = 0;
const ll QR = 0;
void query(int v, int l, int r, int ql, int qr){
    pushdown(v, l, r);
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        q += segtree[v].sum;
        return;
    }
    if(l == r) return;
    int mid = (l + r)/2;
    query(2*v, l, mid, ql, qr);
    query(2*v + 1, mid + 1, r, ql, qr);
}

const ll STADD = 250'001;
void reset(){
    lazy[1] = {0, 0, 1};
    pushdown(1, -250'000 + STADD, 250'000 + STADD);
}


int main(){
    int N;
    fin >> N;

    vector<vector<int>> v(N + 1);
    for(int i = 1; i <= N; i++){
        int el; fin >> el;
        v[el].push_back(i);
    }
    //cout << "dafea" << endl;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        reset();
        int last = 0;
        int lastval = -1; // like cea de dinainte
        v[i].push_back(N + 1);
        ll lans = 0;
        //cout << i << ":\n";
        for(auto el : v[i]){
            int start = lastval + 1;
            int stop = start - (el - last - 1);
            //cout << el << " on " << start << ' ' << stop << '\n';

            q = QR;
                query(1, -250'000+STADD, 250'000 + STADD, stop - 1 + STADD, start - 1 + STADD);
            lans += q;

            update(1, -250'000 + STADD, 250'000 + STADD, stop + STADD, start + STADD);
            update2(1, -250'000 + STADD, 250'000 + STADD, start + 1 + STADD, 250'000 + STADD, start - stop + 1);

            lastval = stop;
            last = el;
        }
        /*
        for(int i = -6; i <= 6; i++){
            q = QR;
            query(1, -250'000+STADD, 250'000 + STADD, i + STADD, i + STADD);
            cout << "(" << i << ")";
            cout << q << ' ';
        } cout << '\n';
        cout << lans << "\n\n";
        */
        ans += lans;
    }

    fout << ans << '\n';

    return 0;
}