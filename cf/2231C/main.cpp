#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

set<ll> possible;
map<ll, ll> counts;
map<ll, ll> howmany;

ll a[100'005];

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        possible.clear();
        counts.clear();
        howmany.clear();

        ll minel = 999'999'999'999;

        for(int i = 1; i <= n; i++){
            ll el; cin >> el;
            minel = min(el, minel);
            a[i] = el;
        }

        while(minel != 1){
            possible.insert(minel);

            if(minel % 2){
                minel++;
            } else {
                minel /= 2;
            }
        }
        possible.insert(1);
        possible.insert(2);
        counts[1] = 0;
        counts[2] = 0;

        for(int i = 1; i <= n; i++){
            ll el = a[i];
            ll opps = 0;
            howmany[1]++;

            if(el == 1){
                counts[2]++;
                howmany[2]++;
                continue;
            }

            while(el != 1){
                if(possible.count(el)){
                    counts[el] += opps;
                    howmany[el]++;
                }
                if(el % 2){
                    el++;
                } else {
                    el /= 2;
                }
                opps++;
            }
            counts[1] += opps;
        
        }

        ll ans = 999'999'999'999;
        for(auto el : counts){
            if(howmany[el.first] == n)
                ans = min(ans, el.second);
        }
        cout << ans << "\n";

    }

    return 0;
}
