#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("incurcatura.in");
ofstream fout("incurcatura.out");

typedef pair<int, int> ip;

set<ip> oriented;

int main(){

    int P;
    fin >> P;

    int N;
    fin >> N;

    for(int i = 1; i <= N; i++){
        int k;
        fin >> k;

        for(int j = 1; j <= k; j++){
            int node; fin >> node;

            if(oriented.count({node, i})){
                oriented.erase({node, i});
                continue;
            }
            oriented.insert({i, node});
        }

    }
    vector<int> freq(N + 1);
    for(auto el : oriented){
        freq[el.first]++;
        freq[el.second]++;
        //cout << el.first << ' ' << el.second << '\n';
    }
    //cout << '\n';
    if(P == 1){
        for(int i = 1; i <= N; i++){
            if(freq[i] == oriented.size()){
                fout << i << '\n';
                return 0;
            }
        }
    }

    vector<vector<int>> somethingig(oriented.size() + 1);
    for(int i = 1; i <= N; i++){
        ip search = {i, -1};
        if(
            oriented.lower_bound(search)->first == i
        ){
            somethingig[freq[i]].push_back(i);
        }
        //cout << i << ": " << freq[i] << '\n';

    }

    //cout << '\n';

    for(int i = 1; i <= oriented.size(); i++){
        if(somethingig[i].empty()) continue;
        //cout << i << ": " << somethingig[i][0] << '\n';
        if(!somethingig[oriented.size() - i].empty()){
            for(auto el : somethingig[oriented.size() - i]){
                if( !(oriented.count({somethingig[i].back(), el}) || oriented.count({el, somethingig[i].back()}))
                ){
                    fout << min(somethingig[i].back(), el) << ' ';
                    fout << max(somethingig[i].back(), el) << '\n';
                    return 0;
                }
            }
        }
        if(!somethingig[oriented.size() - i + 1].empty()
        ){
            fout << min(somethingig[i].back(), somethingig[oriented.size() - i + 1].back()) << ' ';
            fout << max(somethingig[i].back(), somethingig[oriented.size() - i + 1].back()) << ' ';
            return 0;
        }

    }



    return 0;
}