/*
ID: david25
LANG: C++14
TASK: crypt1
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

#define ll long long

using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

bool digits[16];

bool isgood(int n){
    bool r = 1;
    while(n){
        r = r && digits[n % 10];
        n /= 10;
    }
    return r;
}

int main(){

    ll N; fin >> N;

    vector<int> digitsv;
    for(int i = 1; i <= N; i ++){
        int el;
        fin >> el;
        digitsv.push_back(el);
        digits[el] = 1;
    }
    sort(digitsv.begin(), digitsv.end());

    ll ans = 0;
    for(int i = 0; i < pow(N, 3); i++){
        int first = 
            digitsv[i % N] + 
            digitsv[i / N % N]*10 + 
            digitsv[i / N / N % N]*100;
        for(int s1 : digitsv){
            for(int s2 : digitsv){
                if(!isgood(s1 * first) || s1 * first > 999) continue;;
                if(!isgood(s2 * first) || s2 * first > 999) continue;
                if(!isgood((s1*10 + s2) * first) || (s1*10 + s2) * first > 9999) continue;

                ans++;
            }
        }

        fini:
        continue;
    }

    fout << ans << '\n';

    return 0;
}