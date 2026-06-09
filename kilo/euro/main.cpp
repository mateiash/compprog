#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("euro.in");
ofstream fout("euro.out");

ofstream dout("debug.out");

typedef pair<int, int> ip;

int a[4005];
bool doable[8005];

int main(){
    int T;
    fin >> T;

    for(int cer = 0; cer < T; cer++){
        int N, Vmax;
        fin >> N >> Vmax;
        
        vector<int> bestans(Vmax + 1);
        vector<int> furtheststart(Vmax + 1);
        
        fill(doable, doable + Vmax + 1, 0);

        for(auto& a : bestans){
            a = -1;
        }

        for(int i = 1; i <= N; i++){
            fin >> a[i];
        }

        sort(a + 1, a + 1 + N);
        /*
        for(int i = 1; i <= N; i++){
            cout << a[i] << ' ';
        } cout << '\n';
        */
        for(int i = 1; i <= N; i++){
            int currel = a[i];
            vector<int> justdropped;

            for(int past = Vmax; past >= 1; past--){
                if(doable[past] == 0) continue;
                if(past + currel > Vmax) continue;
                if(currel - furtheststart[past] < bestans[past + currel] 
                    || bestans[past + currel] == -1)
                    bestans[past + currel] = currel - furtheststart[past];
                //dout << past + currel << " f " << furtheststart[past] << " t " << currel << " i " << i <<'\n';
                //dout << furtheststart[past + currel] << '\n';
                justdropped.push_back(past + currel);
            }

            for(int past = Vmax; past >= 1; past--){
                if(doable[past] == 0) continue;
                if(past + currel > Vmax) continue;
                furtheststart[past + currel] = max(
                    furtheststart[past + currel],
                    furtheststart[past]
                );
            }

            //cout << currel << " spark\n";
            furtheststart[currel] = currel;
            bestans[currel] = 0;
            justdropped.push_back(currel);

            for(auto el : justdropped){
                doable[el] = 1;
            }

        }
        //dout << '\n';
        for(int i = 1; i <= Vmax; i++){
            fout << bestans[i] << ' ';
        }
        fout << '\n';
        
    }


    return 0;
}