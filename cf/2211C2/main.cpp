#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n, k; cin >> n >> k;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < k; i++){
            int checked2 = true;
            for(int j = i + 1; j <= n; j+=k){

            }
        }
    }

    return 0;
}
