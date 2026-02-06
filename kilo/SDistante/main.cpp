#include <bits/stdc++.h>

#define MOD 1'000'000'007
#define inv2 500'000'004

#define ull unsigned long long
#define ll long long 

using namespace std;

ifstream fin("sdistante.in");
ofstream fout("sdistante.out");

int mapC(char c){
    if('a' <= c && c <= 'z')
        return c - 'a';
    
    return c - 'A' + 26;

}

ll freq[2*26];

int main(){
    ll rez = 0;

    char c;
    ll n = 0;
    ll lastadd = 0;
    while(fin >> c){
        int code = mapC(c);
        ll adder = MOD + (lastadd + n*(n+1) % MOD * (1LL*inv2) % MOD ) % MOD - freq[code];
        adder = adder % MOD;
        lastadd = adder;

        rez += adder;
        rez = rez % MOD;
        
        n++;
        freq[code] += n;
        freq[code] = freq[code] % MOD;
        
    }

    fout << rez << '\n';

    return 0;
}