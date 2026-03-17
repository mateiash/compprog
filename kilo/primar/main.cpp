#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1'000'000'007

typedef pair<ll, ll> ip;

ifstream fin("primar.in");
ofstream fout("primar.out");

int main(){
    int N;
    vector<ip> copaceidr;
    vector<ip> copaceidc;

    fin >> N;

    for(int i = 1; i <= N; i++){
        int r, c; fin >> r >> c;

        copaceidr.push_back({r, c});
        copaceidc.push_back({c, r});
    }

    sort(copaceidr.begin(), copaceidr.end());
    sort(copaceidc.begin(), copaceidc.end());

    ll ans = 0;

    for(auto seed : copaceidr){
        ip invseed = {seed.second, seed.first};
        auto upb = upper_bound(copaceidc.begin(), copaceidc.end(), 
            invseed
        );
        //fout << "seed: " << seed.first << ' ' << seed.second << '\n';
        ip upcopc = {-1*(1<<30), -1};
        ip downcopc = {1<<30, -1};

        for(auto it = upb; it < copaceidc.end(); it++){
            ip procs = *it;
            swap(procs.first, procs.second);

            //fout << "procs: " << procs.first << ' ' << procs.second; //'\n';

            ll w, h;
            if(upcopc.second == -1 || downcopc.second == -1) goto fini;
            if(procs > upcopc && procs < downcopc){
                w = procs.second - seed.second - 1;
                h = downcopc.first - upcopc.first - 1;
                ans += w*h;
                ans%=MOD;
            }
            
            fini:

            if(procs < seed){
                // e limita deasupra
                if(procs > upcopc){ 
                    upcopc = procs;
                    //fout << " set u";
                }
            } else {
                // e limita sub
                if(procs < downcopc) {
                    downcopc = procs;
                    //fout << " set d";
                }
            }
            //fout << '\n';

        }

    }

    fout << ans << '\n';

    return 0;

}