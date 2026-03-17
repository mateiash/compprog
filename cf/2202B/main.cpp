#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        string s;
        cin >> s;

        int tota = (s.size() + 1) / 2;
        int totb = (s.size()) / 2;

        if(n % 2){
            if(s[0] == 'b'){
                cout << "NO\n";
                goto finish;
            }
        }

        for(int i = s.size() % 2; i < s.size(); i += 2){
            if(s[i] == '?' || s[i + 1] == '?'){
                continue;
            }

            if(s[i] == s[i + 1]){
                cout << "NO\n";
                goto finish;
            }

        }
        cout << "YES\n";

        finish:
        tota = 0;
    }

    return 0;
}
