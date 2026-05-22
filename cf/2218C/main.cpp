#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;
        cin >> n;
        
        list<ll> stuff;
        for(int i = 1; i <= 3*n; i++){
            stuff.push_back(i);
        }

        while(!stuff.empty()){
            cout << stuff.front() << ' ';
            stuff.pop_front();
            cout << stuff.back() << ' ';
            stuff.pop_back();
            cout << stuff.back() << ' ';
            stuff.pop_back();
            
        }

        cout << '\n';
    }

    return 0;
}
