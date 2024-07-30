#include <fstream>

#define atividade "3"  
#define nome "Lucas Ferreira Nobre" 
#define matricula "554590"

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
            if (b == 0)
                return a;
            return (mdc(b, a % b));
        }

    public:
        frac(int n = 0, int d = 1)
        {
            int m = mdc(n, d);
            num = n / m;
            den = d / m;
        }
        // Operadores
        bool operator>(frac &frac2)
        {
            if (((float)num / den) > ((float)frac2.getNum() / frac2.getDen()))
                return true;
            return false;
        }
        bool operator==(frac &frac2)
        {
            if (num == frac2.getNum() && den == frac2.getDen())
                return true;
            return false;
        }
        frac operator+(frac &frac2)
        {
            int newNum = num * frac2.getDen() + den * frac2.getNum();
            int newDen = den * frac2.getDen();
            return frac(newNum, newDen);
        }
        int getNum() { return num; }
        int getDen() { return den; }
    };

    frac *loadFracs(const char *fileFracs)
    {
        std::fstream file(fileFracs);
        int size;
        file >> size;

        frac *vetFracs = new frac[size];

        for (int i = 0; i < size; i++)
        {
            int num, den;
            file >> num >> den;
            vetFracs[i] = frac(num, den);
        }
        file.close();
        return vetFracs;
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
    }

    frac sumFracs(frac fracs[], int n)
    {
        frac sum = fracs[0];
        for (int i = 1; i < n; i++)
        {
            sum = sum + fracs[i];
        }
        return frac(sum.getNum(), sum.getDen());
    }

    void sortFracs(frac fracs[], int n)
    {
        for (int i = n - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
                if (fracs[j] > fracs[j + 1])
                {
                    frac x = fracs[j];
                    fracs[j] = fracs[j + 1];
                    fracs[j + 1] = x;
                }
    }
}
