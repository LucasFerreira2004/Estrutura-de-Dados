#define atividade "04"
#define nome "Garibaldi"
#define matricula "***123"
#include <iostream>
using namespace std;

// 1

class vetor
{
  int *u;   // ponteiro para vetoe
  int size; // tamanho do vetor
  int i;

public:
  vetor(int n)
  {
    u = new int[n];

    for (int k = 0; k < n; k++) {
      u[k] = 0;
    }

    size = n;
    i = 0;
  }
  ~vetor() { delete[] u; }
  int &operator[](int k) { return u[k]; }
  int len() { return size; }

  void operator+=(int k) {
    u[i] = k;
    ++i;
  }
};

vetor mergeAll(vetor U[], int n)
{
  vetor ids(n);
  int r_size = 0;
  for (int i = 0; i < n; i++) {
    r_size += U[i].len();
  }

  vetor result(r_size);

  while (true) {
    int menor_id = -1;
    bool achei = false;

    for (int i = 0; i < n; i++) {
      if (ids[i] < U[i].len()) {
        if (!achei || U[i][ids[i]] < U[menor_id][ids[menor_id]]) {
          menor_id = i;
          achei = true;
        }
      }
    }

    if (!achei) {
      break;
    }

    result += U[menor_id][ids[menor_id]];
    ids[menor_id]++;
  }

  return result;
}

int main()
{
  vetor U[3] = {
      vetor(3),
      vetor(3),
      vetor(3),
  };

  U[0][0] = 1; U[0][1] = 3; U[0][2] = 5;

  U[1][0] = 2; U[1][1] = 4; U[1][2] = 6;

  U[2][0] = 7; U[2][1] = 8; U[2][2] = 9;

  vetor r = mergeAll(U, 3);

  for (int i = 0; i < r.len(); i++)
  {
    cout << r[i] << " ";
  }

  return 0;
}

/*
Exemplo 1

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [2,1], [4,0,9] } => {3}
{ [6,8,5], [1], [4,0,9] } => {3,2}
{ [6,8,5], [], [4,0,9] } => {3,2,1}
{ [6,8,5], [], [0,9] } => {3,2,1,4}
{ [6,8,5], [], [9] } => {3,2,1,4,0}
{ [8,5], [], [9] } => {3,2,1,4,0,6}
{ [5], [], [9] } => {3,2,1,4,0,6,8}
{ [], [], [9] } => {3,2,1,4,0,6,8,5}
{ [], [], [] } => {3,2,1,4,0,6,8,5,9}

Exemplo 2

U = { [1,3,5], [2,4,6], [7,8,9] }


{ [3,5], [2,4,6], [7,8,9] } => {1}
{ [3,5], [4,6], [7,8,9] } => {1,2}
{ [5], [4,6], [7,8,9] } => {1,2,3}
{ [5], [6], [7,8,9] } => {1,2,3,4}
{ [], [6], [7,8,9] } => {1,2,3,4,5}
{ [], [], [7,8,9] } => {1,2,3,4,5,6}
{ [], [], [8,9] } => {1,2,3,4,5,6,7}
{ [], [], [9] } => {1,2,3,4,5,6,7,8}
{ [], [], [] } => {1,2,3,4,5,6,7,8,9}

*/