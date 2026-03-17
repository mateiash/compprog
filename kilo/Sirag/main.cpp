#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1'000'000'007

ifstream fin("sirag.in");
ofstream fout("sirag.out");

int main(){

    int n; 
    fin >> n;

    string s;
    fin >> s;

    ll ans = 0;

    for(int dist = 1; dist <= 26; dist++){
        // dist = cate caractere distincte sunt in subsiruri
        vector<ll> l(n + 1);
        vector<ll> r(n + 1);
        vector<ll> dpsp(n + 1);

        vector<int> freq(26);
        int backpoint = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int c = s[i - 1] - 'a'; 
            if(freq[c] == 0) cnt++;
            freq[c]++;

            while(cnt > dist){
                int cb = s[backpoint - 1] - 'a';
                if(freq[cb] == 1) cnt--;
                freq[cb]--;

                backpoint++;
            }

            if(cnt == dist) l[i] = backpoint;
        
        }

        fill(freq.begin(), freq.end(), 0);
        backpoint = 1;
        cnt = 0;
        for(int i = 1; i <= n; i++){
            int c = s[i - 1] - 'a'; 
            if(freq[c] == 0) cnt++;
            freq[c]++;

            while(cnt > (dist - 1)){
                int cb = s[backpoint - 1] - 'a';
                if(freq[cb] == 1) cnt--;
                freq[cb]--;

                backpoint++;
            }

            if(cnt == (dist - 1)) r[i] = backpoint - 1;
        
        }

        for(int i = 1; i <= n; i++){
            if(l[i] <= 0){
                continue;
            }

            dpsp[i] = 2*MOD + dpsp[r[i] - 1] - dpsp[
                max(l[i] - 2, 0LL)
            ]
            + (r[i] - l[i] + 1)
            + dpsp[i - 1];

            dpsp[i] %= MOD;

            ans += MOD + dpsp[r[i] - 1] - dpsp[
                max(l[i] - 2, 0LL)
            ];
            ans %= MOD;
        }

    }
    fout << ans << '\n';
    return 0;

}