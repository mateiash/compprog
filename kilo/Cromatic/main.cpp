#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define MOD 1'000'000'007

ifstream fin("cromatic.in");
ofstream fout("cromatic.out");

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

ll factmod[300'005];
ll invfactmod[300'005];

int a[300'005];
set<int> asorted;

ll nCk(ll n, ll k){
    return (
        factmod[n] * invfactmod[n - k] % MOD *
        invfactmod[k] % MOD
    );
}

int main() {
    ll targetpos = 0;
    factmod[0] = 1;
    
    for(ll i = 1; i <= 300'004; i++){
        factmod[i] = factmod[i - 1] * i % MOD;
    }
    invfactmod[300'004] = 
        fastexp(factmod[300'004], MOD - 2);
    for(ll i = 300'003; i >= 0; i--){
        invfactmod[i] = invfactmod[i + 1] * (i + 1) % MOD;
    }

    int C, N;

    fin >> C >> N;

    if(C == 3) fin >> targetpos;
    //cout << "lool" << endl;
    for(int i = 1; i <= N; i++){
        fin >> a[i];
        if(asorted.count(a[i]) == 0)
            asorted.insert(a[i]);
        else{
            fout << "0\n"; return 0;
        }
    }

    if(C == 1) {
        ll ans = 0;
        for(int i = 0; i < asorted.size(); i++){
            ans += nCk(N - 1, i);
            ans %= MOD;
        }

        fout << ans << '\n';
        return 0;
    }

    if(C == 2){
        ll pos = 0;
        int i = 0;
        for(auto el : asorted){
            if(el == a[1]) break;
            pos += nCk(N - 1, i); 
            i++;
        }

        int lower = i; int higher = N - i - 1;
        cout << pos << " behind\n";
        pos++;
        for(int i = 2; i <= N; i++){
            if(a[i] > a[1]){
                pos += nCk(lower + higher - 1, lower - 1);
                higher--;
            } else {
                lower--;
            }
        }

        fout << pos << '\n';
        return 0;
    }


    sort(a + 1, a + N + 1);
    ll pos = 1;
    ll i = 0;
    ll nCk_prev = 1;
    for(auto el : asorted){
        pos += nCk_prev;

        if(pos > targetpos){
            //cout << pos << " too far!" << endl;
            pos -= nCk_prev;
            //cout << i << " 0 indexed" << endl;
            break;
        }

        //cout << pos << '\n';
        //cout.flush();
        nCk_prev *= (N - 1 - i);
        nCk_prev /= (i + 1);
        i++;
    }


    vector<int> ans;
    ans.push_back(a[i + 1]);

    int lowerind = i + 1 - 1;
    int higherind = i + 1 + 1;

    int lower = i; int higher = N - i - 1;


    for(int i = 2; i <= N; i++){
        pos += nCk(lower + higher - 1, lower - 1);
        if(pos > targetpos){
            pos -= nCk(lower + higher - 1, lower - 1);
            lower--;
            ans.push_back(a[lowerind]);
            lowerind--;
        } else {
            higher--;
            ans.push_back(a[higherind]);
            higherind++;
        }
    }

    for(auto el : ans){
        fout << el << ' ';
    }
    fout << '\n';

    return 0;
}