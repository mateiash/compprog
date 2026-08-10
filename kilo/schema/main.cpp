#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("schema.in");
ofstream fout("schema.out");

typedef pair<int, int> ip;

ip dp[5005];
int a[2005];

int main(){

    int N, G;
    fin >> N >> G;

    for(int i = 1; i <= N; i++){
        fin >> a[i];
    }

    for(int i = 0; i < 5005; i++){
        dp[i].second = INT_MAX;
    }
    dp[0] = {1, INT_MAX};

    for(int i = 1; i <= N; i++){
        for(int cost = G; cost >= 0; cost--){
            if(dp[cost].first == 0 && 
                (cost < a[i] || dp[cost - a[i]].first == 0)
            ) continue;

            int replacement = INT_MIN;

            if(dp[cost].first == 1){
                replacement = max(
                    replacement, 
                    min(dp[cost].second, a[i])
                );
            }

            if(cost >= a[i] && dp[cost - a[i]].first == 1){
                replacement = max(replacement,
                    dp[cost - a[i]].second
                );
            }

            dp[cost] = {1, replacement};

        }
    }

    /*
    for(int i = 0; i <= G; i++){
        cout << i << "\n";
        cout << dp[i].first << ' ' << dp[i].second << '\n';
    }
    */

    int i;
    for(i = 0; i <= G; i++){
        if(dp[i].first == 0) continue;
        if(dp[i].second > G - i) break;
    }

    fout << G - i << '\n';

    return 0;
}