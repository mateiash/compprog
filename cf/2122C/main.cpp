#include <bits/stdc++.h>
#include <ios>

#define ll long long
#define ull unsigned long long

#define inp cin
#define outp cout

using namespace std;

int xcoords[200'005];
int ycoords[200'005];

typedef pair<int, int> ip;

ofstream fout("debug.out");

int manhattan(ip a, ip b){
    return (
        abs(a.first - b.first) + abs(a.second - b.second)
    );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    inp >> t;

    for(int cer = 0; cer < t; cer++){
        vector<pair<ip, int>> xs;
        vector<pair<ip, int>> ys;
        int n; inp >> n;

        for(int i = 1; i <= n; i++){
            int x, y;
            inp >> x >> y;
            xs.push_back({{x, y},i});
            ys.push_back({{y , x},i});
            xcoords[i]=x;
            ycoords[i]=y;
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        ip limlr = xs[n/2 - 1].first;
        ip limud = ys[n/2 - 1].first; // this is y first
        
        int leftcm[200'005] = {0};
        int downcm[200'005] = {0};
        for(int i = 0; i <= n / 2 - 1; i++){
            leftcm[xs[i].second] = 1;
            downcm[ys[i].second] = 1;
        }

        //swap(limud.first, limud.second);
        /*
        outp << limlr.first << ' ' << limlr.second << '\n';
        outp << limud.second << ' ' << limud.first << '\n';
        */
        vector<vector<int>> quadrants(4);
        for(int i = 1; i <= n; i++){
            int x = xcoords[i];
            int y = ycoords[i];

            int leftc = leftcm[i];
            int downc = downcm[i];

            //outp << x << ' ' << y << " coord\n";
            //outp << leftc << ' ' << downc << " distrib\n";
            //outp.flush();
            
            quadrants[leftc + downc*2].push_back(
                i
            );
        }

        while(!quadrants[0].empty()){
            auto it1 = --quadrants[0].end();
            auto it2 = --quadrants[3].end();

            outp << (*it1) << ' ' <<
                (*it2) << '\n';

            quadrants[0].pop_back();
            quadrants[3].pop_back();

        }    
        
        while(!quadrants[1].empty()){
            auto it1 = --quadrants[1].end();
            auto it2 = --quadrants[2].end();

            outp << (*it1) << ' ' <<
                (*it2) << '\n';

            quadrants[1].pop_back();
            quadrants[2].pop_back();

        }   

        outp << '\n';


    }

    return 0;
}
