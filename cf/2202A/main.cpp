#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll x, y;
        cin >> x >> y;

        if(y > 0){
            x -= y * 2;
        } else {
            x += y * 4;
        }

        if(x < 0){
            cout << "NO\n";
            continue;
        }

        if(x % 3 == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
