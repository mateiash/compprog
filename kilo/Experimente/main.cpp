#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("experimente.in");
ofstream fout("experimente.out");

typedef pair<ll , ll> interval;
set<interval> intervale;

int main() {

    ll N, M;
    fin >> N >> M;

    ll soricei = N;
    intervale.insert({0,N-1});

    int lR = 0;

    for(int q = 1; q <= M; q++){

        int S, F; fin >> S >> F;
        S += lR; F += lR;
        
        interval spoint = {S, -1};
        auto its = intervale.lower_bound(spoint);

        vector<interval> torem; vector<interval> toadd;

        if(its != intervale.begin()) its--;
        else its = --intervale.end();

        interval ic = *its;

        while(F > ic.second )

        lR = soricei;
        fout << lR << '\n';

    }

    

    return 0;
}