#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

unordered_map<int, vector<int>> numberss;
unordered_map<int, int> counts;

int a[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        numberss.clear();
        counts.clear();

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            numberss[a[i] >> 2].push_back(a[i]);
        }

        for(auto &p : numberss){
            counts[p.first] = 0;
            sort(p.second.begin(), p.second.end());
        }

        for(int i = 1; i <= n; i++){
            cout << numberss[a[i] >> 2][counts[a[i] >> 2]] << ' ';
            counts[a[i] >> 2]++;
        }
        cout << '\n';
    }

    return 0;
}
