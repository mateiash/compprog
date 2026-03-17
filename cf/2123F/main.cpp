#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

int ciur[100'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i = 2; i < 100'005; i++){
        if(ciur[i]) continue;
        for(int j = 1*i; j < 100'005; j+=i){
            ciur[j] = i;
        }
    }
    
    int t;
    cin >> t;
    
    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        vector<int> ans(n + 5);
        ans[1] = 1;

        vector<int> ind;
        cout << 1 << ' ';

        for(int i = n; i > 1; i--){
            
            if(ans[i]) continue;
            ind.clear();
            for(int j = i; j > 1; j -= ciur[i]){
                if(ans[j]) continue;
                if(ciur[j] != ciur[i]) continue;
                ans[j] = 1;
                ind.push_back(j);
            }
            for(int i = 0; i < ind.size(); i++){
                ans[ind[i]] = ind[
                    (i + 1) % ind.size()
                ];
            }
                
            
        }

        for(int i = 2; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
