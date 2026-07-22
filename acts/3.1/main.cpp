#include <bits/stdc++.h>
#include <istream>

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;

typedef pair<ll, ll> ip;
vector<ip> cht;

ll x[1'000'005];
ll a[1'000'005];
ll b[1'000'005];
ll dp[1'000'005];

ld intersect(ip a, ip b){
    return ((ld)b.second - (ld)a.second) / ((ld)a.first - (ld)b.first);
}

void insert(ip line){
    while(cht.size() >= 2 && intersect(line, cht[cht.size()-2]) < intersect(cht.back(), cht[cht.size()-2])){
        cht.pop_back();
    }
    cht.push_back(line);
}

ll query(ll x){
    if(cht.empty()) return 0;
    if(cht.size() == 1) return cht[0].first * x + cht[0].second;

    int low = 0, high = (int)cht.size() - 2;
    int best_idx = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(intersect(cht[mid], cht[mid + 1]) <= (ld)x) {
            best_idx = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    return cht[best_idx].first * x + cht[best_idx].second;
}


int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x[i];
        cin >> a[i];
        cin >> b[i];
    }

    dp[0] = a[0] + x[0]*b[0];
    insert({x[0], -dp[0]});
    cout << dp[0] << endl;
    for(int i = 1; i < n; i++){
        ll fordp = query(b[i]);
        dp[i] = min(a[i] + x[i]*b[i],
            a[i] + x[i]*b[i] - fordp
        );

        cout << dp[i] << endl;

        insert({x[i], -dp[i]});
    }

    return 0;
}
