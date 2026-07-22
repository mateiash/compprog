#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<vector<int>> doubles;
vector<vector<int>> singles;

int a[200'005];

int main(){

    int t; cin >> t;
    
    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        doubles.clear();
        singles.clear();
        doubles.resize(n + 2);
        singles.resize(n + 2);

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            if(el == a[i]){
                doubles[el].push_back(i);
                continue;
            }
            singles[el].push_back(i);
            singles[a[i]].push_back(i);
        }

        vector<ll> dp(n + 2, 0);
        ll ans = 0;


        {
            int prev = 0;
            size_t di = 0, si = 0;
            while(di < doubles[1].size() || si < singles[1].size()){
                bool takeDouble;
                if(di >= doubles[1].size()) takeDouble = false;
                else if(si >= singles[1].size()) takeDouble = true;
                else takeDouble = doubles[1][di] < singles[1][si];

                if(takeDouble){
                    int P = doubles[1][di++];
                    ll fresh = P - prev;
                    dp[P] = fresh;

                    auto itlim1 = lower_bound(doubles[2].begin(), doubles[2].end(), P);
                    int lim1 = (itlim1 != doubles[2].end()) ? *itlim1 : n + 1;
                    auto itlim2 = lower_bound(singles[2].begin(), singles[2].end(), P);
                    int lim2 = (itlim2 != singles[2].end()) ? *itlim2 : n + 1;

                    int nextBoundary = min(lim1, lim2);
                    ans += dp[P] * (ll)(nextBoundary - P);

                    prev = P;
                } else {
                    int H = singles[1][si++];
                    ll m = H - prev;
                    ans += m * (m - 1) / 2;
                    prev = H;
                }
            }
            ll m = n - prev;
            ans += m * (m + 1) / 2;
        }

        for(int i = 2; i <= n; i++){
            for(int pos = 0; pos < doubles[i].size(); pos++){
                int P = doubles[i][pos];

                auto it = lower_bound(doubles[i - 1].begin(), doubles[i - 1].end(), P);
                if(it == doubles[i - 1].begin()) continue;
                --it;
                int R = *it;

                if(pos > 0 && doubles[i][pos - 1] > R) continue;

                auto it2 = lower_bound(singles[i].begin(), singles[i].end(), R);
                int piedica = (it2 != singles[i].end()) ? *it2 : n + 1;
                if(piedica < P) continue;

                dp[P] += dp[R];

                auto itlim1 = lower_bound(doubles[i + 1].begin(), doubles[i + 1].end(), P);
                int lim1 = (itlim1 != doubles[i + 1].end()) ? *itlim1 : n + 1;
                auto itlim2 = lower_bound(singles[i + 1].begin(), singles[i + 1].end(), P);
                int lim2 = (itlim2 != singles[i + 1].end()) ? *itlim2 : n + 1;

                int nextBoundary = min(lim1, lim2);
                ans += dp[P] * (ll)(nextBoundary - P);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
