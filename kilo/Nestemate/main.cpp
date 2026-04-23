#include <bits/stdc++.h>
#include <iterator>

using namespace std;

ifstream fin("nestemate.in");
ofstream fout("nestemate.out");

struct nestemata {
    int X;
    int Y;
    int Z;
};

vector<nestemata> nestemate;
vector<vector<int>> links;

vector<int> moves;

int main(){
    int T; fin >> T;

    for(int cer = 0; cer < T; cer++){
        nestemate.clear();
        links.clear();
        moves.clear();

        int N, A, B;
        fin >> N >> A >> B;

        nestemate.resize(N + 1);
        moves.resize(500'000 + 1);
        links.resize(500'000 + 1);

        for(int i = 1; i <= N; i++){
            int X, Y, Z;
            fin >> X >> Y >> Z;

            nestemate[i] = {X, Y, Z};
            
            //moves[i] = -1;

            links[X].push_back(Y);
            links[X].push_back(Z);
            
            links[Y].push_back(X);
            links[Y].push_back(Z);
            
            links[Z].push_back(Y);
            links[Z].push_back(X);

        }
        
        /*
        for(int i = 1; i <= N; i++){
            fout << i << ": ";
            for(auto el : links[i]){
                fout << el << ' ';
            }fout << '\n';
        }
        */
        queue<pair<int, int>> bfs;
        bfs.push({nestemate[A].X, 1});
        bfs.push({nestemate[A].Y, 1});
        bfs.push({nestemate[A].Z, 1});
        moves[nestemate[A].X] = 1;
        moves[nestemate[A].Y] = 1;
        moves[nestemate[A].Z] = 1;

        while(!bfs.empty()){

            int num = bfs.front().first;
            int step = bfs.front().second;

            for(auto el : links[
                    num]){
                
                if(moves[el] == 0){
                    bfs.push({el, step + 1});
                    moves[el] = step + 1;
                }
            }


            bfs.pop();
        }
        
        for(int i = 1; i <= N; i++){
            //fout << nestemate[i].X << ' ';
            //fout << nestemate[i].Y << ' ';
            //fout << nestemate[i].Z << ": ";

            //fout << moves[i] << '\n';

        }

        //fout << '\n';

        if(moves[
            nestemate[B].X] == 0){
                fout << "-1\n"; continue;
            }
        
        fout << min(
            moves[nestemate[B].X], 
            min(moves[nestemate[B].Y], 
            moves[nestemate[B].Z]) 
        )
            << '\n';
        //fout << '\n';

    }

    return 0;
}