#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int prioridade (char ch){
    switch(ch){
        case '*': 
        case '/': return 2;

        case '+':
        case '-': return 1;

        case '(': return 0;
    }
    return -1;
}
int main(){     
    string str;
    cin >> str;

    stack<string> var; //variaveis
    stack<char> oper; //operadores

    for (char c: str){
        if (isalpha(c)){
            stringstream x;
            x << c;
            var.push(x.str());
        }else if (c=='+' || c=='-' || c=='*' || c=='/'){
            int pEnter = prioridade(c);
            if (oper.empty() || pEnter >= prioridade(oper.top()))
                oper.push(c);
            else{
                while (!oper.empty() && prioridade(oper.top()) > pEnter){
                    char op = oper.top(); oper.pop();
                    string b = var.top(); var.pop();
                    string a = var.top(); var.pop();

                    stringstream ss;
                    ss << a << b << op;
                    var.push(ss.str());
                    cout << "var.top(): " << var.top() << endl;
                }
            }
        }else if(c=='('){
            
        }
    }
    while (!oper.empty()){
        string b = var.top(); var.pop();
        string a = var.top(); var.pop();
        stringstream ss;
        ss << a << b << oper.top();
        oper.pop();
        var.push(ss.str());
    }
    cout << var.top();
    cout << endl;
    return 0; 
}
