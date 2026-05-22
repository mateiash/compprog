#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int nexts[1'000'005];
int leftat[26];
int crossed[1'000'005];
int preproc[1'000'005];

int nextc[26][1'000'005];
int firstc[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    fill(firstc, firstc + 26, -1);

    for(int i = 0; i < n; i++){
        int c = s[i] - 'a';
        if(firstc[c] == -1){
            firstc[c] = i;
        }
        for(int j = leftat[c]; j < i; j++){
            nexts[j] = i;
            crossed[j]++;
            nextc[c][j] = i;
        }
        leftat[c] = i;
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(crossed[i] != k){
            preproc[i] = 1;
        } else {
            preproc[i] = preproc[nexts[i]] + 1;
        }
    }

    int q; cin >> q;

    for(int i = 0; i < q; i++){
        string qs; cin >> qs;

        int point = 0;
        int querypoint = 0;
        
        if(firstc[qs[0] - 'a'] == -1) {
            cout << "0\n";
            continue;
        }
        querypoint = 1;
        point = firstc[qs[0] - 'a'];

        while(querypoint < qs.size()){
            if(nextc[qs[querypoint] - 'a'][point] == 0){
                cout << "0\n";
                goto fini;
            } else {
                point = nextc[qs[querypoint] - 'a'][point];
                querypoint++;
            }
        }

        if(point == s.size()){
            cout << "0\n";
            continue;
        }

        cout << preproc[point] << '\n';
        fini:
        continue;
    }

    return 0;
}
