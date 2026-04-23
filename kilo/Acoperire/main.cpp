#include <bits/stdc++.h>

using namespace std;

ifstream fin("acoperire.in");
ofstream fout("acoperire.out");

typedef pair<int, int> interval;
vector<interval> intervale;

vector<interval> typeshi;

int cover(int maxlen) {
    typeshi.clear();
    int cnt = 0;
    int lastendcover = -1'999'999'999;
    for(int i = 0; i < intervale.size(); i++ ){
        if(lastendcover < intervale[i].first){
            if(!typeshi.empty())
                typeshi.back().second = lastendcover;

            typeshi.push_back({intervale[i].first, 0});
            cnt++;
            lastendcover = intervale[i].first + maxlen;
        }
        if (maxlen < (intervale[i].first - intervale[i].second)){
            return 999'999'999;
        }
    }
    typeshi.back().second = lastendcover;
    return cnt;
}

int main(){
    int N;

    fin >> N;

    for(int i = 1; i <= N; i++){
        int S; int D;
        fin >> S;
        fin >> D;
        S*=-2;
        D*=-2;
        intervale.push_back({
            (S + D)/2,
            D
        });
    }

    sort(intervale.begin(), intervale.end());

    int Q; fin >> Q;

    //cout << cover(6) << "uite\n";

    for(int q = 1; q <= Q; q++){
        int K; fin >> K;

        int dreapta = 200'000'005;
        int stanga = 0;

        while(dreapta - stanga > 0){
            int mid = (dreapta + stanga)/2;
            if(cover(mid) <= K){
                dreapta = mid;
            } else {
                stanga = mid + 1;
            }
            //cout << stanga << ' ' << dreapta << endl;
        }

        cover(dreapta);
        fout << dreapta/2;
        if(dreapta % 2) fout << ".5";
        fout << '\n';
        
        fout << typeshi.size() << '\n';

        for(int i = typeshi.size() - 1; i >= 0; i--){
            auto el = typeshi[i];
            
            if(el.second > 0) fout << '-';
            fout << abs(el.second) / 2;
            if(abs(el.second) % 2) fout << ".5";
            
            fout << ' ';
            
            if(el.first > 0) fout << '-';
            fout << abs(el.first) / 2;
            if(abs(el.first) % 2) fout << ".5";
            fout << '\n';
        }
    }
    
    return 0;
}