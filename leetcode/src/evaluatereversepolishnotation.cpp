#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
using namespace std;

/*
 * exmaples
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

static char op[] = "+-*/";

bool isInOperatorSet(char c){

	for(int i=0;i<strlen(op);i++)
		if(op[i] == c) return true;
	return false;
}

bool isOperator(string s){
	if(s.size()<=1&&isInOperatorSet(s[0]))
		return true;
	else 
		return false;

}

int getValue(string s){
	return atoi(s.c_str());
}

int getOperator(string s){
	for(int i=0;i<strlen(op);i++)
		if(op[i] == s[0]) return i;
	return -1;// operator is no in set
}
int manipulate(int a, int b, int type){
	int result = 0;
	switch(type){
	case 0:// op +
		result = a + b;
		break;
	case 1:
		result = a - b;
		break;
	case 2://op *
		result = a * b;
		break;
	case 3:
		result = a/b;
		break;
	default:
		break;
	}
	return result;
}
int evalRPN(vector<string> &tokens) {
        stack<int> polishNotion; //store the values
		if(tokens.size()<=0) return 0;

		for(int i=0;i<tokens.size();i++){
			if(isOperator(tokens[i])){ // operator
				int b = polishNotion.top();polishNotion.pop();
				int a = polishNotion.top();polishNotion.pop();
				polishNotion.push(manipulate(a,b,getOperator(tokens[i])));
			}else{
				polishNotion.push(getValue(tokens[i]));
			}
		}
		return polishNotion.top();
    }
int main(){

	vector<string> tokens;
	string list[] = {"4","-2","/","2","-3","-","-"};// = {"2", "1" ,"+" , "3", "*"};
	for(int i=0;i<5;i++) tokens.push_back(list[i]);
	int result = evalRPN(tokens);
	cout<<result<<endl;
	return 0;
}
