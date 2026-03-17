#include <bits/stdc++.h>

#define ll long long

#define MOD 1'000'000'009

using namespace std;

ifstream fin("matrice.in");
ofstream fout("matrice.out");

ll sum(ll start, ll step, ll count){
    return (
        start * count % MOD + 
        (count) * (count - 1) % MOD * 500000005 % MOD * step % MOD
    ) % MOD;
}

int main(){

    // mat[i][j] = a + (M - 1)x + (N - 1)y + (M - 1)(N - 1)z
    // x > 0; y > 0; z >= 0;
    ll N, M, T; fin >> N >> M >> T;

    ll c1, c2, c3;
    c1 = N - 1;
    c2 = M - 1;
    c3 = (N - 1) * (M - 1);

    if(N == 1 && M == 1){
        fout << (T + 1) % MOD << '\n';
        return 0;
    }
    
    if(N == 1){
        ll ans = 0;
        for(int i = c2; i <= T; i+=c2){
            ans += T-i + 1;
            ans %= MOD;
        }

        fout << ans << '\n';

        return 0;
    }

    if(M == 1){
        ll ans = 0;
        for(int i = c1; i <= T; i+=c1){
            ans += T-i + 1;
            ans %= MOD;
        }

        fout << ans << '\n';

        return 0;
    }

    //cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
    list<ll> dp(c2 + 1);
    //cout << sum(N, M, T) << '\n';
    ll ans = 0;
    for(int i = 1; i <= T; i++){
        if(i % c1 == 0){
            dp.back() += 1;
            dp.back() %= MOD;
        }
        if(dp.front() != 0){
            dp.back() += dp.front();
            dp.back() %= MOD;
        }

        //fout << i << ": " << dp[i] << '\n'; 
        ll remaining = T - i;
        
        ll start = remaining % c3;
        ll count = remaining / c3 + 1;

        ans += sum(start + 1, c3, count)*dp.front();
        ans %= MOD;

        dp.pop_front();
        dp.push_back(0);
    }

    fout << ans << '\n';

    return 0;
}