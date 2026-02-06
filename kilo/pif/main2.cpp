#include <bits/stdc++.h>
#include <cassert>

#define ll long long
#define MOD 1'234'567

using namespace std;

ifstream fin("pif.in");
ofstream fout("pif.out");

int As[1'000'005];
int AsforAs[1'000'005];
int BsforAs[1'000'005];


int Bs[1'000'005];
int AsforBs[1'000'005];
int BsforBs[1'000'005];

ll done = 0;
ll todo = 0;

int acc(int* arr, int ind){
    if(ind >= 0){
        return arr[ind];
    } 
    return 0;
}

int main(){
    ll n, k, a, b;
    // a sunt cei mai rapizi
    fin >> n >> k >> a >> b;
    // initial a vor fi batranii si b tinerii
    if(b < a){
        swap(a, b);
        As[0]++;
    } else {
        Bs[0]++;
    }

    for(int i = 0; i <= n; i++){
        As[i] += acc(AsforAs, i);
        As[i] += acc(BsforAs, i);

        As[i] %= MOD;

        Bs[i] += acc(AsforBs, i);
        Bs[i] += acc(BsforBs, i);

        Bs[i] %= MOD;

        AsforAs[i + a] = MOD + AsforAs[i] + As[i] - acc(As, i - a*((k+1)/2));
        BsforAs[i + b] = MOD + BsforAs[i] + Bs[i] - acc(Bs, i - b*((k+1)/2));
        
        AsforAs[i + a] %= MOD;
        BsforAs[i + b] %= MOD;
        
        /*
        fout << "index " << i << " " << i - b*((k+1)/2) << '\n';
        fout << acc(Bs, i - b*(k+1)/2) << '\n';
        */
        // o shit
        AsforBs[i + a*((k+1)/2) + a] = MOD + AsforBs[i] + As[i] - acc(As, i - a*((k)/2));
        BsforBs[i + b*((k+1)/2) + b] = MOD + BsforBs[i] + Bs[i] - acc(Bs, i - b*((k)/2));
        
        AsforBs[i + a*((k+1)/2) + a] %= MOD;
        BsforBs[i + b*((k+1)/2) + b] %= MOD;

        todo += max(1LL*0, As[i]*(k - (n - i)/a));
        todo %= MOD;
        todo += max(1LL*0, Bs[i]*(k - (n - i)/b));
        todo %= MOD;
    }
    for(int i = 0; i <= n; i++){
        fout << As[i] << ' ';
    }
    fout << '\n';
    for(int i = 0; i <= n; i++){
        fout << Bs[i] << ' ';
    }
    fout << '\n';
    /*
    fout << "as for as\n";
    for(int i = 0; i <= n; i++){
        fout << AsforAs[i] << ' ';
    }
    fout << '\n';
    fout << "bs for as\n";
    for(int i = 0; i <= n; i++){
        fout << BsforAs[i] << ' ';
    }
    fout << '\n';
    
    fout << "as for bs\n";
    for(int i = 0; i <= n; i++){
        fout << AsforBs[i] << ' ';
    }
    fout << '\n';
    fout << "bs for bs\n";
    for(int i = 0; i <= n; i++){
        fout << BsforBs[i] << ' ';
    }
    fout << '\n';
    */
    fout << todo << '\n';
}