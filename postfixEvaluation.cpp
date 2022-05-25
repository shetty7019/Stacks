#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int postfixEvaluation(string s){

    stack<int> st;

    int i,op1,op2;

    for(i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }

        else{
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
        }

        switch (s[i])
        {
        case '+':
            /* code */
            st.push(op1+op2);
            break;
        case '-':
            /* code */
            st.push(op1-op2);
            break;
        case '*':
            /* code */
            st.push(op1*op2);
            break;
        case '/':
            /* code */
            st.push(op1/op2);
            break;
        case '^':
            /* code */
            st.push(pow(op1, op2));
            break;
        
        default:
            break;
        }

    }

    return st.top();
}

int main(){

    cout<<postfixEvaluation("46+2/5*7+");
    return 0;
}