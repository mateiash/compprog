#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<vector<int>> doubles;
vector<vector<int>> singles;

int a[200'005];

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        doubles.clear();
        singles.clear();

        doubles.resize(n + 2);
        singles.resize(n + 2);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++){
            int el; cin >> el;

            if(el == a[i]){
                doubles[el].push_back(i);
                continue;
            }

            singles[el].push_back(i);
            singles[a[i]].push_back(i);
        }

        vector<ll> dp(n + 1);
        ll ans = 0;

        for(int i = 1; i <= n; i++){
            if(i == 1){
                for(int pos = 0; pos < (int)doubles[1].size(); pos++){
                    int P = doubles[1][pos];

                    auto ith = lower_bound(singles[1].begin(), singles[1].end(), P);
                    int prevHaz = 0;
                    if(ith != singles[1].begin()){
                        ith--;
                        prevHaz = *ith;
                    }

                    int prevSame = (pos > 0) ? doubles[1][pos - 1] : 0;

                    int boundary = max(prevHaz, prevSame);
                    ll fresh = P - boundary;

                    dp[P] = fresh;

                    auto itlim1 = lower_bound(doubles[2].begin(), doubles[2].end(), P);
                    int lim1 = n + 1;
                    if(itlim1 != doubles[2].end()) lim1 = *itlim1;

                    auto itlim2 = lower_bound(singles[2].begin(), singles[2].end(), P);
                    int lim2 = n + 1;
                    if(itlim2 != singles[2].end()) lim2 = *itlim2;

                    int validEnd = min(lim1, lim2 - 1);
                    ans += fresh * (validEnd - P + 1);
                }
                continue;
            }

            for(int pos = 0; pos < (int)doubles[i].size(); pos++){
                {
                int P = doubles[i][pos];

                auto it = lower_bound(doubles[i - 1].begin(), doubles[i - 1].end(), P);
                if(it == doubles[i - 1].begin()) goto fini;
                it--;
                int R = *it;

                auto it2 = lower_bound(singles[i].begin(), singles[i].end(), R);
                int piedica = n + 67;
                if(it2 != singles[i].end()) piedica = *it2;

                if(piedica < P) goto fini;

                auto itlim1 = lower_bound(doubles[i + 1].begin(), doubles[i + 1].end(), P);
                int lim1 = n + 1;
                if(itlim1 != doubles[i + 1].end()) lim1 = *itlim1;

                auto itlim2 = lower_bound(singles[i + 1].begin(), singles[i + 1].end(), P);
                int lim2 = n + 1;
                if(itlim2 != singles[i + 1].end()) lim2 = *itlim2;

                int validEnd = min(lim1, lim2);
                ans += dp[R] * (validEnd - P + 1);
                dp[P] += dp[R];
                }
                fini:

                {
                int P = doubles[i][pos];

                auto it = lower_bound(doubles[i].begin(), doubles[i].end(), P);
                if(it == doubles[i].begin()) continue;
                it--;
                int R = *it;

                //if(pos > 0 && doubles[i][pos - 1] > R) continue;

                auto it2 = lower_bound(singles[i + 1].begin(), singles[i + 1].end(), R);
                int piedica = n + 67;
                if(it2 != singles[i + 1].end()) piedica = *it2;

                if(piedica < P) continue;

                auto itlim1 = lower_bound(doubles[i + 1].begin(), doubles[i + 1].end(), P);
                int lim1 = n + 1;
                if(itlim1 != doubles[i + 1].end()) lim1 = *itlim1;

                auto itlim2 = lower_bound(singles[i + 1].begin(), singles[i + 1].end(), P);
                int lim2 = n + 1;
                if(itlim2 != singles[i + 1].end()) lim2 = *itlim2;

                int validEnd = min(lim1, lim2);
                ans += dp[R] * (validEnd - P + 1);
                dp[P] += dp[R];
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}