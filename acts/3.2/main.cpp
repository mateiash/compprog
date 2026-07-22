#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll a[3005];
ll sp[3005];

ll dp[3005][3005];

int main(){
    ll n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        sp[i] = sp[i - 1] + a[i];
    }

    for(ll i = 1; i <= n; i++){
        for(int subp = 0; i <= min(i-1, k - 1); subp++){
            for(int j = 0; j < i; j++){
                dp[subp + 1][j] = min(dp)
            }
        }
    }

    return 0;
}
