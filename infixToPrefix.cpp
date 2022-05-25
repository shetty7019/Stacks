#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// function to know the precedence of the character

int precedence(char c)
{

    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    else
    {
        return -1; // returns when there is opening bracket
    }
}

string infixToPrefix(string s)
{

    reverse(s.begin(), s.end());
    stack<char> st;
    string result;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }

        else if (s[i] == ')')
        {
            st.push(s[i]);
        }

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

reverse(result.begin(),result.end());
    return result;
}

int main()
{
    cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}
