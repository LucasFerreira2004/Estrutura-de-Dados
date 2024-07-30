#include <string>
#include <map>
#include <stack>

#include <cmath> // ?
#include <iostream> 


#define atividade "05"
#define nome "Daniel Christopher Souza Rodrigues"
#define matricula "552493"

using namespace std;

// Atividade 5

// Usando a pilha do STL do C++ implemente um avaliador de expressões numéricas cujas expressões, dadas como 
// strings de entrada, devem ter as seguintes características:

// - Ser formada for letras, operadores, números e parênteses.

// - As letras formam nomes de variáveis e as constantes podem ser números reais ou inteiros. Exemplo,
// "x+beta-1.0" => possui as variáveis x e beta, os operadores + e - e a constante numérica 1.0

// - Os operadores computáveis são em ordem de precedêcia: "(+-*/^" onde "^" é o operador de potência.

// - Espaços em branco devem ser ignoráveis e outros caracteres diferentes dos apresentados devem ser 
// considerados erros. Por exemplo, "alpha+gama0+2!"  => são erros "gama0" pois é uma variável contendo 
// um caractere não letra,  Em "2!" o caractere é inválido.

// - O valor das variáveis é uma entrada representada pela estrutura de dados map da STL do C++. 
// Veja exemplo de uso do map a seguir:

/*
    int main() {
        map<string, float> m;
        m["x"] = 21.5; // carrega 'x'
        m["beta"] = 14.72; // carrega 'beta'
    }
*/



int precedencia(char c) {
  switch (c) {
    case '+':
    case '-': return 1;
    
    case '*':
    case '/': return 2;

    case '(': return 3;

    case '^': return 4;

    default: return 0;
  }
}

bool isOperand(char ch) {
    return (isdigit(ch) || isalpha(ch));
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool isValidOperand(string str) {
  for (char c : str) {
    if (isdigit(c)) {
      return false;
    }
  }

  return true;
}

bool isValidNumber(string str) {
  for (char c : str) {
    if (isalpha(c) || (c != '.' && !isdigit(c))) {
      return false;
    }
  }

  return true;
}

float getOperationResult(float a, float b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default:  return 0;
  }
}

float calculate(stack<float>& operands, stack<char>& operators) {
  float b = operands.top(); operands.pop();
  float a = operands.top(); operands.pop();

  char op = operators.top(); operators.pop();

  cout << "calculando: " << a << op << b << endl;

  float result = getOperationResult(a, b, op);

  cout << "resultado: " << result << endl;

  return result;
}

float xEval(string x, map<string, float> &m)
{
  // x é a ///expressão  de entrada
  // m é o mapa de variáveis/valor

  stack<float> operands;
  stack<char> operators;

  string operand = "";

  for (int i = 0; i < x.length(); i++) {
    char c = x[i];

    if (c == ' ') {
      continue;
    }


    while (!isOperator(c) && i < x.length() && !(c == ' ')) {
      operand += c;
      c = x[++i];
    }

    if (operand.length() > 0) {

      if (isdigit(operand[0])) {
        if (!isValidNumber(operand)) {
          throw "A invalid constant number finded!";
        }

        operands.push(stof(operand));
      } else if (!isValidOperand(operand) || !m.count(operand)) {
        throw "A invalid operand finded!";
      } else {
        operands.push(m[operand]);
      }

      operand.clear();
    }

    if (isOperator(c)) {
      while (!operators.empty()  && precedencia(c) <= precedencia(operators.top())){
        float result = calculate(operands, operators);
        operands.push(result);
      }
      operators.push(c);
    }
  }

  while (!operators.empty()) {
    float result = calculate(operands, operators);

    operands.push(result);
  }

  return operands.top(); 
}

int main() {

  map<string, float> m;
  m["x"] = 10;
  m["beta"] = 5;
  string str = "(3.14 * 2.718 ^ 4) + 1.56";


  float r = xEval(str, m);

  cout << "valor final: " << r << endl;

  return 0;
}