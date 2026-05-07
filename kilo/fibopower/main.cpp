// tle??
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fin("fibopower.in");
ofstream fout("fibopower.out");

ll A[100'005];
vector<int> fp;
vector<ll> fibo;

bool isfibo(ll n){
    auto it = lower_bound(fibo.begin(), fibo.end(), n);
    if(*it == n) return 1;
    return 0;
}

bool check2prod(ll n, ll banned){
    int div1 = 0;
    while(fibo[div1]*fibo[div1] < n){
        if(n % fibo[div1] == 0 && fibo[div1] != banned){
            if(isfibo(n / fibo[div1]) && n / fibo[div1] != banned){
                return 1;
            }
        }
        div1++;
    }
    return 0;
}

int main(){
    fibo.push_back(1);

    ll toadd = 2;
    while(toadd <= 1'000'000'000){
        fibo.push_back(toadd);
        toadd = toadd + fibo[fibo.size() - 2];
    }

    int n, q, k; fin >> n >> q >> k;
    for(int i = 1; i <= n; i++){
        fin >> A[i];
    }

    for(int i = 1; i <= n; i++){
        int div1 = 0;
        while(fibo[div1]*fibo[div1] <= n){
            if(A[i] % fibo[div1] == 0){
                if(check2prod(A[i] / fibo[div1], fibo[div1])){
                    fp.push_back(i);
                    break;
                }
            }
            div1++;
        }
    }
    
    vector<ll> spbehind;
    int point = 0;

    return 0;
}