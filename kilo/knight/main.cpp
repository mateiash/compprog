#include <bits/stdc++.h>

#define ll long long
#define MOD 1'000'000'007

using namespace std;

ifstream fin("knight.in");
ofstream fout("knight.out");

typedef pair<ll, ll> ip;

int parinti[200'005];
vector<vector<int>> copii;

int timestamp = 0;

ip prefixcopac[200'005];
ip ts[200'005];

int nivel[200'005];

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

void dfsp(int node){
    timestamp++;
    ts[node].first = timestamp;  
    
    ip pfparinte = prefixcopac[parinti[node]];
    ip pfpropriu;
    
    ll own = copii[parinti[node]].size() - 1;
    if(own != 0) pfpropriu = { pfparinte.first * own % MOD, pfparinte.second };
    else pfpropriu = { pfparinte.first, pfparinte.second + 1 };

    prefixcopac[node] = pfpropriu;

    for(auto copil : copii[node]){
        dfsp(copil);
    }

    ts[node].second = timestamp;

}

int main(){
    int C; int N;
    fin >> C >> N;

    copii.resize(N + 5);

    for(int i = 2; i <= N; i++){
        int p; fin >> p;
        parinti[i] = p;
        copii[p].push_back(i);
        nivel[i] = nivel[p] + 1;
    }
    
    if(C == 1){
        ll ans = 0;
        for(int i = 1; i <= N; i++){
            if(copii[i].size() == 1){
                ans++;
            }
        }

        fout << ans << '\n';
        return 0;
    }
    copii[0].push_back(1);
    prefixcopac[0] = {1, 0};
    // dfs pt prefixe
    dfsp(1);
    /*
    for(int i = 1; i <= N; i++){
        cout << i << ":\n";
        cout << prefixcopac[i].first << ' ' << prefixcopac[i].second << '\n';
    }

    cout << '\n';
    for(int i = 1; i <= N; i++){
        cout << i << ":\n";
        cout << ts[i].first << ' ' << ts[i].second << '\n';
    }
    */
    if(C == 2){
        int Q; fin >> Q;

        for(int q = 1; q <= Q; q++){
            int a, b; fin >> a >> b;
            if(nivel[a] == nivel[b] || nivel[b] > nivel[a]) {
                fout << "0\n";
                continue;
            }

            int pb = parinti[b];
            int pa = parinti[a];
            int nrzerouri;
            if(ts[a].first >= ts[pb].first && ts[a].second <= ts[pb].second){
                // ok
            } else {
                fout << "0\n";
                goto fini;
            }

            if(ts[a].first >= ts[b].first && ts[a].second <= ts[b].second){
                fout << "0\n";
                goto fini;
            }

            nrzerouri = prefixcopac[pa].second - prefixcopac[pb].second;
            if(nrzerouri > 0) {
                fout << "0\n";
                goto fini;
            }
            
            fout << "1\n";
            
            fini:
            continue;
        }
        return 0;
    
    }

    int Q; fin >> Q;

    for(int q = 1; q <= Q; q++){
        int a, b; fin >> a >> b;
        if(nivel[a] == nivel[b] || nivel[b] > nivel[a]) {
            fout << "0\n";
            continue;
        }

        int pb = parinti[b];
        int pa = parinti[a];
        int nrzerouri;
        if(ts[a].first >= ts[pb].first && ts[a].second <= ts[pb].second){
            // ok
        } else {
            fout << "0\n";
            continue;
        }

        if(ts[a].first >= ts[b].first && ts[a].second <= ts[b].second){
            fout << "0\n";
            continue;
        }

        nrzerouri = prefixcopac[pa].second - prefixcopac[pb].second;
        if(nrzerouri > 0) {
            fout << "0\n";
            continue;
        }
        fout << prefixcopac[pa].first * fastexp(prefixcopac[b].first, MOD - 2) % MOD << '\n';

    
    }

    return 0;
}