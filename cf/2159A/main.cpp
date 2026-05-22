#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n; cin >> n;

        vector<int> ansv(2*n + 1);
        set<int> interogare2;
        set<int> stiyul;
        //int lastans = 0;
        for(int curr = 1; curr <= 2*n; curr++){
            cout << "? ";
            cout << interogare2.size() + 1 << ' ';
            for(auto el : interogare2){
                cout << el << ' ';
            } cout << curr << '\n';
            cout.flush();

            int ans; cin >> ans;
            if(ans != 0){
                ansv[curr] = ans;
                stiyul.insert(curr);
            } else {
                interogare2.insert(curr);
            }
        }

        //interogare2.clear();
        for(int curr = 1; curr <= 2*n; curr++){
            if(ansv[curr]) continue;
            
            cout << "? ";
            cout << stiyul.size() + 1 << ' ';
            for(auto el : stiyul){
                cout << el << ' ';
            } cout << curr << '\n';
            cout.flush();

            int ans; cin >> ans;
            
            ansv[curr] = ans;
        }

        cout << "! ";
        for(int i = 1; i <= 2*n; i++){
            cout << ansv[i] << ' ';
        } cout << '\n';
        cout.flush();
    }

    return 0;
}
