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
        int last = 0;
        int opps = 0;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            if(el == 7 - last || el == last){
                opps++;
                last = 0;
            } else {
                last = el;
            }
        }
        cout << opps << '\n';
    }

    return 0;
}
