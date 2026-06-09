#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

struct req{
    ll l;
    ll r;
    ll s;
};

bool operator<(const req& a, const req& b){
    return 
        make_pair(make_pair(a.l, a.r), a.s) < 
        make_pair(make_pair(b.l, b.r), b.s);
}

ll ans[5005];
bool used[5005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> vprime;
    set<req> v;
    for(int i = 0; i < m; i++){
        ll l, r, s;
        cin >> l >> r >> s;
        v.insert({l, r, s});
    }

    for(int i = 1; i <= n; i++){
        vector<pair<ll, ll>> dat;
        for(auto it = v.lower_bound({i, -1, -999999999999999999}); 
            it != v.upper_bound({i, 999'999, -999999999999999999}); it++){

            dat.push_back({it->r, it->s});
        }

        ll last = i;
        ll lastsum = 0;
        for(auto el : dat){
            v.erase({i, el.first, el.second});
        }
        //cout << '\n';
        for(auto el : dat){
            v.insert({last, el.first, el.second - lastsum});
            if(last > el.first){
                cout << "NO\n";
                goto fini;
            }
            last = el.first + 1;
            lastsum = el.second;
        }
    }
    for(auto el : v){
        vprime.insert({
            el.l,
            el.r
        });        
    }

    if(vprime.size()!=v.size()){
        cout << "NO\n";
        goto fini;
    }
    vprime.clear();
    
    for(int i = n; i >= 1; i--){
        auto it = v.lower_bound({i, -1, -1});
        req el = *it;
        if(i != el.l) continue;

        ll sum = 0;
        for(int i = el.l; i <= el.r; i++){
            sum += ans[i];
        }

        ans[i] = el.s - sum;
    }
    cout << "YES\n";

    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    fini:
    return 0;
}
