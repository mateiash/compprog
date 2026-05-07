#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

#define MOD 998'244'353LL

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n; cin >> n;
        ll x; cin >> x;

        ll with0X = (x + 1 - 1)/4 + 1;
        with0X %= MOD;
        ll with1X = (x + 3 - 1)/4;
        with1X %= MOD;

        //cout << "x: " << with0X << ' ' << with1X << '\n'; 

        ll with0N = (n + 1)/4 - with0X + 1;
        with0N %= MOD;
        ll with1N = (n + 3)/4 - with1X;
        with1N %= MOD;
        //cout << "n: " << with0N << ' ' << with1N << '\n'; 

        cout << (with0X * with0N % MOD + with1X * with1N % MOD) % MOD << '\n';
    }

    return 0;
}
