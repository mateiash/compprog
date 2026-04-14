#include <algorithm>
#include <bits/stdc++.h>

#define MOD 1'000'000'007
#define ll long long

using namespace std;

ifstream fin("seqstr.in");
ofstream fout("seqstr.out");

string A;
string B;

set<string> shit;

int c1check(int sb){
    string s;
    int Bpoint = sb;
    for(int i = 0; i < A.size(); i++){
        int available = A[i];
        if(available == B[Bpoint]){
            s.push_back(B[Bpoint]);
            shit.insert(s);
            Bpoint++;
        }
    }

    return Bpoint-1;

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

    ll ans = 0;

    for(int i = 0; i < B.size(); i++){
        int e = c1check(i);

        ans += e - i + 1;
        cout << i << ' ' << e << '\n';
    }
    
    //fout << ans << '\n';
    fout << shit.size() << '\n';

    return 0;
}