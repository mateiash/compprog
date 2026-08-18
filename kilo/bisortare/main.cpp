#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define ll long long

ll lsb(ll x){
    return x & (-x);
}

ll aib[100'005];

void update(ll pos, ll val) {
    while(pos < 100'005){
        aib[pos] += val;
        pos += lsb(pos);
    }
}

ll sum(ll pos) {
    ll r = 0;
    while(pos){
        r += aib[pos];
        pos -= lsb(pos);
    }
    return r;
}

typedef pair<ll, ll> ip;

ifstream fin("test.in");

int main(){
    ll C, N, K;
    cin >> C >> N >> K;

    vector<ll> v;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    vector<ll> st;
    vector<ll> dr;
    for(auto el : v){
        st.push_back(
            sum(el)
        );
        update(el, 1);
    }

    fill(aib, aib + 100'005, 0);
    for(int i = v.size() - 1; i >= 0; i--){
        int el = v[i];
        dr.push_back(
            sum(el)
        );
        update(el, 1);
    }
    reverse(dr.begin(), dr.end());

    ll sum = accumulate(dr.begin(), dr.end(), 0LL);

    set<ip> diff;

    for(int i = 0; i < N; i++){
        diff.insert({st[i] - dr[i], i});
    }
    // for(auto el : diff){
    //     cout << el.first << ' ' << el.second << '\n';
    // }

    vector<ll> ans;
    ans.push_back(sum);
    while(diff.size()){
        sum += diff.begin()->first;
        if(v[diff.begin()->second] != 1)
            ans.push_back(sum);
        diff.erase(diff.begin());
    }
    

    if(C == 2) {
        for(auto el : ans){
            cout << el << ' ';
        }
        cout << '\n';

        return 0;
    }

    cout << ans[K - 1] << '\n';

    return 0;
}