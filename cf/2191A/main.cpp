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
        int bad = 0;

        int inverted = 0;
        int el;
        cin >> el;

        if(el % 2 != 1 % 2){
            inverted = 1;
        }

        for(int i = 2; i <= n; i++){
            int el;
            cin >> el;

            if((el % 2 != i % 2) != inverted){
                bad = 1;
            }
        }

        if(bad){
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
