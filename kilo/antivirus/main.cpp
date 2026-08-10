#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long

ifstream fin("antivirus.in");
ofstream fout("antivirus.out");

typedef pair<ll, ll> ip;

int main(){
    ll T;
    fin >> T;

    for(int cer = 0; cer < T; cer++){
        
        ll N, K;
        fin >> N >> K;

        vector<int> a(N+2, 0);

        ll amdeja = 0;
        for(ll i = 1; i <= N; i++){
            fin >> a[i];
            amdeja += (a[i] == 0);
        }

        ll last = 1;
        vector<ip> intervale;
        for(ll i = 1; i <= N + 1; i++){
            if(a[i] == 0){
                intervale.push_back({last, i - 1});
                last = i + 1;
            }
        }

        vector<vector<ll>> mincosts(intervale.size());

        int i = 0;
        for(auto p : intervale){
            //cout << p.first << ' ' << p.second << '\n';
            ll nel = p.second - p.first + 1;
            mincosts[i].resize(nel + 1, 0);

            vector<ll> sp(nel + 1, 0);
            for(ll i = 1; i <= nel; i++){
                sp[i] = sp[i - 1] + a[p.first + i - 1];
            }

            for(ll cnt = 1; cnt <= nel; cnt++){
                ll minc = 2*((ll)INT_MAX);
                for(ll lefte = 0; lefte <= cnt; lefte++){
                    ll localc = sp[lefte] + sp[nel] - sp[nel - (cnt - lefte)];
                    minc = min(minc, localc);
                }

                mincosts[i][cnt] = minc;
            }

            // for(auto el : mincosts[i]){
            //     cout << el << ' ';
            // } cout << "\n\n";

            i++;
        }

        if(intervale[0].first < intervale[0].second){
            ll sum = 0;
            for(int i = intervale[0].second; i >= intervale[0].first; i--){
                sum += a[i];
                mincosts[0][intervale[0].second - i + 1] = sum;
            }
        }

        if(intervale.back().first < intervale.back().second){
            ll sum = 0;
            for(int i = intervale.back().first; i <= intervale.back().second; i++){
                sum += a[i];
                mincosts.back()[i - intervale.back().first + 1] = sum;
            }
        }

        vector<ll> dp(K + 1, 2*((ll)INT_MAX));
        dp[0] = 0;
        vector<ll> ndp(K + 1, 2*((ll)INT_MAX));

        for(ll i = 0; i < (ll)mincosts.size(); i++){
            for(ll cnt = 0; cnt < (ll)mincosts[i].size(); cnt++){
                for(ll dpcnt = 0; dpcnt <= K - cnt; dpcnt++){
                    ndp[dpcnt + cnt] = min(
                        ndp[dpcnt + cnt],
                        dp[dpcnt] + mincosts[i][cnt]
                    );
                }
            }
            dp = ndp;
            fill(ndp.begin(), ndp.end(), 2*((ll)INT_MAX));
        }

        fout << dp[K - amdeja] << '\n';

    }

    
    return 0;
}