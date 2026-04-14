#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll b, c, d;
        cin >> b >> c >> d;

        ll a = 0;

        for(int i = 0; i <= 61; i++){
            int bitc = (c >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitd = (d >> i) & 1;

            if(bitd){
                if(!bitb && !bitc) a += 1LL << i;
                if(bitb && !bitc) a+=0; //do whatever
                if(!bitb && bitc) {cout << -1 << '\n'; goto finish;}// impossible
                if(bitb && bitc) a+=0;
            } else {
                if(!bitb && !bitc) a+=0;
                if(bitb && !bitc) {cout << -1 << '\n'; goto finish;}
                if(!bitb && bitc) a+=0;
                if(bitb && bitc) a += 1LL << i;
            }

        }
        cout << a << '\n';
        finish:
        b = 0;
    }

    return 0;
}
