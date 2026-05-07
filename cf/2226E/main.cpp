#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define SIZE 200'005

using namespace std;

int fixed[SIZE];
int floating[SIZE];

int lsb(int x) { return x & (-x); }

void update(int pos, int val, int* aib){
    while(pos < SIZE){
        aib[pos] += val;
        pos += lsb(pos);
    }
}

int query(int pos, int* aib){
    int r = 0;
    while(pos){
        r += aib[pos];
        pos -= lsb(pos);
    }
    return r;
}

int cb() { return -1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        int n;
        cin >> n;
        int mex = 0;


        set<int> fixed;
        for(int i = 1; i <= n; i++){
            int el; cin >> el;
        }

    }

    return 0;
}