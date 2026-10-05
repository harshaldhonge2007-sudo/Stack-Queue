class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
                continue;
            }
            if(st.empty()){
                return false;
            }
            char topbracket = st.top();

            if(ch== ')' && topbracket != '('){
                return false;
            }
            if(ch== '}' && topbracket != '{'){
                return false;
            }
            if(ch== ']' && topbracket != '['){
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};