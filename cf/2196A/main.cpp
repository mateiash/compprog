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
        ll p, q;
        cin >> p >> q;

        if(p >= q) {
            cout << "Alice\n";
            continue;
        }

        ll k = q - p;
        ll dif1 = p - 2*k;
        ll dif2 = q - 3*k;
        if(dif1 == dif2 && dif1 >= 0){
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
        

    }

    return 0;
}
