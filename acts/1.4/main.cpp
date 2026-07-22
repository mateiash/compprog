#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> ip;
vector<ip> ans;

vector<vector<int>> adjcnt(7);

void euleruleruler(int from, int v){
    for(int i = 0; i <= 6; i++){
        if(adjcnt[v][i]){
            adjcnt[v][i]--;
            adjcnt[i][v]--;
            euleruleruler(v, i);
        }
    }
    ans.push_back({v, from});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(auto& v : adjcnt){
        v.resize(7);
    }

    map<ip, vector<int>> freq;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        freq[{a,b}].push_back(i + 1);
        adjcnt[a][b]++;
        adjcnt[b][a]++;
    }

    int nimp = 0;
    int start = 0;

    for(int i = 0; i <= 6; i++){
        int sum = 0;
        for(auto el : adjcnt[i]){
            sum+=el;
        }
        nimp += sum % 2;
        if(sum % 2) start=i;
        if(nimp == 0 && sum != 0) start=i;

    }

    if(nimp != 0 && nimp != 2) {
        cout << "No solution\n";
        return 0;
    }

    euleruleruler(-1, start);

    if(ans.size() != n + 1){
        cout << "No solution\n";
        return 0;
    }

    cout << '\n';
    for(auto el : ans){
        if(freq[el].size()) {
            cout << freq[el].back() << " +\n";
            freq[el].pop_back();
        } 
        else if(freq[{el.second, el.first}].size()) {
            cout << freq[{el.second, el.first}].back() << " -\n";
            freq[{el.second, el.first}].pop_back();
        }
    }

    return 0;
}
