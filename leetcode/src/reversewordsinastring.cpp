#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
using namespace std;
/*
 * help function from string library
 * string &append(const string &s,int pos,int n);//把字符串s中从pos开始的n个字符连接到当前字符串的结尾
*/
void reverseWords(string &s) {
        string word; // current word
		int len; // the length of s
		int start, end; // the start and end of the current word
		stack<string> words;// store the words in the s

		len = s.length();
		if(len<=0)
			return ; // special case for null

		for(int i=0;i<len;i++){
			while(i<len&&s[i]==' ') i++; // find the first letter of the current word
			if(i>=len) break;
				start = i;
			while(i<len&&s[i]!=' ')  i++; // find the last letter of the current word
			end = i;

			word.assign(s,start, end - start);
			words.push(word);
		}
		s.clear();
		if(!words.empty()){
			s = words.top();
			words.pop();
			while(!words.empty()){
				s += " " + words.top();
				words.pop();
			}
		}
    }
int main(){
	string a = "  ";
	
	reverseWords(a);
	cout<< a.c_str()<<endl;
	return 0;
}
