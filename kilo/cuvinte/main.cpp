#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define ll long long

#define MOD 1'000'000'007

struct nod{
    nod* parinte;
    nod* fii[26];
    bool kindaleaf;
};

nod radacina;

void insert(nod* v, string& s, int ind){
    if(ind == s.size() - 1 || v -> kindaleaf) {
        v->kindaleaf = true;
        return;
    }
    char c = s[ind + 1];
    
    if(v->fii[c - 'a'] == nullptr) {
        nod* nv = new nod();
        nv->parinte = v;
        v->fii[c - 'a'] = nv;
    }

    insert(v->fii[c - 'a'], s, ind + 1);
}

ll bustbranch[300'005];
ll bustleaf[300'005];

string prefix;

void dfs(nod* v){
    if(v->kindaleaf) {
        bustleaf[prefix.size()]++;
        //cout << prefix << '\n';
        if(!prefix.empty())
            prefix.pop_back();
        return;
    }
    else bustbranch[prefix.size()]++;
    
    for(int i = 0; i < 26; i++){
        if(v->fii[i] == nullptr) continue;

        prefix.push_back(i + 'a');
        dfs(v->fii[i]);
    }
    if(!prefix.empty())
        prefix.pop_back();
    
}
ll x[300'005] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        //reverse(s.begin(), s.end());
        insert(&radacina, s, -1);
    }

    for(int i = 1; i <= M; i++){
        ll el; cin >> el;
        x[el]++;
    }
    
    ll ans = 1;
    dfs(&radacina);

    ll opt = K;
    ll stbust = 0;
    for(int i = 1; i <= 300'000; i++){
        ll free = (3LL * MOD + opt - stbust - bustbranch[i] - bustleaf[i]) % MOD;

        for(int j = 0; j < x[i]; j++){
            ans *= free;
            ans %= MOD;
            free--;
        }
        
        stbust += bustleaf[i] + x[i];
        stbust %= MOD;
        stbust *= K;
        stbust %= MOD;
        opt *= K;
        opt %= MOD;
    }    

    cout << ans << '\n';
    //fout << ans << '\n';
    return 0;
}