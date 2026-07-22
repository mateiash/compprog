#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[200'005];
ll aib[200'005];

void update(int index, int val) {
    index = index + 1;

    while (index <= 200'005) {
        aib[index] += val;
        index += index & (-index); 
    }
}

int query(int index) {
    int sum = 0;
    index = index + 1;

    while (index > 0) {
        sum += aib[index];
        index -= index & (-index); 
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;

        cin >> n;

        vector<ll> scor(n + 5, 0);
        vector<ll> cnt(n + 5, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            scor[1] += n - i + 1;
            scor[a[i] + 1] -= n - i + 1;

            cnt[1]++;
            cnt[a[i] + 1]--;

            update(a[i], 1);
        }

        ll basic = 0;
        
        for(int i = 1; i <= n; i++){
            scor[i] += scor[i - 1];
            cnt[i] += cnt[i - 1];
        }

        for(int i = 1; i <= n; i++){
            basic += scor[i];
            basic -= (cnt[i] + 1) * cnt[i] / 2;
        }

        vector<bool> checked(n + 5, 0);
        ll ans = basic;
        for(int i = n; i >= 1; i--){
            update(a[i], -1);
            if(checked[a[i]] == 1) continue;
            checked[a[i]] = 1;

            ll beforethis = query(n) - query(a[i] - 1);
            ll afterthis = cnt[a[i]] - 1 - beforethis;

            ll newone = basic;
            newone -= n - i + 1;
            newone += afterthis + 1;
            newone += beforethis;

            ans = max(ans, newone);

        }

        //cout << "basic: " << basic << '\n';
        cout << ans << '\n';

    }

    return 0;
}
