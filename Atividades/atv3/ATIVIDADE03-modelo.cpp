#include <fstream>
#include <iostream>

#define atividade "3"
#define nome "Daniel Christopher Souza Rodrigues"
#define matricula "552493"

namespace aluno
{

  /*
  Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.
  */

  class frac
  {
    int num;
    int den;
    static int mdc(int a, int b)
    {
      // calcula mdc dos argumentos
      if (b == 0)
      {
        return a;
      }
      return mdc(b, a % b);
    }

  public:
    frac(int n = 0, int d = 1)
    {
      // Construtor
      num = n;
      den = d;
    }
    // Operadores
    bool operator>(frac &b)
    {
      // configura operador >
      if (((float)num / den) > ((float)b.getNum() / b.getDen()))
      {
        return true;
      }
      return false;
    }
    bool operator==(frac &b)
    {
      // configura operador ==
      if (num == b.getNum() && den == b.getDen())
      {
        return true;
      }
      return false;
    }
    frac operator+(frac &b)
    {
      // soma
      int newNum = (num * b.getDen()) + (den * b.getNum());
      int newDen = den * b.getDen();

      newNum = newNum / mdc(newNum, newDen);
      newDen = newDen / mdc(newNum, newDen);

      return frac(newNum, newDen);
    }
    int getNum() { return num; }
    int getDen() { return den; }
  };

  frac *loadFracs(char *fileFracs)
  {
    /*
    Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente.

    O conteúdo de tais arquivos segue o formato do esquema a seguir,

    -----------
    4           | -> 4 frações
    1   2       | -> fração 1/2
    3   5       | -> fração 1/5
    2   9       ! -> fração 2/9
    7   11      ! -> fração 7/11
    -------------
    */
    // Abrindo arquivo
    std::fstream infile(fileFracs);

    // Leitura do número de fracoes
    int nFracs;
    infile >> nFracs;

    // Aloca um vetor de fracoes
    frac* fracs = new frac[nFracs];

    //Leitura das fracoes do arquivo
    for (int i = 0; i < nFracs; i++) {
      int num, den;
      infile >> num >> den;
      fracs[i] = frac(num, den);
    }

    // Fechando o arquivo
    infile.close();

    return fracs;
  }

  frac sumFracs(frac fracs[], int n)
  {
    /*
     Retorna soma de frações do vetor de entrada.
    */
    if (n == 1)
    {
      return fracs[0];
    }

    frac nextFrac = sumFracs(fracs + 1, n - 1);

    return fracs[0] + nextFrac;
  }

  void sortFracs(frac fracs[], int n)
  {
    /*
       ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.
    */

    for (int j = n - 1; j > 0; j--)
    {
      for (int i = 0; i < j; i++)
      {
        if (fracs[i] > fracs[i + 1])
        {
          frac x = fracs[i];
          fracs[i] = fracs[i + 1];
          fracs[i + 1] = x;
        }
      }
    }
  }
}

using namespace std;
using namespace aluno;

int main()
{
  // Leitura do arquivo de frações
  char nomeArquivoFracoes[] = "./fracoes.txt";
  frac *fracoes = loadFracs(nomeArquivoFracoes);
  int numFracoes = 3;

  // Teste da função loadFracs
  if (fracoes == nullptr)
  {
    cout << "Erro ao carregar frações do arquivo!" << endl;
    return 1;
  }

  // Exibição das frações lidas
  cout << "Frações lidas do arquivo:" << endl;
  for (int i = 0; i < numFracoes; i++)
  {
    cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << endl;
  }

  // Teste da função sumFracs
  cout << endl << "Soma de todas as frações:" << endl;
  frac soma = sumFracs(fracoes, numFracoes);
  cout << soma.getNum() << "/" << soma.getDen() << endl;

  // Teste da função sortFracs
  cout << endl << "Frações ordenadas:" << endl;
  sortFracs(fracoes, numFracoes);
  for (int i = 0; i < numFracoes; i++)
  {
    cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << endl;
  }

  // Liberação da memória alocada para as frações
  delete[] fracoes;

  return 0;
}