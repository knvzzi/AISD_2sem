#include <iostream>
#include <stack>
#define circle stk.push(')'); break;
#define square stk.push(']'); break;
#define curly stk.push('}'); break;
#define math stk.push('>'); break;

using namespace std;

bool correct(string s)
{
    stack <char> stk; 
    for (char symbol : s) {
        switch (symbol) {

        case '(': circle;
        case '[': square;
        case '{': curly;
        case '<': math;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stk.empty() || stk.top() != symbol) 
            { 
                return false;
            }
            stk.pop(); 
        default:
            break;
        }
    }
    return stk.empty();
}

bool nalichie(string s) 
{ 
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '<' || s[i] == '>')
        {
            return true;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    string s;
    cout << "Введите строку для проверке: "; 
    cin >> s;
    nalichie(s);
    if (nalichie(s) == true)
    {
        correct(s);
        if (correct(s) == true)
        {
            cout << "\nCкобки расставлены верно";
        }
        else
        {
            cout << "\nCкобки расставлены не верно";
        }
    }
    else
    {
        cout << "\nВ строке нет скобок";
    }
}