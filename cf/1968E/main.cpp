#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n; cin >> n;

        cout << 1 << ' ' << 1 << '\n';
        cout << n << ' ' << n << '\n';

        for(int i = 1; i <= n - 3; i++){
            cout << 1 << ' ' << i + 1 << '\n';
        }

        if(n >= 3)
            cout << 2 << ' ' << n << '\n';

        cout << '\n';

    }

    return 0;
}
