#include <bits/stdc++.h>

#define MOD 998'244'353

#define ll long long
#define ull unsigned long long

using namespace std;

ll cont[30];

ll factmod[500'005];
ll invfactmod[500'005];

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

vector<ll> dp(500'005);

int main()
{
    int t;
    cin >> t;
    
    factmod[0] = 1;
    
    for(ll i = 1; i < 500'005; i++){
        factmod[i] = factmod[i - 1] * i % MOD;
    }
    
    invfactmod[500'004] = fastexp(factmod[500'004], MOD - 2);
    
    for(ll i = 500'003; i >= 0; i--){
        invfactmod[i] = invfactmod[i + 1] * (i + 1) % MOD;
    }

    for(int cer = 0; cer < t; cer++){
        dp.clear();
        dp.resize(500'005);
        ll base = 0;
        ll sum = 0;
        for(int i = 1; i <= 26; i++){
            ll el; cin >> el;
            sum += el;
            cont[i] = (el);
        }
        
        base = factmod[sum/2]*factmod[(sum+1)/2]%MOD;
        
        for(int i = 1; i < 27; i++){
            ll el = cont[i];
            if(!el)
                continue;
            base = base * invfactmod[el] % MOD;
        }
        
        sort(cont + 1, cont + 30, greater<int>());

        dp[0] = 1;

        //dp[1][cont[1]] = 1;
        int i;
        
        for(i = 1; i <= 27; i++){
            ll el = cont[i];
            //cout << el << ' ';
            if(!el)
                break;
            for(int summs = sum/2; summs >= el; summs--){
                dp[summs] = dp[summs] + dp[summs - el] % MOD;

            }
            
        }//cout << '\n';
        
        cout << '\n' << dp[sum/2] * base % MOD << "\n";
        
    }

    return 0;
}