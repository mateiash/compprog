#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ip;

#define MOD 1'000'000'007
#define ll long long

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r = (r*a) % MOD;
        }
        a = a * a % MOD;
        e >>= 1;
    }  
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        string s; cin >> s;
        
        ll ones = 0;
        for(char c : s){
            if(c == '1') ones++;
        }

        ll plus1 = 
        

    }
    return 0;
}