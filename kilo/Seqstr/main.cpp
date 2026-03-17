#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

#define MOD 1'000'000'007
#define ll long long

using namespace std;

ifstream fin("seqstr.in");
ofstream fout("seqstr.out");

string A;
string B;

int c1check(int sb, int fb){
    int Bpoint = sb - 1;
    for(int i = 0; i < A.size(); i++){
        int available = A[i];
        if(available == B[Bpoint]){
            Bpoint++;
        }
        if(Bpoint > fb - 1){
            return 1;
        }
    }

    return 0;

}

int main(){
    int n, m;

    fin >> n;
    for(int i = 1; i <= n; i++){
        char c; fin >> c;
        A.push_back(c);
    }

    fin >> m;
    for(int i = 1; i <= m; i++){
        char c; fin >> c;
        B.push_back(c);
    }

    int C; fin >> C;

    int l = 1; int r = 1;

    ll ans = 0;

    while(l <= m){
        while(
            c1check(l, r + 1) && r < m
        ){
            r++;
        }

        if(c1check(l, r)){
            ans += r - l + 1;
            ans %= MOD;
            cout << l << ' ' << r << '\n';
        }

        l++;
        r = max(l, r);

    }
    
    fout << ans << '\n';

    return 0;
}