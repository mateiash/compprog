#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 998'244'353

using namespace std;

ll a[200'005];

//ofstream fout("debug.out");

ll factmod[200'005];
ll invfactmod[200'005];

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r = (r * a) % MOD;
        }

        a = a * a % MOD;

        e >>= 1;
    }

    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factmod[0] = 1;
    for(int i = 1; i <= 200'004; i++){
        factmod[i] = factmod[i-1] * i % MOD;
    }

    invfactmod[200'004] = fastexp(factmod[200'004], MOD - 2);

    for(int i = 200'003; i >= 0; i--){
        invfactmod[i] = invfactmod[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        ll sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum+=a[i];
            sum %= MOD;
        }

        ll cnt = 1;
        ll available = 0;

        if(n % 2){
            if(a[(n + 1)/2] == 0){
                available++;
            }
            if(a[(n + 1)/2] > 1){
                cout << "0\n";
                goto done;
            }
        }
        
        if(sum != n){
            cout << "0\n";
            goto done;
        }

        for(int i = (n+1)/2 + 1; i <= n; i++){
            if(a[i]){
                cout << "0\n";
                goto done;
            }
        }


        for(int i = n/2; i >= 1; i--){
            available += 2;
            ll need = a[i];
            
            if(available < need){
                cout << "0\n";
                goto done;
            }

            cnt*=(factmod[available] * 
                invfactmod[available - need] % MOD * 
                invfactmod[need] % MOD
            );
            cnt %= MOD;
            available -= need;

        }

        cout << cnt << '\n';

        done:

        n = 0;

    }

    return 0;
}
