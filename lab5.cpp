#include <iostream>
#include <queue>

using namespace std;

int main() {
    int mas[11][11] = {
//        A  B  C  D  E  F  G  H  I  J  S
/* A */  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
/* B */  {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
/* C */  {0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
/* D */  {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
/* E */  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
/* F */  {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
/* G */  {0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
/* H */  {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
/* I */  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
/* J */  {0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
/* S */  {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},

  };
  int req = 10;

  queue<int> q;
  int parent[11];
  int visited[11];
  for (int i = 0; i < 11; i++) {
    visited[i] = 0;
    parent[i] = -1;
  }
  const int start = 8;
  visited[start] = 1;

  q.push(start);
  while (!q.empty())
  {
    int node = q.front(); 
    q.pop();
    if (node == req) 
      break;
    for (int n = 0; n < 11; n++) {
      if (mas[node][n] == 1 && !visited[n]) {
        visited[n] = true;
        parent[n] = node;
        q.push(n);
      }
    }
  }
  int resp[11];
  for (int i = 0; i < 11; i++) {
        resp[i] = -1;
    }
  int count = 0;
  for (int v = req; v != -1; v = parent[v]) {
    resp[count++] = v;
  }

  cout << "Кратчайший путь: ";
  for (int i = count - 1; i >= 0; i--) {
      if (resp[i] == 10) {
          cout << 'S'; 
      } else {
          cout << (char)('A' + resp[i]);
      }
      if (i > 0) {
          cout << " -> ";
      }
  }
  cout << endl;

  
  return 0;
}
