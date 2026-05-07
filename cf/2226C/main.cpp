#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> ip;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        multiset<int> a;
        set<int> aorg;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
            a.insert(el);
            aorg.insert(el);
        }

        int mex = 0;

        while(a.empty() == false){
            if(aorg.count(mex)){
                auto it = a.lower_bound(mex);
                if(it != a.end()) {
                    a.erase(it);
                    mex++; continue;
                }
            }
            auto it = a.upper_bound(2*mex);
            if(it != a.end()){
                a.erase(it);
                mex++;
                continue;
            }
            break;

        }
        
        cout << mex << '\n';

    }

    return 0;
}