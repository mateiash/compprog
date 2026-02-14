#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int n, k;
int a[200'005];
int freq[200'005];

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        fill(a, a + n + 1, 0);
        fill(freq, freq + n + 1, 0);

        cin >> n >> k;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            freq[a[i]] = 1;
        }

        int output = a[1];

        for(int i = 1; i <= n; i++){
            if(freq[i] == 0){
                output = i;
                break;
            }
        }

        cout << output << ' ';

        int pp = a[n];
        int p = output;

        for(int i = 1; i < k; i++){

            if(abs(pp - p) == 1){
                output = max(pp, p) % n + 1;
            } else {
                output = (pp + p) / 2;
            }

            pp = p;
            p = output;
            cout << output << ' ';

        }

        cout << '\n';

    }

    return 0;
}
