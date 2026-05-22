#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll l, r, G;
        cin >> l >> r >> G;

        l = (l + G - 1) / G;
        r = r / G;

        if(r < l || (l == r && l != 1)) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }

        for(ll len = r - l; len >= 0; len--){
            for(ll i = l; i <= r - len; i++){
                if(gcd(i, i + len) == 1){
                    cout << G * i << ' ' << G * (i + len) << '\n'; 
                    goto fini;
                }
                
            }
        }

        fini:
        continue;
    }

    return 0;
}
