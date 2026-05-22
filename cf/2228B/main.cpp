#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;

        // ll ma_x = max(x1, x2);
        // ll mi_x = min(x1, x2);
        ll dist = min(
            abs(x1 - x2),
            n - abs(x1 - x2)
        );

        if(n == 2 || n == 3){
            cout << "1\n";
            continue;
        }

        /*if(abs(x1 - x2) == 
            n - abs(x1 - x2)){
            //cout << "youre special!\n";
            cout << k + dist << '\n';
        } else { */
            cout << k + dist << '\n';
        //}


    }

    return 0;
}
