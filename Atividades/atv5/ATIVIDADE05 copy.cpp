#include <string>
#include <map>
#include <stack>

#include <cmath>//?
#include <iostream>//
#include <cctype> //

using namespace std;

#define atividade "05"
#define nome "Lucas Ferreira Nobre"
#define matricula "554590"
int prioridade (char ch){
    switch(ch){
        case '^': return 3;

        case '*': 
        case '/': return 2;

        case '+':
        case '-': return 1;

        case '(': return 0;
    }
    return -1;
}

float calcular (float op1, float op2, char c){
  switch(c){
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    case '^':
      return pow(op1, op2);
    default:
      throw "erro";
  }
}

float xEval(string x, map<string, float> &m)
{
  stack<float> num;
  stack<char> oper;
  string numStr = "";
  string varNome = "";

  for (int i=0; i<x.length(); i++){
    if(x[i] == ' ') continue;
    //pegando números
     if (isdigit(x[i]) && i == x.length()-1){
      numStr += x[i];
      num.push(stof(numStr));
      continue;
    }
    else if (isdigit(x[i]) || x[i]=='.'){
      if (isalpha(x[i+1])){
        throw "erro: formato numerico invalido\n";
      }
      numStr += x[i];
      continue;
    } 
    else if(numStr != ""){
      num.push(stof(numStr));
      numStr = "";
    }

    //pegando numeros vindo de variaveis (x, beta)
    if (isalpha(x[i]) && i == x.length()-1){
      varNome += x[i];
      num.push(m[varNome]);
      continue;
    }
    else if (isalpha(x[i])){
      if (isdigit(x[i+1])){
        throw "erro: nome de variavel invalido\n";
      }
      varNome += x[i];
      continue;
    }
    else if (varNome != ""){
      if (m.count(varNome)==0){
        throw "erro: o nome da variavel nao corresponde a nenhum nome mapeado no map";
      }
      num.push(m[varNome]);
      varNome = "";
    }
    //agora a lógica com operadores
    char c = x[i];
    switch(c){
      case '^':
      case '*':
      case '/':
      case '+':
      case '-':
        while(!oper.empty() && prioridade(c) <= prioridade(oper.top())){
          float op2 = num.top(); num.pop();
          char c = oper.top(); oper.pop();
          float op1 = num.top(); num.pop();
          num.push(calcular(op1, op2, c));
        }  
        oper.push(c);
        break;
      case '(':
        oper.push(c);
        break;
      case ')':
        while (oper.top() != '('){
          float op2 = num.top(); num.pop();
          char c = oper.top(); oper.pop();
          float op1 = num.top(); num.pop();
          num.push(calcular(op1, op2, c));
        }
        oper.pop();
        break;
      default:
        throw "erro: operador inválido";
    }
  }

  while(!oper.empty()){
    float op2 = num.top(); num.pop();
    char c = oper.top(); oper.pop();
    float op1 = num.top(); num.pop();
    num.push(calcular(op1, op2, c));
  }
  return num.top();
}

int main(){
  map<string, float> m;
  m["x"] = 21.5; // carrega 'x'
  m["beta"] = 14.72; // carrega 'beta'
  string s = "";
  while(true){
    cout << "expressão infixa: ";
    getline(cin, s);
    if (s=="stop") break;
    try{
      cout << xEval(s, m) << endl;
    }catch(const exception& e) { // Capturando exceções genéricas
      cout << e.what() << endl;
    }
  }

  exit(0);
}

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
