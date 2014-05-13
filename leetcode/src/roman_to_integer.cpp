#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
 int romanToInt(string s) 
 {
        map<char,int> romanToInteger;
		romanToInteger.insert(make_pair('I',1));
		romanToInteger.insert(make_pair('V',5));
		romanToInteger.insert(make_pair('X',10));
		romanToInteger.insert(make_pair('L',50));
		romanToInteger.insert(make_pair('C',100));
		romanToInteger.insert(make_pair('D',500));
		romanToInteger.insert(make_pair('M',1000));

		int len = s.length();
		int result = 0;
		for(int i=0;i<len;i++)
		{
			if(i<len-1&&romanToInteger[s[i]]<romanToInteger[s[i+1]])
				result -= romanToInteger[s[i]];
			else
				result += romanToInteger[s[i]];
		}
		return result;
 }
int main(){
	cout<<romanToInt("I")<<romanToInt("V")
		<<romanToInt("X")<<romanToInt("IV")
		<<romanToInt("MDCLXVI");
	return 0;
}
