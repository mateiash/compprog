#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 1'000'000'007

using namespace std;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}


int main(){
    ll N, T;
    cin >> N >> T;

    // generate matrix row
    ll row[1'000'005] = {0};
    row[1] = 1;
    for(int j = 2; j <= N; j++){
        row[j] = row[j-1] * ((T + j - 1) % MOD) % MOD * modpow(j - 1, MOD - 2) % MOD;
    }

    /*
    for(int j = 1; j <= N; j++){
        cout << row[j] << ' ';
    }cout << '\n';
    */
    ll rez = 0;
    for(int i = 1; i <= N; i++){
        ll el;
        cin >> el;

        rez += ((el + MOD) % MOD) * row[N + 1 - i] % MOD;
        rez = rez % MOD;
    }
    
    cout << rez << '\n';
    return 0;
}