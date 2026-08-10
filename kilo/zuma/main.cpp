#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("zuma.in");
ofstream fout("zuma.out");

typedef pair<int, int> ip;

bool secv[505][505];

int main(){

    int N, K;
    fin >> N >> K;

    vector<ip> comp;
    int last = -1;

    for(int i = 1; i <= N; i++){
        char c; fin >> c;
        int curr = c - 'A';

        if(curr == last){
            comp.back().second++;
        } else {
            comp.push_back({curr, 1});
            last = curr;
        }
    }

    int M = comp.size();

    deque<ip> q;
    vector<vector<ll>> secv_v(M + 2);
    vector<vector<ll>> secv_vprime(M + 2);

    for(int i = 1; i <= M; i++){
        auto p = comp[i - 1];
        if(p.second >= K){
            q.push_back({i, 1});
            secv[i][1] = 1;
            secv_v[i].push_back(1);
            secv_vprime[i].push_back(1);
        }
    }

    // cout << "buna" << endl;

    while(!q.empty()){
        auto p = q.front(); 
        q.pop_front();

        // cout << p.first << ' ' << p.second << endl;

        if(p.first != 1 && p.first + p.second != M + 1){
            auto p1 = comp[p.first - 1 - 1];
            auto p2 = comp[p.first + p.second - 1];
            
            if(p1.first == p2.first && p1.second + p2.second >= K){
                ip np = {p.first - 1, p.second + 2};
                
                if(!secv[np.first][np.second] ){
                    q.push_back(np);
                    secv[np.first][np.second] = 1;
                    secv_v[np.first].push_back(np.second);
                    secv_vprime[np.first + np.second - 1].push_back(np.second);
                }

            }
        }

        // cout << "hei" << endl;

        for(auto el : secv_v[p.first + p.second]){
            ip np = {p.first, p.second + el};
                
            if(!secv[np.first][np.second] ){
                q.push_back(np);
                secv[np.first][np.second] = 1;
                secv_v[np.first].push_back(np.second);
                secv_vprime[np.first + np.second - 1].push_back(np.second);
            }
        }

        for(auto el : secv_vprime[p.first - 1]){
            ip np = {p.first - el, p.second + el};
                
            if(!secv[np.first][np.second] ){
                q.push_back(np);
                secv[np.first][np.second] = 1;
                secv_v[np.first].push_back(np.second);
                secv_vprime[np.first + np.second - 1].push_back(np.second);
            }
        }
        // cout << "hei!" << endl;
    }

    // for(int i = 1; i <= M; i++){
    //     cout << i << '\n';
    //     for(auto el : secv_v[i]){
    //         cout << el << ' ';
    //     } cout << '\n';
    // }

    vector<int> sp;
    sp.push_back(0);

    for(auto p : comp){
        sp.push_back(
            sp.back() + p.second
        );
    }

    vector<ll> dprm(M + 2);

    for(int i = 1; i <= M; i++){
        for(auto p : secv_v[i]){
            int ocupate = sp[i + p - 1] - sp[i - 1];
            for(int j = i + p; j <= M + 1; j++){
                dprm[j] = max(dprm[j],
                    dprm[i] + ocupate
                );
            }
        }
    }

    fout << N - dprm[M + 1] << '\n';


    return 0;
}