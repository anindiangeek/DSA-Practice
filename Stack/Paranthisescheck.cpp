#include <bits/stdc++.h>

using namespace std;

bool isbal(string x)
{
    stack<char> s;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            s.push(x[i]);
        else if (x[i] == '}' || x[i] == ']' || x[i] == ')')
        {
            if (s.empty())
                return false;
            else
            {
                if (x[i] == ')' && s.top() == '(')
                    s.pop();
                else if (x[i] == '}' && s.top() == '{')
                    s.pop();
                else if (x[i] == ']' && s.top() == '[')
                    s.pop();
                else
                    return false;
            }
        }
    }
    return s.empty() ? true : false;
}
