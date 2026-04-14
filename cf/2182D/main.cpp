#include <bits/stdc++.h>
#include <cstddef>

#define ll long long
#define ull unsigned long long

using namespace std;

#define MOD 998244353

int a[55];

ll facto(ll n){
    ll r = 1;
    while(n){
        r *= n;
        r%=MOD;
        n--;
    }
    return r;
}

ll factobound(ll start, ll stop){
    ll r = 1;
    while(stop >= start){
        r *= stop;
        r%=MOD;
        stop--;
    }

    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        int box0; cin >> box0;
        
        ll sum = 0;

        ll maxel = -999'999'999;
        ll maxcnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];

            if(a[i] > maxel){
                maxel = a[i];
                maxcnt = 1;
            } else if (a[i] == maxel){
                maxcnt++;
            }
        }

        ll ans = 0;

        for(int i = maxcnt; i <= n; i++){
            ll needed = (maxel-1)*n+i;

            if(needed <= sum + box0){
                ll localans = factobound(i - maxcnt + 1, i - 1)
                * facto(n - maxcnt);
                ;
                localans %= MOD;
                ans += localans;
                ans %= MOD;
            }


        }
        ans *= maxcnt;
        ans %= MOD;
        cout << ans << '\n';

    }

    return 0;
}

// sum 8
// 8 + 6 = 14
// 12 + 1 = 13
// 12 + 2 = 14
