#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int dists[10'005];

int howmany(int dist){
    dist -= 1;
    int r;
    if(dist % 3 == 0){
        r = dist/3 + 1;
    }

    if(dist % 3 == 1){
        r = dist + 1;
    }
    return r;
}

pair<int, int> topos(int dist, int ind){
    int removed = (howmany(dist) - ind);

    if(dist % 3 == 1){
        int y = (dist) - (removed)*3;
        int x = dist + 1 - y;
        return {x, y};
    } else {
        
        if(removed < howmany(dist) - 1){
        if(removed % 3 == 1){
            removed++;
        } else if(removed % 3 == 2){
            removed--;
        }
    }

        int x, y;
        y = dist - removed;
        x = dist + 1 - y;
        if(removed % 3 == 2){
            x--;
            y--;
        }
        return {x, y};

    }
}

int queries[50'005];

int main(){
    int t;
    
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        fill(dists, dists + 1'005, 0);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> queries[i];
        }

        for(int i = 1; i <= 10'004; i++){
            dists[i] = howmany(i);
        }
        /*
        for(int i = 1; i <= 10; i++){
            cout << dists[i] << ' ';
        }
        cout << '\n';
        */

        int point1 = 1;
        int point0 = 1;

        for(int i = 1; i <= n; i++){
            //cout << i << ": ";
            if(queries[i]){
                dists[point1]--;
                //cout << point1 << '\n';
                cout << topos(point1, dists[point1] + 1).first << ' ';
                cout << topos(point1, dists[point1] + 1).second << '\n';
            } else {
                dists[point0]--;
                //cout << point0 << '\n';
                cout << topos(point0, dists[point0] + 1).first << ' ';
                cout << topos(point0, dists[point0] + 1).second << '\n';
            }

            while(dists[point1] == 0){
                if(point1%3 == 1){
                    point1++;
                } else {
                    point1+=2;
                }
            }

            while(dists[point0] == 0){
                point0+=3;
            }
                
            //cout << "pnts ";
            //cout << point1 << ' ' << point0 << '\n';
            
        }
        cout << '\n';
    }

    return 0;
}
