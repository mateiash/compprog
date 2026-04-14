#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

int ans[200'005];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int cer = 0; cer < t; cer++){
        ll n, k;
        cin >> n >> k;

        list<ll> ans;
        k--;

        if(n%2) {
            ans.push_back(n);
            n--;
        } else {
            ans.push_back(n);
            if(k % 2) ans.push_back(n - 1);
            else ans.push_front(n - 1);
            n-=2;
            k /= 2;
        }

        for(; n > 0; n-=2){
            int big = n; int small = big - 1;
            if(k % 4 == 0) {
                ans.push_front(big);
                ans.push_front(small);
            }
            if(k % 4 == 1){
                ans.push_back(big);
                ans.push_front(small);
            }
            if(k % 4 == 2){
                ans.push_back(small);
                ans.push_front(big);
            }
            if(k % 4 == 3){
                ans.push_back(big);
                ans.push_back(small);
            }
            k/=4;
        }

        if(k) {
            cout << "-1\n";
            continue;
        }

        for(auto el : ans){
            cout << el << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}
