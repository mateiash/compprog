#include <bits/stdc++.h>
#include <climits>

#define ll long long
#define ull unsigned long long

using namespace std;

ll A[200'005];
ll segtree[400'005];

void build(int nod, int l, int r){
    if(l == r){
        segtree[nod] = A[l];
        //cout << nod << " hit\n";
        return;
    }
    int mid = (l + r)/2;
    build(nod*2, l, mid);
    build(nod*2 + 1, mid + 1, r);
    segtree[nod] = min(segtree[2*nod], segtree[2*nod + 1]);
}

void update(int nod, int l, int r, int pos, int val){
    if(l == r){
        segtree[nod] = val; 
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid)
        update(2*nod, l, mid, pos, val);
    if (pos > mid)
        update(2*nod+1, mid+1, r, pos, val);
    segtree[nod] = min(segtree[2*nod], segtree[2*nod+1]);
}

ll sol = 0;

void query(int nod, int st, int dr, int a, int b) {
    if (a<=st && dr<=b) {
        sol = min(sol, segtree[nod]);
        return;
    }
    int mid = (st+dr)/2;
    if (a <= mid)
        query(2*nod, st, mid, a, b);
    if (b >= mid+1)
        query(2*nod+1, mid+1, dr, a, b);
    
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    build(1, 1, n);
    /*
    for(int i = 1; i <= 16; i++){
                cout << i << ": " << segtree[i] << '\n';
            } cout << '\n';
    */
    for(int i = 1; i <= m; i++){
        int ops; cin >> ops;
        if(ops == 1){
            int ind, val; cin >> ind >> val;
            ind++;
            update(1, 1, n, ind, val);
            /*
            cout << '\n';
            for(int i = 1; i <= 16; i++){
                cout << i << ": " << segtree[i] << '\n';
            } cout << '\n';
            */
            continue;
        }
        int a, b; cin >> a >> b;
        a++; 
        sol = LLONG_MAX;
        query(1, 1, n, a, b);
        cout << sol << '\n';
    }

    return 0;
}
