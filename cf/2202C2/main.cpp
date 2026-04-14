#include <bits/stdc++.h>
#include <cstddef>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[300'005];

ll met[300'005];



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a[i] = el;
        }
        

        ll treshold = a[1];
        ll startind = 1;
        ll ans = 1;
        ll dp[300'005] = {0};
        dp[1] = 1;
        met[0] = 1;

        ll maxmet = 0;

        for(int i = 2; i <= n; i++){
            if(a[i] - a[i - 1] < 2 && a[i] > treshold){
                //
            } else {
                for(int i = 0; i <= maxmet; i++){
                    met[i] = 0;
                }
                startind = i;
                treshold = a[i];
                met[0] = startind;
                // new monotonous
                dp[i] = 1 + dp[i - 1] + i - 1 ;
                ans+=dp[i];
                continue;
            }




            /*if(met[
                a[i] - a[startind]
            ] == 0) */met [ a[i] - a[startind] ] = i;
            maxmet = max(maxmet, a[i] - a[startind]);
            dp[i] = 1 
            + dp[i - 1] - startind + 1
            + (i - 1 
                - (met[a[i] - a[startind] - 1] - startind + 1));

            ans += dp[i];
        }
        /*
        cout << '\n';
        for(int i = 0; i <= n; i++){
            cout << dp[i] << ' ';
        } cout << '\n';
        for(int i = 0; i <= n; i++){
            cout << met[i] << ' ';
        } cout << '\n';
        */
        cout << ans << '\n';

    }

    return 0;
}