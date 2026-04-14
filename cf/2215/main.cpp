#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[100'005];

ll spqp[100'005];
ll spp[100'005];
ll spopt[100'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc;
    cin >> tc;

    for(int cer = 0; cer < tc; cer++){
        ll n, k, p, q;

        cin >> n >> k >> p >> q;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // painting with this
        for(int i = 1; i <= n; i++){
            spp[i] = (a[i]) % p + spp[i - 1];
        }

        // painting this
        for(int i = 1; i <= n; i++){
            spqp[i] = ((a[i]) % q) % p + spqp[i - 1];
        }

        // painting this
        for(int i = 1; i <= n; i++){
            spopt[i] = min(
                ((a[i]) % q) % p,
                (a[i]) % p
            )
            + spopt[i - 1];
        }

        // 0 is closed  1 is open segment
        ll dp[2][100'005] = {0};

        for(int i = 1; i <= k; i++){
            dp[0][i] = spqp[i];
        }

        ll ans = 999999999999999999;

        for(int i = 1; i<= n - k + 1; i++){
            ans = min(
                ans,
                spopt[i - 1] + spp[i + k - 1] - spp[i - 1] + spopt[n] - spopt[i + k - 1]
            );
            ans = min(
                ans,
                spopt[i - 1] + spqp[i + k - 1] - spqp[i - 1] + spopt[n] - spopt[i + k - 1]
            );
        }

        cout << ans << '\n';


    }

    return 0;
}
