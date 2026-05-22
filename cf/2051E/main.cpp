#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<ll, ll> ip;
vector<ip> dat;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        dat.clear();
        ll n, k;
        cin >> n >> k;

        ll ans = 0;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            dat.push_back({el, 0});
        }

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            dat.push_back({el, 1});
        }

        sort(dat.begin(), dat.end());

        ll poz = n;
        ll neg = 0;
        
        auto it = dat.begin();
        while(it != dat.end()){
            ll price = it->first;
            //cout << price << " price" << endl;
            if(neg <= k){
                ans = max(ans, (poz + neg) * price);
            }
            ip searched = {it->first + 1, -1};
            auto eit = lower_bound(dat.begin(), dat.end(), searched);
            for(; it != eit; it++){
                if(it->second == 0){
                    neg++;
                    poz--;
                } else {
                    neg--;
                }
            }
            
        }

        cout << ans << '\n';

    }

    return 0;
}
