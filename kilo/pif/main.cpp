#include <bits/stdc++.h>

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
    // iubesc programarea dinamica!!!
    todo = 0;
    for(int i = 0; i <= n; i++){
        As[i] += acc(AsforAs, i);
        As[i] += acc(BsforAs, i);

        As[i] %= MOD;

        Bs[i] += acc(AsforBs, i);
        Bs[i] += acc(BsforBs, i);

        Bs[i] %= MOD;

        AsforAs[i + a] += MOD + AsforAs[i] + As[i] - acc(As, i - a*((k+1)/2));
        BsforAs[i + b] += MOD + BsforAs[i] + Bs[i] - acc(Bs, i - b*((k+1)/2));
        
        AsforAs[i + a] %= MOD;
        BsforAs[i + b] %= MOD;
        
        /*
        fout << "index " << i << " " << i - b*((k+1)/2) << '\n';
        fout << acc(Bs, i - b*(k+1)/2) << '\n';
        */
        // o shit
        AsforBs[i + a*((k+1)/2) + a] += MOD + AsforBs[i + a*((k+1)/2)] + As[i] - acc(As, i - a*((k)/2));
        BsforBs[i + b*((k+1)/2) + b] += MOD + BsforBs[i + b*((k+1)/2)] + Bs[i] - acc(Bs, i - b*((k)/2));
        
        AsforBs[i + a*((k+1)/2) + a] %= MOD;
        BsforBs[i + b*((k+1)/2) + b] %= MOD;

        ll done_a = (n - i) / a;
        ll done_b = (n - i) / b;
        
        if(done_a < k){
            todo = (todo + As[i] * (k - done_a)) % MOD;
        }
        if(done_b < k){
            todo = (todo + Bs[i] * (k - done_b)) % MOD;
        }
    }
    
    fout << todo << '\n';
}