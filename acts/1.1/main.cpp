#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<bool> marked;
deque<int> inorder;

vector<vector<int>> edges;

int timestamp = 0;

void dfs(int x){
    marked[x] = true;
    timestamp++;
    for(auto el : edges[x]){
        if(marked[el]) continue;
        dfs(el);
    }
    timestamp++;
    inorder.push_back(x);
}

bool adjmat[2005][2005];

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> nume;
    vector<string> numev;

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        numev.push_back(str);
        nume[str] = i;
    }

    edges.resize(2*n);
    marked.resize(2*n);
    for(int i = 0; i < m; i++){
        bool negated1 = false, negated2 = false;
        int v1, v2;
        char c; 
        cin >> c;
        if(c == '-') negated1 = true;
        
        string str;
        cin >> str;
        v1 = nume[str];

        for(int j = 0; j < 2; j++){
            cin >> c;
        }

        cin >> c;
        if(c == '-') negated2 = true;

        str.clear();
        cin >> str;
        v2 = nume[str];

        negated1 ^= 1;

        edges[(v1 << 1) + 1^negated1].push_back((v2 << 1) + negated2);
        adjmat[(v1 << 1) + 1^negated1][(v2 << 1) + negated2] = 1;
        edges[(v2 << 1) + 1^negated2].push_back((v1 << 1) + negated1);
        adjmat[(v2 << 1) + 1^negated2][(v1 << 1) + negated1] = 1;


    }
    /*
    cout << "edges\n";
    for(int i = 0; i < edges.size(); i++){
        cout << i << ": ";
        for(auto el : edges[i]){
            cout << el << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
    */

    for(int i = 0; i < 2*n; i++){
        if(marked[i]) continue;
        dfs(i);
    }

    vector<int> components(2*n);
    
    /*
    cout << "dfs:\n";
    for(auto el : inorder){
        cout << el << ' ';
    }
    */

    int component = 1;
    while(!inorder.empty()){
        int on = inorder.back();
        components[on] = component;
        inorder.pop_back();
        if(inorder.empty())continue;
        if(!adjmat[inorder.back()][on]){
            component++;
        }
    }
    /*
    cout << '\n';
    for(auto el : components){
        cout << el << ' ';
    }
    cout << '\n';
    */
    vector<bool> ans(n);
    int summm = 0;
    for(int i = 0; i < n; i++){
        if(components[(i<<1)] > components[(i<<1) + 1]){
            ans[i] = 1;
        } else if (components[(i<<1)] < components[(i<<1) + 1]){
            ans[i] = 0;
        } else {
            cout << "-1\n";
            return 0;
        }
        summm += ans[i];
    }
    cout << summm << '\n';
    for(int i = 0; i < n; i++){
        if(ans[i]){
            cout << numev[i] << '\n';
        }
    }

    return 0;
}
