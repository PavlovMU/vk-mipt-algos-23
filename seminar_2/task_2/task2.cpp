#include <iostream>
#include <stack>
using namespace std;

bool is_palindrome(string s){
    stack<char> st;
    for(size_t i=0; i<s.size(); i++)
        st.push(s[i]);
    for(size_t i=0; i<s.size(); i++){
        char top = st.top();
        if(top != s[i])
            return false;
        st.pop();}
    return true;
}

int main(void){
    cout<<is_palindrome("")<<endl;
    cout<<is_palindrome("A")<<endl;
    cout<<is_palindrome("AA")<<endl;
    cout<<is_palindrome("AB")<<endl;
    cout<<is_palindrome("ABA")<<endl;
    cout<<is_palindrome("SABAS")<<endl;
    cout<<is_palindrome("SABAJ")<<endl;
    cout<<is_palindrome("ALOOLA")<<endl;
    return 0;
}

