//https://codeforces.com/contest/2203/problem/D
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int ciur[2'000'005];
int steaguri[2'000'005];

int a[1'000'005];
int b[1'000'005];

int n, m;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            steaguri[ a[i] ] += 1;
        }
        for(int i = 1; i <= m; i++){
            cin >> b[i];
        }

        
        for(int i = 1; i <= m + n; i++){
            if(steaguri[i] == 0) continue;

            for(int j = i; j <= n + m; j+=i){
                ciur[j] += steaguri[i];
            }
            
        }

        int alice = 0; int bob = 0; int both = 0;
        for(int i = 1; i <= m; i++){
            if(ciur[b[i]] == n) alice++;
            else if(ciur[b[i]] == 0) bob++;
            else both++;
        }
        //cout << alice << ' ' << bob << ' ' << both << '\n';
        alice += (both + 1)/2;
        bob += both/2;

        //cout <<'\n' <<alice << ' ' << bob << '\n';
        if(bob < alice) cout << "Alice\n";
        else cout << "Bob\n";      
        for(int i = 1; i <= n + m; i++) {
            ciur[i] = 0;
            steaguri[i] = 0;
        }
    }

    return 0;
}
