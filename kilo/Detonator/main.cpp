#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long

ifstream fin("detonator.in");
ofstream fout("detonator.out");

int piramida[1005][1005];
int necesare[1005][1005];

int main(){
    int t;
    fin >> t;

    for(int cer = 0; cer < t; cer++){
        int N;
        fin >> N;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= i; j++){
                necesare[i][j] = 0;
            }
        }

        for(int i = 1; i <= N; i++){
            necesare[i][1]--;
            necesare[i][i]--;
            for(int j = 1; j <= i; j++){
                fin >> piramida[i][j];
                necesare[i][j] += 2;
            }
        }

        vector<int> tsort((N + 1)*N/2 + 1);

        typedef pair<int, int> ip;
        set<pair<int, ip>> libere;

        libere.insert({piramida[1][1], {1, 1}});

        for(int i = (N + 1)*N/2; i >= 1; i--){
            auto it = --libere.end();
            tsort[i] = it->first;

            ip pos = it->second;
            libere.erase(it);

            necesare[pos.first + 1][pos.second]--;
            necesare[pos.first + 1][pos.second + 1]--;


            if(necesare[pos.first + 1][pos.second] == 0){
                libere.insert(
                    {piramida[pos.first + 1][pos.second], 
                        {pos.first + 1, pos.second}});
            }
            if(necesare[pos.first + 1][pos.second + 1] == 0){
                libere.insert(
                    {piramida[pos.first + 1][pos.second + 1], 
                        {pos.first + 1, pos.second + 1}});
            }
        }

        // for(auto el : tsort){
        //     cout << el << ' ';
        // }
        // cout << '\n';

        int ans = INT_MAX;
        for(int i = 1; i <= (N + 1)*N/2; i++){
            ans = min(ans, tsort[i] - i);
        }
        fout << ans << '\n';

    }

    return 0;
}