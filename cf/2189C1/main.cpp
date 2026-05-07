#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        if(n % 2)
            cout << n - 1 << ' ';
        else
            cout << n << ' ';
        for(int i = 2; i < n; i++){
            cout << (i ^ 1) << ' ';
        }
        cout << 1 << '\n';

    }

    return 0;
}
