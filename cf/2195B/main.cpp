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
        vector<int> seq;

        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            seq.push_back(el);
        }

        int bad = 0;

        for(int i = 1; i <= n; i+=2){
            for(int j = i; j <= n; j*=2){
                if(
                    (seq[j - 1] % i) || 
                    (!std::__has_single_bit((ull)seq[j - 1] / i))
                ){
                    bad = 1;
                }
            }
        }
        
        if(bad){
            cout << "no\n";
        } else {
            cout << "yes\n";
        }

    }

    return 0;
}
