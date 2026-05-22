#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll sp[200'005];

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        ll n; cin >> n;

        ll special = -1;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            if(abs(el) != 1) special = i;
            sp[i] = sp[i - 1] + el;
        }

        ll firstmax = 0; ll firstmin = 0;
        ll maxc = 0; ll minc = 0;
        for(int i = 1; i < special; i++){
            maxc = max(maxc, sp[i]); minc = min(minc, sp[i]);
            firstmax = max(firstmax, sp[i] - minc);
            firstmin = min(firstmin, sp[i] - maxc);
        }

        ll midmax = -minc;
        ll midmin = -maxc;

        ll lastmax = 0; ll lastmin = 0;
        maxc = sp[special]; minc = sp[special];
        for(int i = special + 1; i <= n; i++){
            maxc = max(maxc, sp[i]); minc = min(minc, sp[i]);
            lastmax = max(lastmax, sp[i] - minc);
            lastmin = min(lastmin, sp[i] - maxc);
        }

        midmax += maxc;
        midmin += minc;

        // cout << firstmin << ' ' << firstmax << "; ";
        // cout << midmin << ' ' << midmax << "; ";
        // cout << lastmin << ' ' << lastmax << "; ";
        // cout << '\n';

        set<ll> ans;
        for(ll i = firstmin ; i <= firstmax; i++){
            ans.insert(i);
        }

        for(ll i = midmin ; i <= midmax; i++){
            ans.insert(i);
        }

        for(ll i = lastmin ; i <= lastmax; i++){
            ans.insert(i);
        }

        cout << ans.size() << '\n';
        for(auto el : ans){
            cout << el << ' ';
        } cout << "\n";

    }

    return 0;
}
