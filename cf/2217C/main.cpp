#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ull n, m, a, b;
        cin >> n >> m >> a >> b;

        if(gcd(a,n) != 1 || gcd(b, m) != 1){
            cout << "NO\n";
            continue;
        }

        ull alpha = 0;

        ull al1 = lcm(a, n) / a;
        ull al2 = lcm(b, m) / b;
        alpha = lcm(al1, al2);

        //cout << alpha << '\n';
        if(2*alpha < n*m){
            cout << "NO\n";
            continue;    
        }
        cout << "YES\n";
    }

    return 0;
}
