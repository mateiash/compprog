#include <bits/stdc++.h>

#define ll long long

#define MOD 1'000'000'007

using namespace std;

ifstream fin("leftmax.in");
ofstream fout("leftmax.out");

int elevi[100'005];
int maxst[100'005];
int maxdr[100'005];

typedef pair<int, int> pii;

set<pii> multime;
vector<pii> descos;

ll sigmasum(ll start, ll stop, ll step){
    if(stop < start)
        return 0;
    ll nsteps = (stop - start)/step + 1;
    return nsteps * (start + stop) / 2 % MOD;
}

int main()
{
    int N;
    fin >> N;
    
    for(int i = 1; i <= N; i++){
        fin >> elevi[i];
    }
    elevi[0] = 999'999;
    elevi[N + 1] = 999'999;
    for(int i = 0; i <= N + 1; i++){
        multime.insert({elevi[i], i});
        auto upto = multime.lower_bound({elevi[i], i});
        
        for(auto it = multime.begin(); it != upto; it = next(it)){
            descos.push_back(*it);
        }
        
        for(auto el : descos){
            multime.erase(el);
            maxdr[el.second] =  i - el.second;
        }
        descos.clear();
    }
    multime.clear();
    for(int i = N + 1; i >= 0; i--){
        multime.insert({elevi[i], i});
        auto upto = multime.lower_bound({elevi[i], i});
        
        for(auto it = multime.begin(); it != upto; it = next(it)){
            descos.push_back(*it);
        }
        
        for(auto el : descos){
            multime.erase(el);
            maxst[el.second] = el.second - i;
        }
        descos.clear();
    }
    
    ll rez = 0;
    for(int i = 1; i <= N; i++){
        int n = maxst[i];
        int m = maxdr[i];
        //fout << "index " << i << ' ' << n << ' ' << m << '\n';
        // brut
        ll j = min(
            (m) - 1, 
            (n+m)/2);

        rez += 2*MOD;

        // n + m = 3j
        rez += sigmasum(0, j, 1);
        rez -= sigmasum(0, 
            max(1LL*0,j - n), 
            1);
        rez -= sigmasum(m % 2, 
            max(1LL*0,2*j - (m)), 
            2);
        rez %= MOD;
        j = min(
            m,
            (n+m+1)/2
        );
        rez += 2*MOD;
        // n + m + 1 = 3j
        rez += sigmasum(0, j, 1);
        rez -= sigmasum(0, 
            max(j - n, 1LL*0),
            1);
        rez -= sigmasum((m + 1) % 2, 
            max(1LL*0, 2*j - (m + 1)), 
            2);
        rez %= MOD;

    }
    
    fout << rez << '\n';

    return 0;
}