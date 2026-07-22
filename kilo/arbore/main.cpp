#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define MOD 1'000'000'007

using namespace std;

ifstream fin("arbore.in");
ofstream fout("arbore.out");

int dpincl[100'005];
int dpexcl[100'005];

ll moduriincl[100'005];
ll moduriexcl[100'005];

vector<vector<int>> adj;

void dfs(int node, int parent){
    if(adj[node].size() == 1){
        dpincl[node] = 1;
        dpexcl[node] = 0;
        moduriincl[node] = 1;
        moduriexcl[node] = 1;
        return; 
    }
    int sumexcl = 0;
    int sumwhatevers = 0;

    ll modfincl = 1;
    ll modfexcl = 1;

    for(auto link : adj[node]){
        if(link == parent) continue;
        dfs(link, node);
        sumexcl += dpexcl[link];
        ll inmul = 0;
        if(dpexcl[link] >= dpincl[link] - 1){
            inmul += moduriexcl[link];
        }
        if(dpincl[link] - 1 >= dpexcl[link]){
            inmul += moduriincl[link];
        }
        modfincl = (modfincl * inmul) % MOD;

        sumwhatevers +=
            max(dpexcl[link], dpincl[link]);
        inmul = 0;
        if(dpexcl[link] >= dpincl[link]){
            inmul += moduriexcl[link];
        }
        if(dpincl[link] >= dpexcl[link]){
            inmul += moduriincl[link];
        }
        modfexcl = (modfexcl * inmul) % MOD;

    }
    dpincl[node] = sumexcl + 1;
    dpexcl[node] = sumwhatevers;

    moduriincl[node] = modfincl;
    moduriexcl[node] = modfexcl;
}


int main(){
    int N; fin >> N;

    adj.resize(N + 1);

    for(int i = 1; i <= N - 1; i++){
       int a, b;
       fin >> a >> b;
       
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    adj[1].push_back(-1);

    dfs(1, -1);
    /*
    for(int i = 1; i <= N; i++){
        cout << i << '\n';
        cout << dpincl[i] << ' ' << dpexcl[i] << '\n';
        cout << moduriincl[i] << ' ' << moduriexcl[i] << '\n';
    }
    */
    fout << max(dpincl[1], dpexcl[1]) << ' ';// << 0 << '\n';
    
    ll moduddududri = 0;
    if(dpexcl[1] == max(dpincl[1], dpexcl[1])) moduddududri+=moduriexcl[1]; 
    if(dpincl[1] == max(dpincl[1], dpexcl[1])) moduddududri+=moduriincl[1]; 
    
    fout << moduddududri << '\n';

    return 0;
}
