#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<ll, ll> ip;

ll p[100'005];
ip steps[100'005];

set<int> fragmentation;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;
        cin >> n;

        for(ll i = 1; i <= n; i++){
            cin >> p[i];
        }
        for(ll i = 1; i <= n - 1; i++){
            ll step = abs(p[i] - p[i + 1]);
            steps[i] = {step, i};
        }

        sort(steps + 1, steps + n);

        fragmentation.clear();
        fragmentation.insert(0);
        fragmentation.insert(n);

        ll dpmaybe[100'005] = {0};

        for(ll i = 1; i <= n - 1; i++){
            ll step = steps[i].first;
            ll index = steps[i].second;

            auto greaterit = fragmentation.upper_bound(index);
            ll greater = *(greaterit);
            ll lesser = *(prev(greaterit));

            //cout << lesser << ' ' << greater << '\n';

            ll invalidated = (greater - index) * (index - lesser);
            dpmaybe[step+1] -= invalidated;

            fragmentation.insert(index);
        }
        ll ans = n * (n - 1) / 2;
        for(ll i = 1; i <= n - 1; i++){
            ans += dpmaybe[i];
            cout << ans << ' ';
        }

        cout << "\n";


    }

    return 0;
}
