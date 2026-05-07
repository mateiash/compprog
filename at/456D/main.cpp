#include <bits/stdc++.h>

#define ll long long

using namespace std;

#define MOD 998244353

int main(){
    int t;
    //cin >> t;
    t = 1;
    for(int cer = 0; cer < t; cer++){
        string s;
        cin >> s;

        int a[300'005];
        for(int i = 1; i <= s.size(); i++){
            a[i] = s[i - 1] - 'a';
        }
        /*
        for(int i = 1; i <= s.size(); i++){
            cout << a[i];
        } 
        */
        ll dp[26] = {0};

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < 26; j++){
                if(j == a[i]) dp[a[i]]++;
                else {
                    dp[a[i]] += dp[j];
                }
                dp[a[i]] %= MOD;
            }
        }

        ll r = 0;

        for(int i = 0; i < 26; i++){
            r+=dp[i];
            r%= MOD;
        }

        cout << r << '\n';


    }
    
    return 0;
}
