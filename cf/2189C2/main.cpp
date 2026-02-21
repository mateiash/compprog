#include <bits/stdc++.h>
#include <ios>

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
        ull n; cin >> n;
        
        if(__has_single_bit(n)){
            cout << "-1\n";
            continue;
        }
        ull lsb = n & (-n);
        if(n % 2 == 1){
            cout << n - 1 << ' ';
            for(ull i = 2; i <= n - 1; i++){
                cout << (i ^ 1) << ' ';
            }
            cout << 1 << '\n';
        } else {
            cout << lsb + 1 << ' ';
            for(ull i = 2; i <= n - 1; i++){
                if(i == lsb){
                    cout << n << ' ';
                    continue;
                }
                cout << (i ^ 1) << ' ';
            }
            cout << 1 << '\n';
        }


    }

    return 0;
}
