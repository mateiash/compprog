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
        ll n, k;
        cin >> n >> k;

        string l, r;
        cin >> l >> r;

        ll cases[4] = {};
        // 0: 0 0
        // 1: 0 1
        // 2: 1 0
        // 3: 1 1

        for(int i = 0; i <= n - 1; i++){
            if(l[i] == '0' && r[i] == '0') cases[0]++;
            if(l[i] == '0' && r[i] == '1') cases[1]++;
            if(l[i] == '1' && r[i] == '0') cases[2]++;
            if(l[i] == '1' && r[i] == '1') cases[3]++;
        }

        ll ans = 0;
        ll tot = (1 << k) + 1;
        if(tot % 3 == 0){
            ans += (n - cases[0] - cases[1]) * (cases[0] + cases[1])*tot/3;
            ans += (n - cases[0] - cases[2]) * (cases[0] + cases[2])*tot/3;
            ans += (n - cases[0] - cases[3]) * (cases[0] + cases[3])*tot/3;

            cout << ans << '\n';
        } else {
            ans += (n - cases[0] - cases[1]) * (cases[0] + cases[1])*(tot/3 + 1);
            ans += (n - cases[0] - cases[2]) * (cases[0] + cases[2])*(tot/3 + 1 - tot/2%2);
            ans += (n - cases[0] - cases[3]) * (cases[0] + cases[3])*(tot/3 + tot/2%2);

            cout << ans << '\n';
        }
        
    }

    return 0;
}
