#include <bits/stdc++.h>

#define ll long long

#define inp fin
#define outp fout

using namespace std;

ifstream fin("rover.in");
ofstream fout("rover.out");

int mat[505][505];
int ff[505][505];

typedef pair<int, int> ip;
typedef pair<ip, int> coordpar;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int N, G;

void runff(int G){
    memset(ff, 999'999, sizeof(ff));
    list<coordpar> current, next;
    ff[1][1] = 0;
    current.push_back({{1, 1}, 0});
    while(current.empty() == false){
        auto el = current.front();
        current.pop_front();
        int r = el.first.first;
        int c = el.first.second;
        int par = el.second;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > N){
                continue;
            }
            int ind = mat[nr][nc] < G;
            if(par + ind < ff[nr][nc]){
                ff[nr][nc] = par + ind;
                if(ind)
                    current.push_back({{nr, nc}, par + ind});
                else
                    current.push_front({{nr, nc}, par + ind});
                
            }

        }
        
    }

}


int main(){
    int V;
    inp >> V;
    
    if(V == 1){
        
        inp >> N >> G;
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                inp >> mat[r][c];
            }
        }
        
        runff(G);
        
        fout << ff[N][N] << '\n';

        return 0;
    }

    inp >> N;
    int maxG = 0;
    int minG = 999'999;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            inp >> mat[r][c];
            maxG = max(maxG, mat[r][c]);
            minG = min(minG, mat[r][c]);
        }
    }
    //outp << minG << " min\n";
    //outp << maxG << " max\n";
    int left = minG;
    int right = maxG + 1;

    while(right - left != 1){
        int mid = (left + right)/2;
        runff(mid);
        int ans = ff[N][N];

        if(ans == 0){
            left = mid;
        } else {
            right = mid;
        }

    }

    outp << left << '\n';

    return 0;
}