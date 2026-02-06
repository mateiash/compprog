#include <fstream>
#include <iostream>
#include <map>

using namespace std;

ifstream fin("opsir.in");
ofstream fout("opsir.out");

char S[200005];
char T[200005];

int fS[26];
int fT[26];

int C;

void reset_f() {
  for(int i = 0; i < 26; i++){
    fS[i] = 0;
    fT[i] = 0;
  }
}

int main(){
  fin >> C;

  int k; fin >> k;
  for(int test = 0; test < k; test++) {
    reset_f();
    int n, m;
    fin >> n >> m;
    fin >> S >> T;

    
    for(int i = 0; i < n; i++)
      fS[S[i] - 'a']++;

    for(int i = 0; i < m; i++)
      fT[T[i] - 'a']++;

    int distincte = 0;
    for(int i = 0; i < 26; i++)
        if(fS[i] + fT[i] > 0)
          distincte++;

    if(C == 1){
      fout << distincte << '\n';
      for(int i = 0; i < 26; i++){
        if(fS[i] + fT[i] == 0)
          continue;

        fout << (char) ('a' + i) << ' ';

        if(fT[i] >= fS[i]){
          fout << 'T';
        } else {
          fout << 'S';
        }

        fout << '\n';
      }
      continue; 
    }

    int pointS = 0;
    int pointT = 0;
    int bad = 0;
    while(pointS < n){
        map<char, int> freqsubS;
        int startS = pointS;
        int needToCover = 1;
        freqsubS[S[pointS]]++;
        while(S[pointS+1] >= S[pointS]){
            pointS++;
            freqsubS[S[pointS]]++;
            needToCover++;
        }
        //fout << needToCover << " need to cover\n";
        int covered = 0;

        while(covered!=needToCover){
            if(pointT >= m){
                break;
            }
            char c = T[pointT];
            if(freqsubS[c]){
                freqsubS[c]--;
                covered++;
            }
            pointT++;
        }
        
        if(pointT >= m && covered!=needToCover){
            bad = 1;
            break;
        }
        pointS++;

    }
    if(bad){
        fout << "NU\n";
    } else {
        fout << "DA\n";
    }
    
  }

  return 0;
}
