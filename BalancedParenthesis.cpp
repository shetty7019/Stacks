#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool IsValid(string s){
    int n=s.size();
    stack<char> st;

    bool ans=true;
int i;
    for( i=0;i<n;i++){
        if(s[i]=='(' ||s[i]=='[' ||s[i]=='{' ){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                ans= false;
                break;
            }
        }
         else if(s[i]==']'){
            if(!st.empty() and st.top()=='['){
                st.pop();
            }
            else{
                ans= false;
                break;
            }
        }
         else if(s[i]=='}'){
            if(!st.empty() and st.top()=='{'){
                st.pop();
            }
            else{
                ans= false;
                break;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return ans;
}

int main(){

    string s="{[()]}";

    if(IsValid(s)){
       cout<<"The string is valid!"<<endl; 
    }

    else{
        cout<<"The string is invalid!"<<endl;
    }

    return 0;
}