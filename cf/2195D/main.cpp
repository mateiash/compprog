#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

ll ans[300'005] = {0};
ll inputs[300'005] = {0};
ll calcs[300'005] = {0}; // este -1 -1 -1 ... 11 1 1


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n;
        cin >> n;

        
        for(int i = 1; i <= n; i++){
            cin >> inputs[i];
        }
        inputs[n + 1] = 0;

        ll sum = (inputs[n] + inputs[1])/(n-1); // ultimul + primul (ev)

        for(int i = 2; i <= n; i++){
            calcs[i - 1] = inputs[i - 1] - inputs[i];
        }
        ll diff = (calcs[1] + calcs[n-1])/2; //ultimul - primul 
        
        for(int i = 2; i <= n - 1; i++){
            ans[i] = (calcs[i - 1] - calcs[i])/2;
            sum -= ans[i];
        }

        ans[n] = (sum + diff)/2;
        ans[1] = sum - ans[n];

        for(int i = 1; i <= n; i++){
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
