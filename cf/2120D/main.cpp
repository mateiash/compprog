#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 1'000'000'007

using namespace std;

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1) {
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

    for(int cer = 0; cer < t; cer++){
        ll a, b, k;
        cin >> a >> b >> k;

        ll n = ((a-1)*k % MOD + 1) % MOD;
        cout << n << ' ';

        ll aCn = 1; ll denum = 1;

        for(int i = 1; i <= a; i++){
            denum = denum * i % MOD;
            aCn = aCn * (MOD + n - i + 1) % MOD;
        }

        ll m = aCn *k % MOD* fastexp(denum, MOD - 2) % MOD *(b - 1) + 1;
        m %= MOD;

        cout << m << '\n';

    }

    return 0;
}
