#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll sp[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        int m; cin >> m;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            sp[i] = sp[i - 1] + el;
        }

        vector<int> b = {0};
        for(int i = 1; i <= m; i++){
            int el; cin >> el;
            b.push_back(el);
        }
        sort(b.begin(), b.end());

        ll ans = sp[n];
        for(int i = 1; i < (ll)b.size(); i++){
            if(sp[b[i]] - sp[b[i - 1]] < 0) {
                ans -= sp[b[i]] - sp[b[i - 1]];
                ans -= sp[b[i]] - sp[b[i - 1]];
            }
        }

        cout << ans << '\n';

    }

    return 0;
}
