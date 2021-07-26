#include <iostream>
#include <stdio.h> 
#include <stack>

using namespace std;

void parantheses_match();
void postfix_eval();

int main(int argc, char *argv[]){

    //parantheses_match();
    //postfix_eval();
    
    return EXIT_SUCCESS;
}

void parantheses_match(){
    string s;
    stack<char> st;

    cin>>s;
    for(char c:s){
        if(c=='(' || c=='[')
            st.push(c);
        else if((c==')' && st.top()=='(') || (c==']' && st.top()=='['))
            st.pop();
    }

    if(st.empty())
        cout<<"Parantheses are correct!!"<<endl;
    else 
        cout<<"Parantheses are not correct!!"<<endl;

    
}

void postfix_eval(){
    string s;
    stack<int> st;
    int o1,o2;

    cin>>s;
    for(char c:s){
        if(c>=48 && c<=57)
            st.push(c-48);
        else if(c=='+'){
            o1=st.top();
            st.pop();
            o2=st.top();
            st.pop();
            st.push(o1+o2);
        }
        else if(c=='-'){
            o1=st.top();
            st.pop();
            o2=st.top();
            st.pop();
            st.push(o2-o1);
        }
        else if(c=='/'){
            o1=st.top();
            st.pop();
            o2=st.top();
            st.pop();
            if(o1!=0)
                st.push(o2/o1);
            else return;
        }
        else if(c=='*'){
            o1=st.top();
            st.pop();
            o2=st.top();
            st.pop();
            st.push(o1*o2);
        }

    }

    cout<<s<<"="<<st.top()<<endl;

}
