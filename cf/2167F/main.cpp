#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<vector<int>> adi;


int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n, k;
        cin >> n;
        adi.clear();
        adi.resize(n+5);
        for(int i = 1; i <= n; i++){
            int a, b; cin >> a >> b;
            adi[a].push_back(b);
            adi[b].push_back(a);
        }

        
        
    }

    return 0;
}
