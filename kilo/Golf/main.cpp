#include <fstream>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define ll long long

ifstream fin("golf.in");
ofstream fout("golf.out");

int golf[1005][1005];

ll acoloane[1005];
ll bcoloane[1005];

ll alinii[1005];
ll blinii[1005];

int n, m;

struct Insula {
  int celule;

  int x1;
  int y1;

  int x2;
  int y2;
};

Insula insule[1000005];
int insule_cnt;

void gaseste_insule();

void task_2();
void task_3();

void debug_matrice();
void debug_insule();

int main() {
  int T;

  fin >> T >> n >> m;

  int sum = 0;
  
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      char a;
      fin >> a;
      a = a - '0';
      golf[i][j] = a;
      sum+=a;
    }
  }

  if(T == 1){
    fout << sum;
  } else if (T == 2) {
    //cout << " te pup cerinta 2";
    gaseste_insule();
    task_2();
  } else if (T == 3){
    gaseste_insule();
    task_3();
  }
  //debug_matrice();
  //debug_insule();
  return 0;
}

bool in_queue[1005][1005];

int dl[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void gaseste_insule() {
    int insula_curenta = 2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (golf[i][j] != 1) continue;

            //memset(in_queue, 0, sizeof(in_queue));

            queue<pair<int,int>> Q;
            Q.push({i, j});
            in_queue[i][j] = true;

            int x1 = j, x2 = j;
            int y1 = i, y2 = i;
            int celtot = 0;

            while (!Q.empty()) {
                auto [l, c] = Q.front();
                Q.pop();

                if (golf[l][c] != insula_curenta)
                    celtot++;

                golf[l][c] = insula_curenta;

                x1 = min(x1, c);
                x2 = max(x2, c);
                y1 = min(y1, l);
                y2 = max(y2, l);

                for (int k = 0; k < 4; k++) {
                    int nl = l + dl[k];
                    int nc = c + dc[k];

                    if (nl < 1 || nl > n || nc < 1 || nc > m) continue;

                    if (golf[nl][nc] == 1 && !in_queue[nl][nc]) {
                        Q.push({nl, nc});
                        in_queue[nl][nc] = true;  
                    }
                }
            }

            insule[insula_curenta].x1 = x1;
            insule[insula_curenta].x2 = x2;
            insule[insula_curenta].y1 = y1;
            insule[insula_curenta].y2 = y2;
            insule[insula_curenta].celule = celtot;

            insula_curenta++;
        }
    }

    insule_cnt = insula_curenta - 1;
}



void debug_matrice(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cout << golf[i][j] << ' ';
    }
    cout << '\n';
  }
}

void debug_insule(){
  for(int i = 2; i <= insule_cnt; i++){
    cout << "insula " << i << '\n';
    cout << "x1 y1 x2 y2 celule\n";
    cout << insule[i].x1 << ' ' <<
      insule[i].y1 << ' ' <<
      insule[i].x2 << ' ' <<
      insule[i].y2 << ' ' <<
      insule[i].celule << '\n';
  } 
}

void task_2(){
  int cnt = 0;
  int max = -1;
  for(int i = 2; i <= insule_cnt; i++){
    int cel = insule[i].celule;
    if(cel == max)
      cnt++;
    else if(cel > max){
      max = cel;
      cnt = 1;
    }
  }
  fout << cnt;
}

void task_3(){
  int qu = 0;
  fin >> qu;
    
  for(int i = 2; i <= insule_cnt; i++){
    Insula ins = insule[i]; 
    /*ineficient
    for(int j = 1; j < ins.x1; j++){
        bcoloane[j]+=ins.celule;
    }
    
    for(int j = ins.x2 + 1; j <= m; j++){
        acoloane[j]+=ins.celule;
    }
    
    for(int j = 1; j < ins.y1; j++){
        blinii[j]+=ins.celule;
    }
    
    for(int j = ins.y2 + 1; j <= n; j++){
        alinii[j]+=ins.celule;
    }
    */
    bcoloane[ins.x1-1]+=ins.celule;
    acoloane[ins.x2 + 1]+=ins.celule;
    blinii[ins.y1-1]+=ins.celule;
    alinii[ins.y2 + 1]+=ins.celule;

  }

  for(int j = m; j >= 1; j--){
        bcoloane[j] = bcoloane[j] + bcoloane[j + 1];
    }
  for(int j = 1; j <= m; j++){
        acoloane[j] = acoloane[j] + acoloane[j - 1];
    }

  for(int j = n; j >= 1; j--){
        blinii[j] = blinii[j] + blinii[j + 1];
    }
  for(int j = 1; j <= n; j++){
        alinii[j] = alinii[j] + alinii[j - 1];
    }
  
  for (int i = 0; i < qu; i++){
    char task;
    int query;

    fin >> task >> query;
    bool column = false;
    if (task == 'C'){
        fout << acoloane[query] * bcoloane[query] << '\n'; 
    } else {
        fout << alinii[query] * blinii[query] << '\n'; 
    }
    
  }
  return;
}