#include <algorithm>
#include <bits/stdc++.h>

#define MOD 1'000'000'007

using namespace std;

ifstream fin("seqstr.in");
ofstream fout("seqstr.out");

typedef pair<int, int> ip;

vector<ip> A;
vector<ip> B;

int c1check(int sb, int fb){
    vector<ip> constructedB;
    ip sp = {sb, -1}; ip ep = {fb, 2};
    auto sit = lower_bound(B.begin(), B.end(), sp);
    auto eit = upper_bound(B.begin(), B.end(), sp);

    for(auto it = sit; it < eit; it++){
        
    }

}

int main(){
    int n, m;

    fin >> n;

    int curr; int currstart = 1;
    fin >> curr;

    for(int i = 2; i <= n; i++){
        int newcurr; fin >> newcurr;
        if(newcurr != curr){
            A.push_back({currstart, curr});
            currstart = i;
        }
        curr = newcurr;
    }

    A.push_back({currstart, curr});
    A.push_back({n+1, 2});

    for(auto el : A){
        cout << el.first << ": " << el.second << '\n';
    }
    cout << '\n';

    return 0;
}