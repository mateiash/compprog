#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

#define MOD 998244353

using namespace std;

int a[200'005];
int b[200'005];

int oga[200'005];
int ogb[200'005];

ll invmod(ll a){
    ll e = MOD - 2;
    ll r = 1;
    while(e){
        if(e & 1){
            r = (r * a) % MOD;
        }

        a = (a * a) % MOD;

        e >>= 1;
    }
    return r;
}

typedef pair<int, int> ip;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            oga[i] = a[i];
        }
        
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            ogb[i] = b[i];
        }

        a[n + 1] = 1'000'000'000;
        b[n + 1] = 1'000'000'000;

        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        ll ans = 1;

        for(int i = 1; i <= n; i++){
            ans *= min(a[i], b[i]);
            //cout << a[i] << ' ' << b[i] << ' ';
            ans %= MOD;
        } //cout << '\n';

        //cout << "\n\n\n\n";
        cout << ans << ' '; 

        for(int i = 1; i <= q; i++){
            int o, x; cin >> o >> x;
            int* ogarr = ogb;
            int* arr = b;
            int* notarr = a;

            if(o == 1) {
                swap(arr, notarr);
                ogarr = oga;
            }
            auto pos = upper_bound(arr + 1, arr + n + 2, ogarr[x]) - arr - 1;
            
            //cout << /*"cutting at " <<*/ pos << ' ';
            
            ll nans = ans;
            nans = nans * invmod(
                min(arr[pos], notarr[pos])
            ) % MOD;
            ;
            nans = nans * min(arr[pos] + 1, notarr[pos]) % MOD;
            arr[pos]++;
            ans = nans;
            ogarr[x]++;
            cout << nans << ' ';
            /*
            for(int i = 1; i <= n; i++){
                cout << a[i] << ' ';
            }
            cout << '\n';
            for(int i = 1; i <= n; i++){
                cout << b[i] << ' ';
            }
            cout << '\n';
            for(int i = 1; i <= n; i++){
                cout << oga[i] << ' ';
            }
            cout << '\n';
            for(int i = 1; i <= n; i++){
                cout << ogb[i] << ' ';
            }
            cout << '\n';
            */

        }
        cout << '\n';

    }

    return 0;
}
