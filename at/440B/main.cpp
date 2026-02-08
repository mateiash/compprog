#include <bits/stdc++.h>

#define ll long long

using namespace std;

set<pair<int, int>> times;

int main(){
    int N; cin >> N;

    for(int i = 1; i <= N; i++){
        int t; cin >> t;
        times.insert({t, i});
    }
    auto it = times.begin();
    cout << (*(it++)).second << ' ';
    cout << (*(it++)).second << ' ';
    cout << (*(it++)).second << '\n';

    return 0;
}