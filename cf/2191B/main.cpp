#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        int good = 0;
        int nr0 = 0;
        int nr1 = 0;
        for(int i = 1; i<=n; i++){
            int el;
            cin >> el;
            if(el == 0) nr0++;
            if(el == 1) nr1++;
        }

        if(nr0 == 1) good = 1;
        if(nr0 > 1 && nr1 > 0) good = 1;

        if(good){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
        ;
    }

    return 0;
}
