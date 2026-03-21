// unfinished, crap problem
#include <bits/stdc++.h>

using namespace std;

ifstream fin("dragonfruit.in");
ofstream fout("dragonfruit.out");

int A[2'005];

map<int, int> mincv;

// se verifica impotriva rezultatului din mincv

typedef pair<int, int> ip;

int main(){

    int T; fin >> T;

    for(int cer = 0; cer < T; cer++){
        
        int N, K, S;
        fin >> N >> K >> S;
        /*
        for(int i = 1; i <= N; i++){
            fin >> A[i];
        }

        vector<ip> q;
        for(int i = 1; i <= N; i++){
            q.clear();
            for(auto kvp : mincv){
                q.push_back({kvp.first + A[i], kvp.second + 1});
            }

            for(auto p : q){
                if(mincv[p.first] == 0) mincv[p.first] = p.second;
                else mincv[p.first] = min(p.second, mincv[p.first]);
            }

            mincv[A[i]] = 1;

        }
            */
        /*
        for(auto kvp : mincv){
            fout << kvp.first << ' ' << kvp.second << '\n';
        }
        */
        int cnt = mincv[K];
        mincv.clear();

        // inchis/deschis
        // completate
        // suma
        ip dp[2][11][1005];

        for(int i = 1; i <= N; i++){
            int el = A[i];
            // 0 is closed 1 is open
            // closed choices, open new ones
            for(int seq = 1; seq <= S - 1; seq++){
                for(int csum = 0; csum <= K - el; csum++){
                    if(dp[0][seq][csum].second == 0) continue;
                    
                    ip* comingfrom = &dp[0][seq][csum];
                    ip* goingto = &dp[1][seq+1][csum + el];
                    // making new opens by starting a new one
                    if(
                        (*goingto).second == 0
                    ){
                        *goingto = {
                            (*comingfrom).first + 1,
                            1,
                        };
                    } else {

                        if(
                            (*comingfrom).first + 1 == (*goingto).first
                        ){
                            (*goingto).second++;
                        } else if (
                            (*comingfrom).first + 1 < (*goingto).first
                        ){
                            *goingto = {
                                (*comingfrom).first + 1,
                                1,
                            };
                        }


                    }

                    // making new closed by adding a new subseq with only this element
                    goingto = &dp[0][seq+1][csum + el];

                    if(
                        (*goingto).second == 0
                    ){
                        *goingto = {
                            (*comingfrom).first + 1,
                            1,
                        };
                    } else {

                        if(
                            (*comingfrom).first + 1 == (*goingto).first
                        ){
                            (*goingto).second++;
                        } else if (
                            (*comingfrom).first + 1 < (*goingto).first
                        ){
                            *goingto = {
                                (*comingfrom).first + 1,
                                1,
                            };
                        }


                    }
                    
                }
            }

            // open choices, extending
            for(int seq = 1; seq <= S - 1; seq++){
                for(int csum = 0; csum <= K - el; csum++){
                    if(dp[1][seq][csum].second == 0) continue;
                    
                    ip* comingfrom = &dp[0][seq][csum];
                    ip* goingto = &dp[1][seq+1][csum + el];
                    // making new opens by starting a new one
                    if(
                        (*goingto).second == 0
                    ){
                        *goingto = {
                            (*comingfrom).first + 1,
                            1,
                        };
                    } else {

                        if(
                            (*comingfrom).first + 1 == (*goingto).first
                        ){
                            (*goingto).second++;
                        } else if (
                            (*comingfrom).first + 1 < (*goingto).first
                        ){
                            *goingto = {
                                (*comingfrom).first + 1,
                                1,
                            };
                        }


                    }

                    // making new closed by adding a new subseq with only this element
                    goingto = &dp[0][seq+1][csum + el];

                    if(
                        (*goingto).second == 0
                    ){
                        *goingto = {
                            (*comingfrom).first + 1,
                            1,
                        };
                    } else {

                        if(
                            (*comingfrom).first + 1 == (*goingto).first
                        ){
                            (*goingto).second++;
                        } else if (
                            (*comingfrom).first + 1 < (*goingto).first
                        ){
                            *goingto = {
                                (*comingfrom).first + 1,
                                1,
                            };
                        }


                    }
                    
                }
            }
        }


    }


    return 0;
}