#pragma GCC optimize("Ofast")
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<ll, ll> ip;

vector<ip> byX;
vector<ll> byY;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        byX.clear();
        //cout << "cerinta " << cer + 1 << '\n';
        vector<vector<ll>> suportX(n + 1);
        vector<ll> suportY(n + 1);
        for(int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            suportX[x].push_back(y);
            suportY[y]++;
        }

        for(int i = 0; i <= n; i++){
            for(auto j : suportX[i]){
                byX.push_back({i, j});
            }
        }
        suportX.clear();

        vector<ll> yvalsfront;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < suportY[i]; j++){
                yvalsfront.push_back(i);
            }
        }
        suportY.clear();

        byY.clear();
        byY.resize(n + 1);
        ll last = -1;
        int ind = 0;
        for(auto el : yvalsfront){
            if(el == last) continue;
            byY[el] = ind;
            ind++;
            last = el;
        }

        
        byX.push_back({-1, -1});
        
        ll next = 0;
        ll on = -1;
        vector<ll> ybackmin(n + 1); ybackmin[0] = 999'999'999;
        vector<ll> ybackmax(n + 1); ybackmax[0] = -1;
        for(int i = 1; i <= n; i++){
            ybackmax[i] = max(ybackmax[i - 1], byX[i - 1].second);
            ybackmin[i] = min(ybackmin[i - 1] , byX[i - 1].second);
        }
        
        vector<ll> yfrontmin(n + 2); yfrontmin[n + 1] = 999'999'999;
        vector<ll> yfrontmax(n + 2); yfrontmax[n + 1] = -1;
        for(int i = n; i >= 1; i--){
            yfrontmax[i] = max(yfrontmax[i + 1], byX[i - 1].second);
            yfrontmin[i] = min(yfrontmin[i + 1] , byX[i - 1].second);
        }

        ll ans = 0;
        while(next < n){
            do {
                on = byX[next].first;
                next++;
            } while(byX[next].first == on);

            if(next >= n) break;
            // find min
            ll start = max(
                ybackmin[next],
                yfrontmin[next + 1]
            );
            // fuin max
            ll finish = min(
                ybackmax[next],
                yfrontmax[next + 1]
            );
            ll cnt = 
                byY[finish] - 
                byY[start];
            
            cnt = max(0LL, cnt);

            //cout << cnt << " cnt\n";
            ans += cnt;
            //cout.flush();
        }
        cout << ans;
        cout << "\n";

    }

    return 0;
}
