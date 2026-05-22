#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

#define MOD 1'000'000'007

using namespace std;

ll a[200'005];
ll sp[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        string s;
        cin >> s;

        for(int i = 1; i <= s.size(); i++){
            char c = s[i - 1];
            if(c == '0') a[i] = -1;
            else a[i] = 1;

            sp[i] = sp[i - 1] + a[i];
        }

        map<ll, ll> enc;
        ll ans = 0;

        enc[0] = 1;
        for(int i = 1; i <= s.size(); i++){
            ans = ans + enc[sp[i]] * (s.size() + 1 - i);
            ans %= MOD;

            enc[sp[i]] += i + 1;
            enc[sp[i]] %= MOD;

        }

        cout << ans << '\n';

    }

    return 0;
}
