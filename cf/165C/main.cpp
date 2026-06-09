#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll segments[1'000'005];

int main(){
    int t;
    //cin >> t;
    t = 1;
    for(int cer = 0; cer < t; cer++){
        ll k; cin >> k;

        string s;
        cin >> s;
        int i = 1;
        for(char c : s){
            segments[i]++;
            if(c == '1') i++;
        }
        segments[i]++;

        i = 1;
        ll ans = 0;
        if(k == 0){
            while(true){
                if(segments[i + k] == 0) break;
                ans += ((segments[i] - 1) * (segments[i + k]))/2;
                //cout << ((segments[i] - 1) * (segments[i + k]))/2 << ";\n";
                i++;
            }
            cout << ans << '\n';
            continue;
        }        

        i = 1;
        while(true){
            ans += segments[i] * (segments[i + k]);
            //cout << segments[i] * segments[i + k] << ";\n";
            if(segments[i + k] == 0) break;
            i++;
        }

        cout << ans << '\n';
        
    }

    return 0;
}
