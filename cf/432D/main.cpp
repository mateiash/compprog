#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> pi(s.size());
    int j = 0;

    vector<int> freq(s.size());
    for(int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        freq[j]++;
        pi[i] = j;
    }

    vector<int> anses(s.size() + 1);
    
    for(int i = s.size() - 1; i > 0; i--){
        freq[pi[i - 1]] += freq[i];
    }
    
    int cnt = 0;
    for(int i = pi[s.size() - 1]; i > 0; i = pi[i - 1]){
        anses[i] = freq[i];
        cnt++;
    }

    cout << cnt + 1 << '\n';
    for(int i = 1; i <= s.size(); i++){
        if(anses[i]) {
            cout << i << ' ' << anses[i] + 1 << '\n';
        }
    }
    cout << s.size() << " 1\n";

    return 0;
}
