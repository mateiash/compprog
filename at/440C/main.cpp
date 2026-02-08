// unfinished
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int cer = 0; cer < t; cer++){
        int N, W;
        cin >> N >> W;
        int C[200'005];
        int resturi[200'005];
        int costmax = 0;
        int cost = 0;
        for(int i = 1; i <= N; i++){
            cin >> C[i];
            resturi[i % (2*W)]+=C[i];
            if(i % (2*W) < W){
                cost+=C[i];
            }
        }
        for(int i = W; i <= 2*W+1; i++){
            cost += resturi[i % (2*W)];
            cost -= resturi[(i - W) % (2*W)];
            costmax = min(costmax, cost);
        }

        cout << costmax << '\n';

    }
    
    return 0;
}
