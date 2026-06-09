#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("sushi.in");
ofstream fout("sushi.out");

typedef pair<ll, ll> ip;

ip anses[100'005];

int main(){

    int N, M;
    fin >> N >> M;

    set<ip> present;
    map<ip, int> starts;

    vector<vector<int>> adj(N + 1);
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

        present.insert({x, adj[x][y-1]});
        starts[{x, y}] = max(starts[{x, y}], t);
    }

    ll timestamp = 1;
    ip mone = {-1, -1};
    fill(anses, anses + N + 1, mone);

    set<ip> onhold;
    multiset<ll> choseformax;
    
    choseformax.insert(-starts[*present.begin()]);
    onhold.insert(*present.begin());
    present.erase(present.begin());

    map<ip, ll> inchosingset;
    inchosingset[*onhold.begin()] = *choseformax.begin(); 
    anses[onhold.begin()->first] = {-*choseformax.begin(), *choseformax.begin()};
    anses[onhold.begin()->second] = {1 -*choseformax.begin(), *choseformax.begin()};

    vector<ll> parcurs{onhold.begin()->first, onhold.begin()->second};

    while(!onhold.empty()){
        timestamp++;

        ll previous = parcurs.back();
        ll prevprevious = *(parcurs.end() - 2);

        ll ind = find(adj[previous].begin(), adj[previous].end(), 
        prevprevious) 
            - adj[previous].begin() + 1;
        ind %= adj[previous].size();

        ll newnode = adj[previous][ind];

        if(onhold.count({previous, newnode})){
            onhold.erase({previous, newnode});
            choseformax.erase(
                choseformax.lower_bound(inchosingset[{previous, newnode}])
            );
        }

        if(present.count({previous, newnode})){
            auto it = present.lower_bound({previous, newnode});
            choseformax.insert(timestamp - 1 - starts[*it]);
            onhold.insert(*it);
            inchosingset[*it] = timestamp - 1 - starts[*it]; 
            present.erase(it);
        }

        if(!choseformax.empty()){
            if(*choseformax.begin() != anses[previous].second){
                anses[previous].first = max(anses[previous].first, timestamp - 1 - *choseformax.begin());
                anses[previous].second = *choseformax.begin();
                cout << previous << " upd " << anses[previous].first << '\n';
            }
        }

        cout << newnode << endl;
        parcurs.push_back(newnode);
        
    }

    for(int i = 1; i <= N; i++){
        cout << anses[i].first << ' ';
    }
    cout << endl;

    return 0;
}