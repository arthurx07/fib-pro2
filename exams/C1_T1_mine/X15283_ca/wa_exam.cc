#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    string str;
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); ++i)
        {
            s.push(str[i]);
        }
        
        // bool repeat = true;
        int i = 0;
        while (not s.empty() and i <= 10000) // :(
        {
            //if (s.top() == '(' or str[i] == '[')
                //s.push(str[i]);
            if (s.top() == ')') 
            {   
                s.pop();
                if (not s.empty() and s.top() == '(') s.pop();
                else s.push(')');
            }
            else if (s.top() == ']')
            {
                s.pop();
                if (not s.empty() and s.top() == '[') s.pop();
                else if (not s.empty() and s.top() == '(')
                {
                    s.pop();
                    s.push(']');
                }
                else s.push(']');
            }
            ++i;
        }
        
        while (not s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
}
