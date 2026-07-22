#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int h[50'005];

vector<vector<int>> adj;
vector<int> tin;
vector<int> tout;
vector<int> sizes;
vector<vector<int>> up;
vector<int> depth;

int timer = 0;

vector<int> pathid;
vector<int> pathpos;
vector<int> pathleader(1);

int unusedpath = 1;

vector<vector<int>> arrays(1);
vector<vector<int>> segtrees(1);

int n;

void dfss(int v, int p){
    int sum = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfss(u, v);
        sum += sizes[u];
    }
    for(int i = 0; i < adj[v].size(); i++){
        //if(adj[v][i] == p) continue;
        if(sizes[adj[v][i]] > sizes[adj[v][0]]){
            swap(adj[v][0], adj[v][i]);
            //cout << v << "extend from" << adj[v][0] << '\n';
       }
    }
    sizes[v] = sum;
    if(adj[v].size() <= 1){
        pathid[v] = unusedpath;
        unusedpath++;
        arrays.push_back({h[v]});
        pathleader.push_back(v);
        pathpos[v] = 1;
        return;
    }

    pathpos[v] = pathpos[adj[v][0]] + 1;
    pathid[v] = pathid[adj[v][0]];
    pathleader[pathid[v]] = (v);
    arrays[pathid[v]].push_back(h[v]);

}

void dfst(int v, int p){
    timer++;
    tin[v] = timer;
    up[v][0] = p;
    if(p == -1){
        up[v][0] = v;
    }
    if(p == -1){
        depth[v] = 0;
    } else 
        depth[v] = depth[p] + 1;
    for (int i = 1; i <= ceil(log2(n)); ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for(auto u : adj[v]){
        if(u == p) continue;
        dfst(u, v);
    }
    tout[v] = timer;

}

void build(vector<int> &a, vector<int>& t, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, t, v*2, tl, tm);
        build(a, t, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
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

int query(int v, vector<int>& t, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(v*2, t, tl, tm, l, min(r, tm)),
           query(v*2+1, t, tm+1, tr, max(l, tm+1), r));
}

void update(int v, vector<int>& t, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, t, tl, tm, pos, new_val);
        else
            update(v*2+1, t, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void hld_update(int v, int newval){
    h[v] = newval;
    int pid = pathid[v];
    int idx = pathpos[v] - 1;
    update(1, segtrees[pid], 0, (int)arrays[pid].size() - 1, idx, newval);
}

int hld_query(int u, int v){
    int res = 0; 

    while(pathid[u] != pathid[v]){
        int headU = pathleader[pathid[u]];
        int headV = pathleader[pathid[v]];

        if(depth[headU] < depth[headV]){
            swap(u, v);
            swap(headU, headV);
        }

        int pid = pathid[u];
        int l = pathpos[u] - 1;
        int r = pathpos[headU] - 1;
        res = max(res, query(1, segtrees[pid], 0, (int)arrays[pid].size() - 1, l, r));

        u = up[headU][0]; 
    }

    if(pathpos[u] > pathpos[v]) swap(u, v);
    int pid = pathid[u];
    int l = pathpos[u] - 1;
    int r = pathpos[v] - 1;
    res = max(res, query(1, segtrees[pid], 0, (int)arrays[pid].size() - 1, l, r));

    return res;
}

int main(){
    cin >> n;

    up.assign(n + 1, vector<int>(ceil(log2(n))+ 1));

    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    tin.resize(n + 1);
    tout.resize(n + 1);
    sizes.resize(n + 1);
    adj.resize(n + 1);
    pathid.resize(n + 1);
    pathpos.resize(n + 1);
    depth.resize(n + 1);

    for(int i = 1; i <= n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfst(1, -1);
    dfss(1, -1);

    /*
    for(int i = 1; i <= n; i++){
        cout << pathid[i] << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << pathpos[i] << ' ';
    }
    cout << '\n';
    for(int i = 1; i < unusedpath; i++){
        cout << pathleader[i] << ' ';
    }
    cout << '\n';
    */
    for(int i = 1; i < arrays.size(); i++){
        segtrees.push_back({});
        segtrees[i].resize(4*arrays[i].size());
        build(arrays[i], segtrees[i], 1, 0, arrays[i].size() - 1);
    }

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        char c; cin >> c;
        if(c == '!'){
            int v, nv;
            cin >> v >> nv;
            hld_update(v, nv);
            continue;
        }

        int v, u; cin >> v >> u;
        cout << hld_query(v,  u) << '\n';
    }

    return 0;
}
