#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin("experimente.in");
ofstream fout("experimente.out");
ll N, M;
typedef pair<ll,ll> interval;
set<interval> intervale;

bool check(ll q, ll s, ll f) {
    if (s <= f) {
        return s <= q && q <= f;
    } else {
        return q >= s || q <= f;
    }
}

ll intlen(ll s, ll f) {
    if (s <= f) {
        return f - s + 1;
    } else {
        return N - s + f + 1;
    }
}

int main() {
    fin >> N >> M;
    ll soricei = N;
    intervale.insert({0, N-1});
    ll lR = 0;

    for (int q = 1; q <= M; q++) {
        ll A, B;
        fin >> A >> B;
        ll S = (lR + A) % N;
        ll F = (lR + B) % N;

        set<interval> torem, toadd;

        for (auto it = intervale.begin(); it != intervale.end(); ++it) {
            ll s = it->first;
            ll f = it->second;

            bool sinSF = check(s, S, F);
            bool finSF = check(f, S, F);

            if (sinSF && finSF) {
                if (check(S, s, f) && check(F, s, f) && S != F) {
                    torem.insert({s, f});
                    toadd.insert({s, F});
                    toadd.insert({S, f});
                } else {
                    // ok
                }
            } else if (sinSF && !finSF) {
                if( check(F, s, f) ){
                    torem.insert({s, f});
                    toadd.insert({s, F});
                } else {
                    torem.insert({s, f});
                    toadd.insert({S, s});
                }
            } else if (!sinSF && finSF) {
                if(check(S, s, f)){
                    torem.insert({s, f});
                    toadd.insert({S, f});
                } else {
                    torem.insert({s, f});
                    toadd.insert({f, F});
                }
            } else {
                if (check(S, s, f)) {
                    // ok
                } else {
                    torem.insert({s, f});
                }
            }
        }

        for (auto& el : torem) {
            soricei -= intlen(el.first, el.second);
            intervale.erase(el);
        }
        for (auto& el : toadd) {
            soricei += intlen(el.first, el.second);
            intervale.insert(el);
        }

        lR = soricei;
        fout /* << q << ": "*/ << lR << '\n';
        fout.flush();

        cout << "Intervale:\n";
        for(auto el : intervale){
            cout << el.first << ' ' << el.second << '\n';
        }
        cout.flush();


    }
    return 0;
}