#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<int> betweens;

int main() {
    int t; cin >> t;

    for(int cer = 0; cer < t; cer++){
        betweens.clear();
        int n, l, r;
        cin >> n >> l >> r;

        ll constant = 0;
        ll ps = 0;
        
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            if(el <= l){
                constant -= el;
                ps++;
            } else if(el >= r){
                constant+=el;
                ps--;
            }else {
                betweens.push_back(el);
            }
        }

        sort(betweens.begin(), betweens.end());
        
        for(int i = 0; i < betweens.size() / 2; i++){
            constant -= betweens[i];
        }

        for(int i = (betweens.size() + 1) / 2; i < betweens.size(); i++){
            constant += betweens[i];
        }

        cout << constant << ' ' << ps << '\n';

    }

    return 0;
}