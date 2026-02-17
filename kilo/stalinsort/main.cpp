#include <bits/stdc++.h>

#define ll long long

using namespace std;

typedef pair<int, int> ip;

ifstream fin("stalinsort.in");
ofstream fout("stalinsort.out");

int elemente[1'000'005];
ll dpsum[1'000'005];

int nextbig[1'000'005];

int main(){
    int n;
    fin >> n;

    for(int i = 1; i <= n; i++){
        fin >> elemente[i];
    }

    dpsum[n] = 1;

    list<int> mstack;
    
    for(int i = 1; i <= n; i++){
        while(!mstack.empty() && elemente[mstack.back()] <= elemente[i]){
            nextbig[mstack.back()] = i;
            mstack.pop_back();
        }
        mstack.push_back(i);
    }

    for(int i = 1; i <= n; i++){
        if(nextbig[i] == 0){
            nextbig[i] = n + 1;
        }

        //cout << nextbig[i] << ' ';
    }

    //cout << '\n';
    
    for(int i = n - 1; i >= 1; i--){
        ip firstgeq;
        //cout << firstgeq.second << '\n';
        firstgeq.second = nextbig[i];
        dpsum[i] = firstgeq.second - i;

        dpsum[i] += dpsum[firstgeq.second] + (n - firstgeq.second + 1);
    }

    for(int i = 1; i <= n; i++){
        fout << dpsum[i] << ' ';
    }
    fout << '\n';
}