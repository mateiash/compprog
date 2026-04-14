#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int p[200'005];

int prefixgcd[200'005];
int suffixgcd[200'005];

int main(){
    int t;
    //cin >> t;
    t = 1;
    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }

        prefixgcd[1] = p[1];
        for(int i = 2; i <= n; i++){
            prefixgcd[i] = gcd(
                prefixgcd[i - 1], p[i]
            );
        }

        suffixgcd[n] = p[n];
        for(int i = n - 1; i >= 1; i--){
            suffixgcd[i] = gcd(
                suffixgcd[i + 1], p[i]
            );
        }


        ll ans = prefixgcd[n];
        for(int i = 2; i <= n - 1; i++){
            ans += 
                min(suffixgcd[i],
                    prefixgcd[i]);
        }

        cout << ans << '\n';

    }

    return 0;
}
