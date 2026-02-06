#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define ll long long

using namespace std;

typedef pair<int, int> pr;

ifstream fin("tort.in");
ofstream fout("tort.out");

ll sp[200'005];
int posibil[400'005];


int main(){
    int N;
    fin >> N;

    for(int i = 1; i <= N; i++){
        ll el; fin >> el;
        sp[i] = sp[i-1] + el;
    }

    for(int i = N - 1; i >= 1; i--){
        posibil[sp[N] - sp[i]] = 1;
    }

    ll rez = 0;
    for(int i = 1; i <= sp[N]; i++){
        for(int j = i; j <= sp[N]; j += i){
            if(posibil[j]){
                rez++;
            } else {
                break;
            }
        }
    }

    fout << rez << '\n';

    return 0;
}