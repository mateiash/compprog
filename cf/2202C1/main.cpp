#include <bits/stdc++.h>
#include <cstddef>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<int> a;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        a.clear();
        ll n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a.push_back(el);
        }
        

        ll treshold = a[0];
        ll size = 1;

        for(int i = 1; i < n; i++){
            if(a[i] - a[i - 1] < 2 && a[i] > treshold){
                continue;
            } else {
                size++;
                treshold = a[i];
            }
        }
        cout /*<< "\nans: " */<< size << '\n';
    }

    return 0;
}
