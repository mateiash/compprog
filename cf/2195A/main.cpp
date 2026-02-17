#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        int good = 0;
        for(int i = 1; i <= n; i++){
            int what; cin >> what;
            if(what == 67){
                good = 1;
            }
        }
        if(good){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
