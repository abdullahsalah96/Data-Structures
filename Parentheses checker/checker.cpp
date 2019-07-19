#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string s){
  int size = s.size();
  stack<char> stack;
  for(int i=0; i<size; i++){
    if(s[i] == '[' || s[i] == '{' || s[i] == '('){
      stack.push(s[i]);
    }else{
      if(stack.empty()){
        return false;
      }else if(((s[i] == ']') && (stack.top()!= '['))
                  || ((s[i] == ')') && (stack.top()!='(')) || ((s[i] == '}') && (stack.top() != '{'))){
        return false;

      }else{
        stack.pop();
      }
    }
  }
  return (stack.empty()?true:false);
}
