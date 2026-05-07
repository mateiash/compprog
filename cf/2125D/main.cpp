#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

#define MOD 998244353

using namespace std;

typedef pair<int, int> ip;
typedef pair<ip, ip> inter;

ll dp[200'005];

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    //cin >> t;
    t = 1;

    for(int cer = 0; cer < t; cer++){
        int n, m; cin >> n >> m;

        dp[0] = 1;

        vector<inter> intervale;

        for(int i = 1; i <= n; i++){
            int l, r, p, q;
            cin >> l >> r >> p >> q;

            intervale.push_back(
              {  {l, r}, {p, q} }
            );

            dp[0] *= MOD + q - p; dp[0] %= MOD;
            dp[0] *= fastexp(q, MOD - 2); dp[0] %= MOD;
        }

        sort(intervale.begin(), intervale.end());

        for(auto interval : intervale){
            int l = interval.first.first;
            int r = interval.first.second;

            int p = interval.second.first;
            int q = interval.second.second;
            
            ll adder =  
                dp[l - 1] * 
                fastexp(MOD + q - p, MOD - 2) % MOD
            ;

            adder *= p; adder %= MOD;

            dp[r] += adder; dp[r] %= MOD;
        }

        cout << dp[m] << '\n';


    }

    return 0;
}
