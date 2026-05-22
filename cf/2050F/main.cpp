#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[200'005];
ll segtree[800'010];

void build(int node, int l, int r){
    if(l == r){
        segtree[node] = abs(a[l] - a[l + 1]);
        return;
    }

    int mid = (l + r)/2;
    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    segtree[node] = gcd(
        segtree[2*node], segtree[2*node + 1]
    );
}

ll qres = 0;
void query(int node, int l, int r, int ql, int qr){
//    cout << node << " node" << endl;
if(l > r) return;
    if(ql <= l && r <= qr){        
        qres = gcd(qres, segtree[node]);
        return;
    }

    if(r < ql || qr < l) return;
    int mid = (l + r)/2;
    query(2*node, l, mid, ql, qr);
    query(2*node + 1, mid + 1, r, ql, qr);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n, q;
        cin >> n >> q;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        if(n > 1) build(1, 1, n - 1); 

        for(int i = 1; i <= q; i++){
            int l, r;
            cin >> l >> r;

            if(l == r){
                cout << "0 ";
                continue;
            }
            //cout << "hello" << endl;
            qres = 0;
            query(1, 1, n - 1, l, r - 1);
            cout << qres << ' ';

        }

        cout << '\n';
    }

    return 0;
}
