#include <bits/stdc++.h>
#include <numeric>

#define ll long long
#define ull unsigned long long

using namespace std;

multiset<ll> choices;
ll d[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n, k;
        cin >> n >> k;
    

        for(int i = 1; i <= n; i++){
            ll el; cin >> el;
            d[i] = el;
        }
        choices.clear();
        //ll ans = 0;

        for(int i = n; i > 0; i--){
            int rem = n - i + 1;
            if(rem / (k + 1) > (rem - 1) / (k + 1)){
                choices.insert(d[i]);
            } else if (!choices.empty()){
                if(d[i] > *choices.begin()){
                    choices.erase(choices.begin());
                    choices.insert(d[i]);
                }
            }
        }

        cout << accumulate(choices.begin(), choices.end(), 0LL) << "\n\n";
        

    }

    return 0;
}
