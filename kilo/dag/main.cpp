#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1'000'000'007

ifstream fin("dag.in");
ofstream fout("dag.out");

ll fastexp(ll a, ll e){
    ll r = 1;
    while(e){
        if(e & 1){
            r = r * a % MOD;
        }

        a = a * a % MOD;

        e >>= 1;
    }
    return r;
}



int main(){
    int n; fin >> n;

    int perm[200'005];

    for(int i = 1; i <= n; i++){
        fin >> perm[i];
    }

    int igbro[200'005];
    fill(igbro + 1, igbro + n + 1, -1);
    stack<int> ms;
    
    for(int i = n; i > 0; i--){
        while(!ms.empty() && perm[ms.top()] < perm[i]){
            igbro[ms.top()] = i;
            ms.pop();
        }
        ms.push(i);
    }

    /*
    for(int i = 1; i <= n; i++){
        fout << igbro[i] << ' ';
    }

    fout << '\n';
    */

    ll ans = 1;

    for(int i = 1; i <= n; i++){
        if(igbro[i] == -1){
            ans = ans * 
                fastexp(2, i - 1) % MOD;
            continue;
        }

        ans = ans * fastexp(2, igbro[i] - 1) % MOD;
        ans = ans * (fastexp(2, i - igbro[i]) - 1) % MOD;
    }

    fout << ans << '\n';

    return 0;
}