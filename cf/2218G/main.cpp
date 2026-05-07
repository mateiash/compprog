#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

#define MOD 676767677

using namespace std;

int b[200'005];
int eliberat[200'005];
map<int, vector<int>> bsort;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        bsort.clear();
        int n, m;
        cin >> n >> m;

        fill(eliberat + 1, eliberat + n + 1, -1);

        for(int i = 1; i <= n; i++){
            cin >> b[i];
            bsort[b[i]].push_back(i);
        }
        /*
        for(int i = 0; i <= m; i++){
            cout << i << ": ";
            for(auto el : bsort[i]){
                cout << el << ' ';
            }
            cout << '\n';
        }
        */
        ll ans = 1;
        ll lastliberated = 0;
        ll liberated = 0;
        for(auto& el : bsort){
            int currtime = el.first;
            if(currtime == 0) goto fini;
            for(auto asezat : el.second){
                if(eliberat[asezat] == currtime - 1){
                    ans *= liberated; ans %= MOD;
                } 
                else if(eliberat[asezat] == -1){
                    ans *= 0;
                }
                else {
                    ans *= liberated - lastliberated;
                    ans %= MOD;
                }
            }


            fini:
            for(auto pers : el.second){
                if(eliberat[pers + 1] == -1) eliberat[pers + 1] = el.first;
                if(eliberat[pers - 1] == -1) eliberat[pers - 1] = el.first;
            }
            lastliberated = liberated;
            liberated += el.second.size();
        }
        cout /*<< "here: "*/ << ans << '\n';
        /*
        for(int i = 1; i <= n; i++){
            cout << eliberat[i] << ' ';
        }
        cout << "\n\n";
        */
    }

    return 0;
}
