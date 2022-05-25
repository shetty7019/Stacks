#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        /* code */
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }

        st.push(word);

    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    

}


int main()
{
    string sentence;
    cout << "Enter the sentence to reverse it: " << endl;
    cin >> sentence;
 reverseSentence(sentence);
    return 0;
}