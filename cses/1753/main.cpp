#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;
    cin >> s;
    string p;
    cin >> p;
    ll searched = p.size();
    p.push_back(' ');
    p.append(s);
    s = p;
    //cout << s << '\n';

    vector<ll> pi(s.length());
    ll j = 0;
    for(int i = 1; i < s.length(); i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    ll ans = 0;    
    for(int i = 0; i < s.length(); i++){
        if(pi[i] == searched) ans++;
    }
    cout << ans << '\n';

    return 0;
}
