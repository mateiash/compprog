#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

using namespace std;

map<int,int> encounter;
int a[200'005];
int b[200'005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }

        int lasta, lastb;
        lasta = a[n];
        lastb = b[n];

        if(lasta == lastb){
            cout << n << '\n';
            goto done;
        }

        for(int i = n - 1; i >= 1; i--){
            if(a[i] == b[i]){
                cout << i << '\n';
                goto done;
            }
            if(a[i] == lasta || b[i] == lastb){
                cout << i << '\n';
                goto done;
            }
            if(encounter[a[i]] || encounter[b[i]]){
                cout << i << '\n';
                goto done;
            }

            encounter[lasta] = 1;
            encounter[lastb] = 1;

            lasta = a[i];
            lastb = b[i];
        }
        cout << "0\n";
        done:
        encounter.clear();
    }

    return 0;
}
