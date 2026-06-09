/*
ID: david25
LANG: C++14
TASK: milk
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

#define ll long long

using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");

typedef pair<ll, ll> ip;

int main(){
    ll N, M;
    fin >> N >> M;

    multiset<ip> fermieri;

    ip f;
    for(int i = 1; i <= M; i++){
        int a, b;
        fin >> a >> b;

        fermieri.insert({a, b});
    }
    ll price = 0;
    while(N > 0){
        ip galeata = *fermieri.begin();
        ll cnt = min(N, galeata.second);
        price += cnt * galeata.first;
        fermieri.erase(fermieri.begin());
        N -= galeata.second;
    }

    fout << price << '\n';

    return 0;
}