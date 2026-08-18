#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

ll costuri[8'000'005];
ll pasigol[100'005][18];

ll prefix[100'005];
ll suffix[100'005][18];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 8'000'000; i++){
        if(i % 2) costuri[i] = costuri[i - 1] + 1;
        else costuri[i] = costuri[i/2] + 1;
    }

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;
        cin >> n;

        ll initial = 0;
        vector<ll> a;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a.push_back(el);
            initial += costuri[el];
        }
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= 17; j++){
                int p = 1 << j;
                ll least = ((p - a[i] % p) % p) + a[i];
                ll best = LLONG_MAX;
                for(int mult = 0; mult < 40; mult++){
                    ll b = least + (ll)mult * p;
                    //cout << b << endl;
                    ll cost = (b - a[i]) + costuri[b];
                    best = min(best, cost);
                }
                pasigol[i][j] = best;
            }
        }

        ll lasts[18] = {0};
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 18; j++){
                suffix[i][j] = pasigol[i][j] + lasts[j]; //+ costuri[i];
                lasts[j] = suffix[i][j];
            }
        }

        ll ans = initial;

        //cout << "\n";
        //cout << "init: " << initial << '\n';
        for(int i = 1; i <= 17; i++){
            //cout << i << ": " << suffix[0][i] - i * (n - 1) << '\n';
            ans = min(ans, suffix[0][i] - i * (n - 1));
        }

        cout << ans << "\n";

    }
    
    return 0;
}