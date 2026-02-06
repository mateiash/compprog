#include <bits/stdc++.h>

#define ll long long

#define MOD 20'173'333

#define inp fin
#define outp fout

using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r = (r * a) % MOD;
        }
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

ll factmod[100'005];
ll invfactmod[100'005];

ll dp[100'005];

ll accdp(int ind){
    if(ind >= 0){
        return dp[ind];
    }
    return 0;
}

int main(){
    ll P, N;
    inp >> P >> N;

    factmod[0] = 1;
    for(ll i = 1; i < 100'005; i++){
        factmod[i] = i*factmod[i-1] % MOD;
    }

    invfactmod[100'004] = fastexp(factmod[100'004], MOD - 2);
    for(ll i = 100'003; i >= 0; i--){
        invfactmod[i] = (invfactmod[i + 1]) * (i + 1) % MOD;
    }

    // btars and sars 
    if(P == 1){
        int U;
        inp >> U;
        ll boxnowbox = N - U;
        ll barnowbar = U - 1;
        ll rez = factmod[boxnowbox + barnowbar] * invfactmod[boxnowbox] % MOD * invfactmod[barnowbar] % MOD;

        outp << rez << '\n';
        return 0;
    }
    
    int R;
    inp >> R;
    dp[0] = 1;
    ll rez = 0;
    for(int i = 1; i <= N; i++){
        rez = (dp[i - 1] + rez) % MOD + MOD - accdp(i - R - 1);
        rez %= MOD;
        dp[i] = rez;
        //outp << dp[i] << ' ';
    }//outp << '\n';

    outp << dp[N];

    return 0;
}