#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> ip;

map<ll, ll> elemente;
multiset<ll, greater<ll>> odds;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        elemente.clear();
        odds.clear();
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            int el;
            cin >> el;
            elemente[el]++;
        }

        ll ab[2] = {0};
        int oddind = 0;
        for(auto el : elemente){

            if(el.first % 2){
                odds.insert(el.second);
            }

            ab[0] += el.second * (el.first/2);
            ab[1] += el.second * (el.first/2);

        }

        for(auto el : odds){
            ab[oddind] += el;
            oddind = 1 - oddind;
        }

        cout << ab[0] << ' ' << ab[1] << '\n';

    }

    return 0;
}
