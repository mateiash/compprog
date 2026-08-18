#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1'000'000'007

ifstream fin("zid.in");
ofstream fout("zid.out");

int N, M, K;

ll dp[5010][5010][2];
vector<ll> ways(5010);

vector<ll> gateste(vector<ll> a, vector<ll> b){
    vector<ll> r(5010);
    for(int add = 0; add <= K; add++){
        for(int to = 0; to <= K - add; to++){
            r[add + to] += a[to] * b[add];
            r[add + to] %= MOD;
        }
    }
    return r;
}


int main(){
    fin >> N >> M >> K;
    
    // if(M != 1){
    //     fout << ":(\n";
    //     return 0;
    // }

    // pos
    // # galbene

    // 0 : galben
    // 1 : rosu

    dp[1][0][1] = 1;
    dp[2][2][0] = 1;

    for(int i = 0; i <= N; i++){
        for(int cntg = 0; cntg <= K; cntg++){
            dp[i + 2][cntg + 2][0] +=
                2*dp[i][cntg][0] + dp[i][cntg][1];
            dp[i + 2][cntg + 2][0] %= MOD;

            dp[i + 1][cntg][1] +=
                dp[i][cntg][0] + dp[i][cntg][1];
            dp[i + 1][cntg][1] %= MOD;

            dp[i + 2][cntg][1] +=
                dp[i][cntg][1];
            dp[i + 2][cntg][1] %= MOD;  
            
        }
    }

    for(int i = 0; i <= K; i++){
        ways[i] = (dp[N][i][0]
            + dp[N][i][1]) % MOD;
    }

    vector<vector<ll>> ingrediente(13);
    for(auto& v : ingrediente) v.resize(5010);

    ingrediente[0] = ways;
    for(int i = 1; i <= 12; i++){
        ingrediente[i] = gateste(ingrediente[i - 1], ingrediente[i - 1]);
    }
    
    vector<ll> r(5010);
    r[0] = 1;
    int Mcp = M;
    int exp = 0;
    while(Mcp){
        if(Mcp & 1){
            r = gateste(r, ingrediente[exp]);
        }

        Mcp /= 2;
        exp++;
    }

    fout << r[K] << '\n';

    return 0;
}