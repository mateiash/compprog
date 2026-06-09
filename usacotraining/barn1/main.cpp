/*
ID: david25
LANG: C++14
TASK: barn1
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

#define ll long long

using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int main(){

    ll M, S, C;
    fin >> M >> S >> C;

    vector<ll> dat;
    for(int i = 1; i <= C; i++){
        ll oc; fin >> oc;
        dat.push_back(oc);
    }
    sort(dat.begin(), dat.end());

    ll last = *dat.begin();

    multiset<ll> gaps;
    ll length = 1;
    for(int i = 1; i < dat.size(); i++){
        length++;
        M--;
        gaps.insert(dat[i] - last - 1);
        last = dat[i];
    }

    while(M <= 0){
        length+=*gaps.begin();
        gaps.erase(gaps.begin());
        M++;
    }

    fout << length << '\n';

    return 0;
}