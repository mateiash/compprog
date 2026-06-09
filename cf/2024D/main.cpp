#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define INF LLONG_MAX

using namespace std;

typedef pair<ll, ll> ip;

ll a[400'005];
ll b[400'005];
ll sp[400'005];

ll anses[400'005];

vector<vector<ip>> adj;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n + 1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sp[i] = sp[i - 1] + a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            if(i != 1) adj[i].push_back({i - 1, 0});
            if(b[i] > i) adj[i].push_back({b[i], a[i]});
        }

        set<ip> unvisited;
        unvisited.insert({0, 1});
        anses[1] = 0;
        for(int i = 2; i <= n; i++){
            unvisited.insert({INF, i});
            anses[i] = INF;
        }

        while(!unvisited.empty()) {
            ip el = *unvisited.begin();
            if(el.first == INF) break;
            unvisited.erase(unvisited.begin());

            for(ip link : adj[el.second]){
                if(el.first + link.second >= anses[link.first]) continue;
                unvisited.erase({anses[link.first], link.first});
                anses[link.first] = el.first + link.second;
                unvisited.insert({anses[link.first], link.first});
            }

        }

        ll best = 0;

        for(int i = 1; i <= n; i++){
            best = max(best, sp[i] - anses[i]);
            //cout << anses[i] << ' ';
        } cout << best;
        cout << '\n';

    }

    return 0;
}
