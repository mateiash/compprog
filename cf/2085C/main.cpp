#include <bits/stdc++.h>
#include <type_traits>

#define ll long long
#define ull unsigned long long

#define MAXK 1'000'000'000'000'000'000

using namespace std;

int logopogo(ull n){
    int r = 0;
    while(n){
        r++;
        n >>= 1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ull x, y;
        cin >> x >> y;

        if(x == y){
            cout << "-1\n"; continue;
        }

        ull mic = min(x, y);
        ull mare = max(x, y);
        ull diff = mare - mic;
        
        ull target = 1 << logopogo(mare);


        ull k = target - mare;
        


        cout << k << '\n';
    }

    return 0;
}
