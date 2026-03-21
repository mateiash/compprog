#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define ll long long
#define MOD 1'000'000'007

ifstream fin("cvintete.in");
ofstream fout("cvintete.out");

ll freq[20'005];

vector<ll> divisors;

struct tpair{
    ll a;
    ll b;
    ll c;

    ll cnt;
};

vector<tpair> abcs;

bool isps(ll n){
    ll rt = (ll) round(sqrt(n));

    return rt*rt == n;
}

int main(){

    ll N, D;
    fin >> N >> D;

    ll maxel = -1;
    ll minel = -1;

    for(int i = 1; i <= N; i++){
        ll el; fin >> el;

        if(minel == -1) minel = el;
        maxel = max(el, maxel);
        
        freq[el]++;
    }

    for(ll d = 1; d*d <= D; d++){
        if(D % d == 0 && freq[d]) {
            divisors.push_back(d);
        }

        if(d > maxel) break;
    }
    
    for(int ai = 0; ai < divisors.size(); ai++){
        ll a = divisors[ai];

        for(int bi = ai + 1; bi < divisors.size(); bi++){
            ll b = divisors[bi];
            if(a*b >= D) break;
            if(D % (a*b) != 0) continue;
            
            ll c = D / (a*b);
            if(c <= b) break;
            ll cnt = 0;
            if(c <= maxel) cnt = freq[a] * freq[b] % MOD * freq[c] % MOD;

            if(cnt) {
                abcs.push_back({a, b, c, cnt});
                /*
                cout << a << ' ';
                cout << b << ' ';
                cout << c << ' ';
                cout << cnt << '\n';
                */
            }

        }
    }

    ll ans = 0;

    for(auto el : abcs){
        ll a = el.a;
        ll b = el.b;
        ll c2 = el.c*el.c;

        if(c2 % gcd(a, b)) continue;

        for(int x = minel; x <= maxel; x++){
            if(freq[x] == 0) continue;

            ll by2 = c2 - a * x * x;
            if(by2 < 0) break;
            if(by2 % b != 0) continue;

            ll y2 = by2 / b;

            if(!isps(y2)) continue;

            ll y = (ll) round(sqrt(y2));

            if(y != x && freq[y]) ans+=el.cnt*freq[x]%MOD*freq[y]%MOD;
            ans %= MOD;
        }
    }

    fout << ans << '\n';

    return 0;
}