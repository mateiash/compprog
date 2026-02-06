#include <bits/stdc++.h>

#define MOD 1'000'000'009

#define ll long long

using namespace std;

ll factmod[100'005];
ll invfactmod[100'005];

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r *= a;
            r %= MOD;
        }
        a*=a;
        a %= MOD;

        e >>= 1;
        
    }
    return r;
}

ifstream fin("fotbal.in");
ofstream fout("fotbal.out");

struct schimbare{
    int vdr;
    int vst;

    int pdr;
    int pst;
};

map<int, schimbare> schimbari;

ll accessinv(int n){
    if(n >= 0){
        return invfactmod[n];
    } else {
        return 0;
    }
}

ll combi(ll n, ll k){
    return factmod[n] * accessinv(n - k) % MOD * accessinv(k) % MOD;
}

int main(){
    
    factmod[0] = 1;
    for(ll i = 1; i < 100'005; i++){
        factmod[i] = factmod[i - 1] * i;
        factmod[i] %= MOD;
    }

    invfactmod[100'004] = fastexp(factmod[100'004], MOD - 2);
    for(ll i = 100'003; i >= 0; i--){
        invfactmod[i] = invfactmod[i + 1] * (i + 1) % MOD;
    }

    int N, K;
    fin >> N >> K;

    for(int i = 0; i < N; i++) {
        int v, p, tip;
        fin >> v >> p >> tip;
        if(tip == 0){
            // stangaci
            schimbari[v].vst++;
            schimbari[p].pst++;
        } else {
            // dreptaci
            schimbari[v].vdr++;
            schimbari[p].pdr++;
        }

    }

    int currst = 0;
    int currdr = 0;

    ll totaltally = 0;
    ll drtally = 0;
    ll sttally = 0;
    for(auto kv : schimbari){
        schimbare s = kv.second;
        // adaugiri
        for(int i = 0; i < s.vst; i++){
            currst++;
            // calc combinatii
            sttally +=
                combi(currst - 1, K - 1);
            sttally %= MOD;
            totaltally +=
                combi(currdr + currst - 1, K - 1);
            totaltally %= MOD;
        }

        for(int i = 0; i < s.vdr; i++){
            currdr++;
            // calc combinatii

            drtally +=
                combi(currdr - 1, K - 1);
            drtally %= MOD;    
            totaltally +=
                combi(currdr + currst - 1, K - 1);
            totaltally %= MOD;
            
        }
        // cum faci cu stangacii si dreptacii????????
        // plecari

        //fout << kv.first << ": " << currst << ' ' << currdr << '\n';
        currst -= s.pst;
        currdr -= s.pdr;

    }

    fout << (2*MOD + totaltally - sttally - drtally) % MOD << '\n';


    return 0;
}