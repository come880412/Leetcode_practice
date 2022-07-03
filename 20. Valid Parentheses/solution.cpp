class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        
        char parenthese;
        for(int i=0; i<s.size(); ++i){
            parenthese = s[i];
            
            if(parentheses.empty()) // Stack is empty
                parentheses.push(parenthese);
            
            else{ // Stack is not empty
                if(parenthese == '(' || parenthese == '{' || parenthese == '['){
                    parentheses.push(parenthese);
                }
                
                else{
                    char &tmp = parentheses.top();
                    
                    switch (parenthese){
                    case ')':
                        if(tmp == '(')
                            parentheses.pop();
                        else
                            return false;
                        break;
                            
                     case '}':
                        if(tmp == '{')
                            parentheses.pop();
                        else
                            return false;
                        break;
                            
                     case ']':
                        if(tmp == '[')
                            parentheses.pop();
                        else
                            return false;
                        break;
                     default:
                        break;
                    }
                    
                }
            }
        }
        if(parentheses.empty())
            return true;
        else
            return false;
    }
};
