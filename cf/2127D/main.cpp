#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 1'000'000'007

using namespace std;

int root;
int lastleaf;
int bad;

vector<vector<int>> adj;
vector<bool> isleaf;

ll factmod[200'005];

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r = r * a % MOD;
        }

        a = a * a % MOD;

        e >>= 1;
    }

    return r;
}

int main(){
    int t;
    cin >> t;

    factmod[0] = 1;
    for(ll i = 1; i <= 200'004; i++){
        factmod[i] = factmod[i - 1] * i % MOD;
    }

    for(int cer = 0; cer < t; cer++){
        int n, m;
        cin >> n >> m;

        adj.clear();
        adj.resize(n + 1);
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(m != n - 1){
            cout << "0\n";
            continue;
        }
        if(n == 2){
            cout << "2\n";
            continue;
        }

        isleaf.clear();
        isleaf.resize(n + 1);
        for(int i = 1; i <= n; i++){
            if(adj[i].size() == 1){
                isleaf[i] = 1;
            }
        }

        vector<int> leavescnt(n + 1);
        ll base = 1;
        for(int i = 1; i <= n; i++){
            int leaves = 0;
            for(auto link : adj[i]){
                leaves += isleaf[link];
            }
            if(adj[i].size() - leaves > 2){
                base = 0;
            }
            leavescnt[i] = leaves;
            base *= factmod[leaves];
            base %= MOD;
        }
        //cout << "base: " << base << '\n';
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(adj[i].size() - leavescnt[i] < 2 && !isleaf[i]){ // gng we found him
                ans += base;
                ans %= MOD;
                
                ll prov = base;
                
                prov *= fastexp(factmod[leavescnt[i]], MOD - 2);
                prov %= MOD;
                prov *= factmod[leavescnt[i] - 1];
                prov %= MOD;
                prov *= leavescnt[i];
                prov %= MOD;

                //prov *= leaves;
                prov %= MOD;

                ans += prov;
                ans %= MOD;
                //cout << i << ": " << prov << '\n';
            }
        }
        cout << ans << "\n";

    }

    return 0;
}
