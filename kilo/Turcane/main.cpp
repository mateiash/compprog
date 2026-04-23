#include <bits/stdc++.h>
#include <deque>

#define ll long long
#define MOD 1'000'000'007

using namespace std;

typedef pair<ll, ll> ip;

ifstream fin("turcane.in");
ofstream fout("turcane.out");

// pt c1
ll dp[1005][1005];

vector<deque<ip>> rowmin;
vector<deque<ip>> colmin;
vector<deque<ip>> diagmin;

void updms(deque<ip>& dat, ll val, ll pos, ll intlen){
    while(!dat.empty() && dat.back().first > val){
        dat.pop_back();
    }

    while(!dat.empty() && dat.front().second <= pos - intlen){
        dat.pop_front();
    }

    dat.push_back({val, pos});

}

// pt c2
vector<vector<ll>> diagsp;
ll rowssp[1005][1005];
ll colssp[1005][1005];

int main(){
    int C;
    fin >> C;

    int N, M;
    fin >> N >> M;

    rowmin.resize(N + 1);
    colmin.resize(M + 1);
    diagmin.resize(N + M);

    int P, Q, R;
    fin >> P >> Q >> R;

    if(C == 1){
        dp[1][1] = 0;

        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= M; c++){
                int d = c - r + N;
                dp[r][c] = 999'999'999'999'999;
                if(c != 1){
                    ll minbyright = rowmin[r].front().first;
                    dp[r][c] = min(minbyright + 1, dp[r][c]);
                }
                if(r != 1){
                    ll minbydown = colmin[c].front().first;
                    dp[r][c] = min(dp[r][c], minbydown + 1);
                }

                
                if(r != 1 && c != 1){
                    ll minbydiag = diagmin[d].front().first;
                    dp[r][c] = min(dp[r][c], minbydiag + 1);
                }

                if(r - 2 >= 1 && c - 1 >= 1){
                    dp[r][c] = min(dp[r][c], 
                        dp[r - 2][c - 1] + 1
                    );
                }

                if(r - 1 >= 1 && c - 2 >= 1){
                    dp[r][c] = min(dp[r][c], 
                        dp[r - 1][c - 2] + 1
                    );
                }
                
                if(r == 1 && c == 1) dp[r][c] = 0;
                updms(rowmin[r], dp[r][c], c, P);
                updms(colmin[c], dp[r][c], r, Q);
                updms(diagmin[d], dp[r][c], r, R);
            }
        }

        fout << dp[N][M] << '\n';

        return 0;
    }
    
    
    diagsp.resize(N + M);
    for(int i = 0; i < N + M; i++){
        diagsp[i].push_back(0);
    }
    dp[1][1] = 1;
    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            int d = c - r + N;
            dp[r][c] = 0;
            //cout << r << ' ' << c << endl;
            if(c != 1){
                ll sumbyright = rowssp[r][c - 1] - rowssp[r][max(
                    c - 1 - P,
                    0
                )];
                dp[r][c] += sumbyright;
                //cout << sumbyright << "right\n";
                dp[r][c] %= MOD;
            }

            
            if(r != 1){
                ll sumbydown = colssp[r - 1][c] - colssp[max(
                    r - 1 - Q,
                    0
                )][c];
                //cout << sumbydown << "down\n";
                dp[r][c] += sumbydown;
                dp[r][c] %= MOD;
            }
            
            
            if(r != 1 && c != 1){
                ll sumbydiag = MOD + diagsp[d][diagsp[d].size() - 1] - diagsp[d][max(
                    (ll)diagsp[d].size() - 1 - R,
                    0LL
                )];
                //cout << sumbydiag << "diag\n";
                //cout << diagsp[d][diagsp[d].size() - 1] << '\n';
                dp[r][c] += sumbydiag;
                dp[r][c] %= MOD;
            }
            

            if(r - 2 >= 1 && c - 1 >= 1){
                dp[r][c] +=
                    dp[r - 2][c - 1];
                dp[r][c] %= MOD;   
            }

            if(r - 1 >= 1 && c - 2 >= 1){
                dp[r][c] +=
                    dp[r - 1][c - 2];
                dp[r][c] %= MOD;   
            }
            
            if(r == 1 && c == 1) dp[r][c] = 1;
            rowssp[r][c] = (rowssp[r][c - 1] + dp[r][c]) % MOD;
            colssp[r][c] = (colssp[r - 1][c] + dp[r][c]) % MOD;
            diagsp[d].push_back(
                (diagsp[d].back() + 
                dp[r][c]) % MOD
            );
            //fout << dp[r][c] << ' ';
        }
        //fout << '\n';
    }
    

    fout << dp[N][M] << '\n';


    return 0;
}