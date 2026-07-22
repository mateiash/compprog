#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int w[200'005];
int tin[200'005];
int tout[200'005];

vector<vector<int>> children;
vector<int> parents;
vector<vector<int>> up;
int n;

int timestamp = 0;
void dfst(int x){
    timestamp++;
    tin[x] = timestamp;
    up[x][0] = parents[x];
    for (int i = 1; i <= ceil(log2(n)); ++i)
        up[x][i] = up[up[x][i-1]][i-1];

    for(auto el : children[x]){
        dfst(el);
    }
    tout[x] = timestamp;
}

bool is_anc(int a, int b){
    if(tin[b] >= tin[a] && tout[b] <= tout[a]) return true;
    return false;
}

int lca(int u, int v)
{
    if (is_anc(u, v))
        return u;
    if (is_anc(v, u))
        return v;
    for (int i = ceil(log2(n)); i >= 0; --i) {
        if (up[u][i] != 0 && !is_anc(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i + 1];
    }
    children.resize(n + 1);
    parents.resize(n + 1);
    up.assign(n + 1, vector<int>(ceil(log2(n))+ 1));
    for(int i = 0; i < n - 1; i++){
        int el; cin >> el;
        parents[i+2] = el;
        children[el].push_back(i+2);
    }
    timestamp = 0;
    dfst(1);
    
    cout << lca(2, 3) << '\n';

    return 0;
}
