#include <bits/stdc++.h>
#include <climits>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n, q;
        cin >> n >> q;;

        vector<ll> a;
        for(int i = 0; i < n; i++){
            ll el; cin >> el;
            a.push_back(el);
        }

        ll k = 1;
        for(; k < n; k <<= 1){
            //cout << k << " k\n";
            ll lastmax = INT_MIN;
            ll currmin = INT_MAX;
            ll currmax = INT_MIN;
            
            for(int i = 0; i < n; i++){
                currmax = max(currmax, a[i]);
                currmin = min(currmin, a[i]);
                
                if((i + 1) % k == 0 || i == n - 1){
                    //cout << "lmax " << lastmax;
                    //cout << "cmax " << currmax;
                    //cout << " cmin " << currmin << '\n';
                    if(lastmax > currmin){
                        goto nextk;
                    }
                    lastmax = currmax;
                    currmin = INT_MAX;
                    currmax = INT_MIN;
                }
            }

            break;

            nextk:
            continue;
        }

        cout << k/2 << '\n';

    }

    return 0;
}
