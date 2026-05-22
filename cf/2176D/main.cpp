#include <bits/stdc++.h>

using namespace std;

#define MOD 998'244'353
#define ll long long

vector<vector<ll>> to;
vector<vector<ll>> from;

vector<set<ll>> possible;

ll a[200'005];

vector<map<ll, ll>> ans;

vector<vector<ll>> daglinks;
vector<ll> dagcnts;
vector<ll> freedagnodes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        daglinks.clear();
        dagcnts.clear();
        freedagnodes.clear();

        to.clear();
        from.clear();
        possible.clear();

        ans.clear();

        ans.resize(n + 1);
        dagcnts.resize(n + 1);
        daglinks.resize(n + 1);

        to.resize(n + 1);
        from.resize(n + 1);

        possible.resize(n + 1);

        for(int i = 1; i <= m; i++){
            int v, u;
            cin >> v >> u;

            possible[u].insert(a[v] + a[u]);
            to[u].push_back(v);
            from[v].push_back(u);

            ans[u][a[v]]++;
        }

        // constreauaiestea un daga=
        for(int i = 1; i <= n; i++){
            for(auto link : to[i]){
                ll should = a[i];
                if(possible[link].count(should)){
                    daglinks[link].push_back(i);
                    dagcnts[i]++;
                    //cout << link << ' ' << i << "found\n";
                }
            }
        }

        // sortaeaasaza atioikikgicu
        for(int i = 1; i <= n; i++){
            if(dagcnts[i]) continue;
            freedagnodes.push_back(i);
        }

        for(int i = 0; i < freedagnodes.size(); i++){
            int node = freedagnodes[i];
            for(auto link : daglinks[node]){
                ans[link][a[node]] += ans[node][a[link] - a[node]];
                ans[link][a[node]] %= MOD;
                dagcnts[link]--;
                if(dagcnts[link] <= 0) freedagnodes.push_back(link);
            }
        }

        ll spercaebine = 0;
        for(int i = 1; i <= n; i++){
            for(auto el : ans[i]){
            spercaebine += el.second;
            spercaebine %= MOD;}
        } cout << "\n" << spercaebine << "\n";

    }

    return 0;
}