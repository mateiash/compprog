#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<string, char> scp;
set<scp> bust;

int k, a;

vector<char> ans;
void euleruleruler(string str, char e){
    for(char c = 'a'; c < 'a' + a; c++){
        if(bust.count({str, c})) continue;
        bust.insert({str, c});
        string nstr = str;
        nstr.erase(0, 1);
        nstr.push_back(c);

        euleruleruler(nstr, c);

    }
    ans.push_back(e);
}


int main(){
    cin >> k >> a;

    if(k == 1){
        for(char c = 'a'; c < 'a' + a; c++){
            cout << c;
        }
        cout << '\n'; return 0;
    }

    string str;
    for(int i = 0; i < k - 1; i++){
        str.push_back('a');
    }

    euleruleruler(str, '*');

    for(int i = 0; i < ans.size(); i++){
        char s = ans[i];
        if(s != '*')
            cout << s;
    } cout << '\n';

    return 0;
}
