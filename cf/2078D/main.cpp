#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<ll, ll> ip;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        vector<ip> left;
        vector<ip> right;

        left.push_back({0, 0});
        right.push_back({0, 0});
        for(int i = 1; i <= n; i++){
            char op; cin >> op;
            ll amt; cin >> amt;

            if(op == '+')
                left.push_back({0, amt});
            else
                left.push_back({1, amt});

            cin >> op;
            cin >> amt;

            if(op == '+')
                right.push_back({0, amt});
            else
                right.push_back({1, amt});

        }

        vector<ll> dpleft(n + 2);
        vector<ll> dpright(n + 2);

        dpleft[n + 1] = 1;
        dpright[n + 1] = 1;

        for(int i = n; i >= 1; i--){
            if(left[i].first == 0)
                dpleft[i] = dpleft[i + 1];
            else
                dpleft[i] = dpleft[i + 1] + (left[i].second - 1) * max(dpleft[i + 1], dpright[i + 1]);

            if(right[i].first == 0)
                dpright[i] = dpright[i + 1];
            else
                dpright[i] = dpright[i + 1] + (right[i].second - 1) * max(dpleft[i + 1], dpright[i + 1]);

        }

        ll lcnt = 1;
        ll rcnt = 1;

        for(int i = 1; i <= n; i++){
            ll extra = 0;

            if(left[i].first == 0)
                extra += left[i].second;
            else
                extra += lcnt * (left[i].second - 1);

            if(right[i].first == 0)
                extra += right[i].second;
            else
                extra += rcnt * (right[i].second - 1);

            if(dpleft[i + 1] > dpright[i + 1])
                lcnt += extra;
            else
                rcnt += extra;

        }

        cout << lcnt + rcnt << '\n';

    }

    return 0;
}