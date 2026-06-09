#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("sushi.in");
ofstream fout("sushi.out");

typedef pair<ll, ll> ip;

ll anses[100'005];

ll segtree[800'005];
ll parcursstarts[200'005];

void build(int node, int l, int r) {
    if (l == r) { segtree[node] = parcursstarts[l]; return; }
    int mid = (l + r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    segtree[node] = min(segtree[2*node], segtree[2*node+1]);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (ql > qr) return 999'999'999'999;
    if (ql <= l && r <= qr) return segtree[node];
    ll mid = (l + r) / 2;
    ll res = 999'999'999'999;
    if (ql <= mid) res = min(res, query(2*node, l, mid, ql, qr));
    if (qr > mid)  res = min(res, query(2*node+1, mid+1, r, ql, qr));
    return res;
}



int main(){
    fill(parcursstarts, parcursstarts + 200'005, 999'999'999'999);

    int N, M;
    fin >> N >> M;

    vector<vector<int>> adj(N + 1);
    set<ip> starts;
    map<ip, int> starttimes;
    for(int i = 1; i <= N; i++){
        int k; fin >> k;

        for(int j = 1; j <= k; j++){
            int el; fin >> el;
            adj[i].push_back(el);
        }
    }

    for(int i = 1; i <= M; i++){
        int x, y, t;
        fin >> x >> y >> t;
        starts.insert({x, y});
        starttimes[{x, y}] = max(
            t, starttimes[{x, y}]);
    }

    vector<ll> parcurs{1, adj[1][0]};

    while(true){
        ll previous = parcurs.back();
        ll prevprevious = *(parcurs.end() - 2);

        ll ind = find(adj[previous].begin(), adj[previous].end(), 
        prevprevious) 
            - adj[previous].begin() + 1;
        ind %= adj[previous].size();

        ll newnode = adj[previous][ind];

        if(previous == parcurs[0] && newnode == parcurs[1]) break;

        //cout << newnode << endl;
        parcurs.push_back(newnode);
        
    }
    vector<vector<int>> ogadj = adj;

    adj.clear();
    adj.resize(N + 1);
    for(int i = 0; i < parcurs.size(); i++){
        adj[parcurs[i]].push_back(i);
    }


    adj.clear();
    adj.resize(N + 1);
    for(int i = 0; i < parcurs.size(); i++){
        adj[parcurs[i]].push_back(i);
    }

    for(int i = 0; i < parcurs.size() - 1; i++){
        int u = parcurs[i], v = parcurs[i + 1];
        int ni = (find(ogadj[u].begin(), ogadj[u].end(), v)
                       - ogadj[u].begin()) + 1;
        if(starttimes.count({u, ni})){
            parcursstarts[i] = i - starttimes[{u, ni}];
        }
    }

    ll L =  parcurs.size();
    build(1, 0, L - 1);

    for(int node = 1; node <= N; node++){
        auto& pos = adj[node]; 
        ll sz = pos.size();
        ll best = 0;

        for(int j = 0; j < sz; j++){
            ll cur = pos[j];
            ll prv = (j == 0) ? pos[sz - 1] : pos[j - 1];

            if(prv < cur){
                ll minval = query(1, 0, L-1, prv+1, cur);
                if(minval < 999'999'999'999)
                    best = max(best, cur - minval);
            } else {
                ll m1 = query(1, 0, L-1, prv+1, L - 1);
                if(m1 < 999'999'999'999)
                    best = max(best, cur + (L-1) - m1);

                ll m2 = query(1, 0, L-1, 0, cur);
                if(m2 < 999'999'999'999)
                    best = max(best, cur - m2);
            }
        }
        anses[node] = best;
    }

    for(int i = 1; i <= N; i++){
        fout << anses[i];
        if(i < N) fout << ' ';
    }
    fout << '\n';
    /*
    for(auto el : parcurs){
        cout << el << ' ';
    }
    cout << '\n';
    */
    return 0;
}