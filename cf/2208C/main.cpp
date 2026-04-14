#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

long double ca[100'005];
long double pa[100'005];

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> ca[i];
            cin >> pa[i];
        }

        long double score = 0;

        for(int i = n; i >= 1; i--){
            if( score * (1.0 - pa[i]/100.0) + ca[i] > score ){
                score = score * (1 - pa[i]/100) + ca[i];
            }
        }

        cout << fixed << setprecision(10)<< score << '\n';


    }

    return 0;
}
