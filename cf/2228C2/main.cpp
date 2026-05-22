#include <bits/stdc++.h>
#include <cstdlib>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<ll> av;

ll conv(ll ind){
    ll exp = 1;
    ll r = 0;
    ll digs = 1;
    ll substraction = av.size();

    if(av.size() == 1){
        ind++;
        while(ind){
            int u = ind % av.size();
            ind--;

            r += av[u]*exp;
            exp *= 10;
        }

        return r;
    }

    if(av[0] == 0){
        while(ind){
            int u = ind % av.size();
            ind /= av.size();

            r += av[u]*exp;
            exp *= 10;
        }

        return r;
    }

    while(ind >= substraction){
        ind -= substraction;
        substraction *= av.size();
        digs++;
    }


    while(digs){
        int u = ind % av.size();
        ind /= av.size();

        r += av[u]*exp;
        exp *= 10;
        digs--;
    }
    return r;
}

ll betterpow(ll a, ll e){
    ll r = 1;
    while(e--){
        r *= a;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        av.clear();
        ll a, n;
        cin >> a >> n;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            av.push_back(el);
        }
        /*
        for(int i = 0; i <= 10; i++){
            cout << conv(i) << ' ';
        } cout << '\n';
        cout.flush();
        */
        // is this some actual ternary searfh ts is unbelaeibavle

        ll l = 0; ll r = betterpow(av.size(), 18);
        if(av.size()==1) r = 18;
        ll ans = -1;

        while(l <= r){
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;

            if(abs(a - conv(m1)) == abs(a - conv(m2))){
                l = m1 + 1;
                r = m2 - 1;
                ans = m1;
            } else if(abs(a - conv(m1)) < abs(a - conv(m2))){
                r = m2 - 1;
                ans = m1;
            } else {
                l = m1 + 1;
                ans = m2;
            }

        }

        cout << abs(a - conv(ans)) << '\n';

    }

    return 0;
}
