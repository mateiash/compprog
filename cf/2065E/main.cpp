#include <bits/stdc++.h>
#include <tuple>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n, m, k;
        cin >> n >> m >> k;

        if(abs(n - m) > k) {
            cout << "-1\n";
            continue;
        }

        if(n < k && m < k) {
            cout << "-1\n";
            continue;
        }

        string s;
        char c = '0';

        if(m > n){
            c = '1';
            swap(m, n);
        }

        //cout << n << ' ' << m << " debug\n";
        //cout << c << " char\n";

        while(n || m){
            int oldn = n;
            for(int i = 0; i < min(k, oldn); i++){
                s.push_back(c);
                n--;
            }
            swap(n, m);
            c = '0' + ('1' - c);
        }
        
        cout << s << '\n';

    }

    return 0;
}
