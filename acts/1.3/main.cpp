#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> ip;

unordered_map<int, vector<int>> adj;
vector<int> ans;

void euleruler(int nod, int cf){
    while(adj[nod].size()){
        int nod2 = adj[nod].back();
        adj[nod].pop_back();
        euleruler(nod2, nod);
    }
    ans.push_back(nod - cf);
}


int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        adj.clear();
        ans.clear();

        vector<ip> v;
        ll sum = 0;

        for(int i = 0; i < n; i++){
            ll a, b; cin >> a >> b;
            v.push_back({a, b});
            sum += a + b;
        }
        sum /= n - 1;

        for(auto& el : v){
            el.second = sum - el.first - el.second;
            adj[el.first].push_back(el.first + el.second);
        }

        euleruler(0, 0);

        for(int i = ans.size() - 2 ; i >= 0; i--){
            cout << ans[i] << ' ';
        }
        cout << '\n';

    }

    return 0;
}
