#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define ll long long

bool inf[100'005];
bool cerinta1[100'005];

typedef pair<int, int> ip;

vector<vector<ip>> adj;
vector<vector<bool>> adjs;

void dfs1(int v, int ind){
    cout << v << ' ' << ind << " entered" << endl;
    for(int i = ind; i >= 0; i--){
        if(adjs[v][i]) break;

        cerinta1[adj[v][i].first] = true;
        dfs1(adj[v][i].first, adj[v][i].second);

        adjs[v][i] = true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N, M;
    cin >> C >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> inf[i];
    }

    adj.resize(N + 1);
    adjs.resize(N + 1);

    vector<ip> chrono;

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;

        chrono.push_back({a, b});

        adj[a].push_back({b, -1});
        adj[b].push_back({a, -1});
        adjs[a].push_back(0);
        adjs[b].push_back(0);

        adj[a].back().second = adj[b].size() - 1;
        adj[b].back().second = adj[a].size() - 1;

    }

    for(int i = 1; i <= N; i++){
        if(inf[i]) continue;

        cerinta1[i] = true;
        queue<ip> q;    
        q.push({i, adj[i].size() - 1});
        while(!q.empty()){
            int v = q.front().first;
            int ind = q.front().second;
            q.pop();
            for(int i = ind; i >= 0; i--){
                if(adjs[v][i]) break;

                cerinta1[adj[v][i].first] = true;
                q.push({adj[v][i].first, adj[v][i].second});

                adjs[v][i] = true;
            }
        }

    }

    if(C == 1){
        for(int i = 1; i <= N; i++){
            cout << 1 - cerinta1[i];
        }
        cout << '\n';
       return 0;
    }

    vector<int> cerinta2(N + 1);
    for(int i = 1; i <= N; i++){
        if(cerinta1[i] == 0){
            cerinta2[i] = i;
        }
    }

    // for(int i = 1; i <= N; i++){
    //     cout << "(";
    //     cout << i;
    //     cout << ")";
    //     cout << cerinta2[i] << ' ';
    // }
    // cout << '\n';

    for(ip p : chrono){
        auto& a = cerinta2[p.first];
        auto& b = cerinta2[p.second];
        if(a == 0 && b == 0) continue;
        if(a == 0 && b != 0) {
            a = b;
            continue;
        }
        if(a != 0 && b == 0) {
            b = a;
            continue;
        }
        if(a != b){
            a = -1; b = -1;
        }
    }

    vector<int> ans(N + 1, 1);
    for(int i = 1; i <= N; i++){
        // cout << "(";
        // cout << i;
        // cout << ")";
        // cout << cerinta2[i] << ' ';
        if(cerinta2[i] > 0){
            ans[cerinta2[i]] = 0;
        }
        /*
        if(cerinta1[i] == 1){
            ans[i] = 1;
        }
            */
    }
    cout << '\n';

    for(int i = 1; i <= N; i++){
        cout << ans[i];
        
    }
    cout << '\n';
    
    return 0;
}