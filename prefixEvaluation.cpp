#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int prefixEvaluation(string s)
{

    stack<int> st;
    int op1, op2, i;

    for (i = s.length() - 1; i >= 0; i--)//reading the string from right
    {
        if (s[i] >= '0' && s[i] <= '9')//if it is a operand then push in the stack
        {
            st.push(s[i] - '0');
        }

        else//if string has operator
        {
            //pop the first two operands in the stack
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();
        }

        switch (s[i])//now calculate according to the operation and push back to the stack
        {
        case '+':
            st.push(op1 + op2);
            break;
        case '-':
            st.push(op1 - op2);
            break;
        case '*':
            st.push(op1 * op2);
            break;
        case '/':
            st.push(op1 / op2);
            break;
        case '^':
            st.push(pow(op1, op2));
            break;
        default:
            break;
        }
    }

    return st.top();//return the final result
}
int main()
{
    cout << prefixEvaluation("-+7*45+20") << endl;
    return 0;
}
// example
//  -+7*45+20