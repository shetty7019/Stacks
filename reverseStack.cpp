#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int ele){
    
    if(st.empty()){
        st.push(ele);
        return;
    }
    
    int topele=st.top(); //store the top element 
    st.pop();//pop the top element
    insertAtBottom(st,ele);//insert at bottom

    st.push(topele);//push the top element back to stack
}


void reverse(stack<int> &st){

if(st.empty()){
    return;
}
    int ele=st.top();//store the top element in variable ele

    st.pop();//then pop the top element

    reverse(st);//call recursion function for rest of the elements
    insertAtBottom(st,ele);//insert the top element which was popped at the bottom


}
int main(){
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);

reverse(st);
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}cout<<endl;

}