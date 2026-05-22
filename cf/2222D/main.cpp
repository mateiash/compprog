#include <bits/stdc++.h>
#include <ios>

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
        vector<ip> sp;

        int n; cin >> n;
        ll last = 0;
        for(int i = 1; i <= n; i++){
            ll el; cin >> el;
            sp.push_back({last, i});
            last += el;
        }

        sort(sp.begin(), sp.end());

        ll p[n + 1];
        int toset = n;
        for(auto el : sp){
            p[el.second] = toset;
            toset--;
        }

        for(int i = 1; i <= n; i++){
            cout << p[i] << ' ';
        }
        cout << '\n';

    }

    return 0;
}
