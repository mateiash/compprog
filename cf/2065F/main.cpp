#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[500'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<int> adj[n + 1];

        for(int i = 1; i <= n - 1; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        set<int> good;
        for(int i = 1; i <= n; i++){
            set<int> conn;
            conn.insert(a[i]);
            for(auto link : adj[i]){
                if(conn.count(a[link])){
                    good.insert(a[link]);
                } else {
                    conn.insert(a[link]);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(good.count(i)) cout << 1;
            else cout << 0;
        }

        cout << '\n';

    }

    return 0;
}
