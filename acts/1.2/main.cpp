#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<multiset<int>> adj;
vector<int> ans;

void euleruleruler(int x){
    while(!adj[x].empty()){
        int to = *adj[x].begin();
        adj[x].erase(adj[x].lower_bound(to));
        adj[to].erase(adj[to].lower_bound(x));
        euleruleruler(to);
    }
    ans.push_back(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    adj.resize(n + 1);

    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int u; cin >> u;
            int len; cin >> len;

            adj[i].insert(u);
        }
    }

    int start = 1;
    int nimp = 0;
    for(int i = 1; i <= n; i++){
        nimp += adj[i].size() % 2;

        if(adj[i].size() % 2) start = i;
    }

    if(nimp != 0 && nimp != 2){
        cout << "-1\n";
        return 0;
    }

    euleruleruler(start);

    cout << ans.size() - 1 << '\n';
    for(auto el : ans){
        cout << el << ' ';
    } cout << '\n';

    return 0;
}
