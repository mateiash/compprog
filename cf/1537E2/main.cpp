#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int a[200'005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    //cin >> t;

    t = 1;
    cout << '\n';

    for(int cer = 0; cer < t; cer++){
        int n, k; cin >> n >> k;

        string s; cin >> s;

        string rez;

        rez.push_back(s[0]);

        for(int i = 1; i < s.size(); i++){
            if(s[i] < s[0]){
                rez.push_back(s[i]);
            } else if (s[i] == s[0]) {
                if(i == s.size() - 1) break;
                int j = i + 1;
                while(s[j - i] == s[j] && j < s.size() - 1){
                    j++;
                }
                if(s[j - i] > s[j]){
                    for(int ind = i; ind <= j; ind++){
                        rez.push_back(s[ind]);
                    }
                    i = j;
                } else break;
            } else break;
        }

        
        for(int i = 0; i < k/rez.size(); i++){
            cout << rez;
        }

        for(int i = 0; i < k % rez.size(); i++){
            cout << rez[i];
        }
        cout << '\n';
    }   

    return 0;
}
