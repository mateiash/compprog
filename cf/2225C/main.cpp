#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int N; cin >> N;
        string a, b;
        cin >> a >> b;

        if(N == 1){
            cout << (a[0] != b[0]) << '\n';
            continue;
        }


        int total = 0;
        for(int i = 0; i < N; i++){
            if(i == N - 1){
                total += (a[i] != b[i]);
                continue;
            }

            int laid = 0; int standing = 0;

            laid += a[i] != a[i+1];
            laid += b[i] != b[i+1];

            standing += a[i] != b[i];
            standing += a[i + 1] != b[i+1];

            if(laid < standing) {
                i++;
                total += laid;
            } else {
                total += a[i] != b[i];
            }
        }
        cout << total << '\n';

    }

    return 0;
}
