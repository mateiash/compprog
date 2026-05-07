#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<bitset<8192>> paths;
vector<bitset<8192>> pathsp;

unordered_map<int, vector<int>> components;

bool compbypaths(const int& a, const int& b){
    return 
        paths[a].count() <
        paths[b].count();
}

typedef pair<int, int> ip;

set<pair<int, int>> links;

void gencomp(int par, vector<int>& children){
    pathsp[par][par-1] = 1;
    sort(children.begin(), children.end(), compbypaths);
    
    vector<ip> upper; upper.push_back({par, 1});

    for(auto child : children){
        pathsp[child][child - 1] = 1;
        int link = -1;
        int depth = -1;
        for(auto up : upper){
            if((paths[up.first] & paths[child]) != paths[up.first]) continue;

            if(up.second > depth){
                depth = up.second;
                link = up.first;
            }

        }

        if(link == -1) continue;
        links.insert({child, link});
        upper.push_back({child, paths[child].count()});
        pathsp[child] = pathsp[child] | pathsp[link];
    }

}

vector<vector<int>> adj;
set<int> connected;

void dfs(int start){
    connected.insert(start);
    for(auto el : adj[start]){
        if(connected.count(el) == 0){
            dfs(el);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        
        paths.clear();
        pathsp.clear();

        components.clear();

        links.clear();

        paths.resize(n + 1);
        pathsp.resize(n + 1);

        adj.clear(); adj.resize(n + 1);
        connected.clear();

        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            reverse(s.begin(), s.end());
            bitset<8192> b{s};
            paths[i] = b;

            int cnt = paths[i].count();
            if(cnt == 1) {
                components[i] = {};
            }
        }

        for(int i = 1; i <= n; i++){
            for(auto el : components){
                if(el.first == i) continue;
                if(paths[i][el.first - 1] == 1){
                    components[el.first].push_back(i);
                }
            }
        }

        //cout << cer + 1 << " Caz\n";
        
        for(auto el : components){
            //cout << el.first << ": doin\n";
            if(el.second.size() == 0) {
                cout << "No\n";
                goto fini;
            }
            gencomp(el.first, el.second);
        }


        for(int i = 1; i <= n; i++){
            if(paths[i] != pathsp[i]){
                cout << "No\n";
                goto fini;
            }
        }

        if(links.size() != n - 1){
            cout << "No\n";
            goto fini;
        }

        for(auto el : links){
            adj[el.first].push_back(el.second);
            adj[el.second].push_back(el.first);
        }

        dfs(1);

        if(connected.size() != n){
            cout << "No\n";
            goto fini;
        }

        cout << "Yes\n";
        for(auto el : links){
            cout << el.first << ' ' << el.second << '\n';
        }

        fini:
        cout << '\n';
        continue;
    }

    return 0;
}
