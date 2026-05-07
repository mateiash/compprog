#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int ciur[100'005];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ciur[0] = 1;
    ciur[1] = 1;

    for(int i = 2; i <= 100'004; i++){
        if(ciur[i]) continue;

        for(int j = 2*i; j <= 100'004; j+=i){
            ciur[j] = 1;
        }
    }

    vector<int> prime;
    for(int i = 0; i <= 100'004; i++){
        if(!ciur[i]) prime.push_back(i);
    }
    /*
    for(int i = 0; i < 10; i++){
        cout << prime[i] << '\n';
    }
    */
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;
        set<int> deoutput;
        
        for(int i = 1; i <= n; i++){
            deoutput.insert(i);
        }

        int prima = *lower_bound(prime.begin(), prime.end(), n/2);
        
        cout << prima << ' ';
        deoutput.erase(prima);
        int lw = prima - 1;
        int hr = prima + 1;

        while(lw >= 1 && hr <= n){
            cout << lw << ' ' << hr << ' ';
            deoutput.erase(lw); deoutput.erase(hr);
            lw--;
            hr++;
        }

        for(auto el : deoutput) cout << el << ' ';

        cout << '\n';
        
    }

    return 0;
}
