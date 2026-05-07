#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 998244353

using namespace std;

ll a[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        
        ll last0;
        ll last1;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        if(a[1] == 0) {
            last0 = 1;
            last1 = 1;
        } else {
            last0 = 1;
            last1 = 0;
        }

        for(int i = 2; i <= n; i++){
            ll liar = last1;

            ll truther = 0;
            // try to transform last 0 into 1
            if(a[i - 2] + 1 == a[i]) {
                truther += last0;
            }
            // blah blah blah the other ojne
            if(a[i - 1] == a[i]){
                truther += last1;
            }

            last0 = liar % MOD;
            last1 = truther % MOD;
        }

        cout << (last0 + last1) % MOD << '\n';

    }

    return 0;
}
