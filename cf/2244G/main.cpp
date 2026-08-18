#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

ll a[200'005];

ll segtree[800'005];
void build(ll v, ll l, ll r){
    segtree[v] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
}

void update(ll v, ll l, ll r, ll pos, ll val){
    if(pos < l || r < pos) return;
    if(l == r){
        segtree[v] = max(val, segtree[v]);
        return;
    }

    int mid = (l + r)/2;
    update(2*v, l, mid, pos, val);
    update(2*v + 1, mid + 1, r, pos, val);
    segtree[v] = max(segtree[2*v], segtree[2*v + 1]);

}

const ll qreset = 0;
ll qans = qreset;
void query(ll v, ll l, ll r, ll ql, ll qr){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        qans = max(qans, segtree[v]);
        return;
    }

    int mid = (l + r)/2;
    query(2*v, l, mid, ql, qr);
    query(2*v + 1, mid + 1, r, ql, qr);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a[i] = el;
        } 

        map<int, vector<int>> starts;
        vector<ll> anses(n + 1);
        for(int i = 1; i <= n; i++){
            anses[i] = a[i];
        }

        for(int i = 1; i <= n; i++){
            starts[i - a[i] - 1].push_back(i);
        }

        build(1, 0, n);
        for(int i = 1; i <= n; i++){
            update(1, 0, n, i + a[i], anses[i]);
            /*
            cout << i << " at\n";
            for(int i = 0; i <= 10; i++){
                qans = qreset;
                query(1, 0, n, i, i);
                cout << qans << ' ';
            }
            cout << '\n';
            */
            for(auto el : starts[i]){
                qans = qreset;
                query(1, 0, n, 0, el - 1);
                anses[el] =
                    max(anses[el], qans + a[el]);
            }
        }

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(anses[i], ans);
            //cout << anses[i] << ' ';
        } //cout << '\n';
        cout << ans << '\n';

    }

}