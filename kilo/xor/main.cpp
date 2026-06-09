#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("xor.in");
ofstream fout("xor.out");

typedef pair<ll, ll> ip;

ll combipar(ll n, ll k){
    if(n < 0 || k < 0) return 0;
    return
        (n & k) == k;
}

int main()
{
    ll q, i, j, a, b, m;
    fin >> q >> i >> j >> a >> b >> m;

    while(q){


        ll r = i;
        ll c = j;
        ll ans = 0;

        for(ll bit = 0; bit <= 42; bit++){
            ll ra = r + (1LL << bit);
            ll ca = c - (1LL << bit);

            ans += combipar(ra+ca, ca) << bit;
            if(ca < 0) break;

        }

        fout << ans << '\n';
        i = (a * i + b) % m;
        j = (a * j + b) % m;
        q--;
    }

    return 0;
}