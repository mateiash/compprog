#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("xidartros.in");
ofstream fout("xidartros.out");

int main(){

    int t;
    fin >> t;

    for(int cer = 1; cer <= t; cer++){
        //cout << cer << endl;
        int N, B, K;
        fin >> N >> B >> K;

        vector<int> perm(N + 1);
        for(int i = 1; i <= N; i++){
            perm[i] = i;
        }
        
        bool bad = 0;
        vector<int> pasv(N + 1);
        vector<vector<int>> ans(N + 1);
        for(int pas = 0; pas < K; pas++){
            for(int i = 1; i <= N; i++){
                int el; fin >> el;
                pasv[i] = el;
            }

            int last = 0;
            int curdig = 0;
            for(int i = 1; i <= N; i++){
                if(last > perm[pasv[i]]) curdig++;
                if(curdig >= B){
                    //cout << "-1\n\n";
                    bad = 1;
                }

                ans[pasv[i]].push_back(curdig);

                last = perm[pasv[i]];
            }

            for(int i = 1; i <= N; i++){
                perm[pasv[i]] = i;
            }
        }

        if(bad){
            fout << "-1\n";
            goto fini;
        }
        
        //cout << "0\n";
        // fout << "0\n";
        for(int i = 1; i <= N; i++){
            ll loc = 0;
            ll po = 1;
            for(auto d : ans[i]){
                loc += d * po;
                po *= B;
            } // cout << loc << ' ';
            fout << loc << ' ';
        }
        

        //cout << "\n";
        fout << "\n";
        fini:
        continue;
    }

    return 0;
}