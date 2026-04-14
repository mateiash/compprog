#include <bits/stdc++.h>
#include <cstddef>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;

        // i = 1
        int ftgcd = gcd(a[1], a[2]);
        if(a[1] / ftgcd > 1){
            ans++;
        }
        int ltgcd = gcd(a[n - 1], a[n]);
        if(a[n] / ltgcd > 1){
            ans++;
        }

        for(int i = 2; i <= n - 1; i++){
            int prv = gcd(a[i - 1], a[i]);
            int nxt = gcd(a[i], a[i + 1]);

            int lcmshi = lcm(prv,nxt);

            if(a[i] / lcmshi > 1){
                ans++;
            }
            
        }

        cout << ans << '\n';
    }

    return 0;
}
