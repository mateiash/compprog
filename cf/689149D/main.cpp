#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[100'005];
int suffix[31][100'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    //cin >> t;
    t = 1;
    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        int target; cin >> target;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        set<int> needed;
        for(int i = 0; i < 30; i++){
            suffix[i][n + 1] = 0;
            needed.insert(i);
        }

        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 30; j++){
                int bit = (a[i] >> j) & 1;
                suffix[j][i] = suffix[j][i + 1] ^ bit; 
            }
        }
        vector<int> ans(n + 1);
        for(int i = n; i >= 1; i--){
            int goodforor = 1;
            vector<int> eraseable;
            for(int j = 0; j < 30; j++){
                int bit = (a[i] >> j) & 1;
                if(!bit) continue;
                if(needed.count(j) == 0)continue;
                eraseable.push_back(j);
                if( (1 ^ suffix[j][i + 1]) != ((target >> j) & 1) ){
                    goodforor = 0;
                }
            }

            if(!goodforor) continue;

            ans[i] = 1;
            for(auto j : eraseable){
                needed.erase(j);
            }

        }

        for(int i = 1; i <= n; i++){
            if(ans[i] == 1){
                cout << '|';
            } else {
                cout << '^';
            }
        }
        cout << '\n';

    }

    return 0;
}
