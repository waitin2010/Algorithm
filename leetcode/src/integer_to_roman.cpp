#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
string intToRoman(int num) 
 {
      string str;
        map<int,string> data;
        data.insert(make_pair(1,"I"));
		data.insert(make_pair(4,"IV"));
        data.insert(make_pair(5,"V"));
		data.insert(make_pair(9,"IX"));
        data.insert(make_pair(10,"X"));
		data.insert(make_pair(40,"XL"));
        data.insert(make_pair(50,"L"));
		data.insert(make_pair(90,"XC"));
        data.insert(make_pair(100,"C"));
		data.insert(make_pair(400,"CD"));
        data.insert(make_pair(500,"D"));
		data.insert(make_pair(900,"CM"));
        data.insert(make_pair(1000,"M"));
        int d[13] = {0};
        int s[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<13;i++){
			while(num/s[i])
			{
				d[i] = num/s[i];
				num = num - s[i]*d[i];
			}
		}
        for(int i=0;i<13;i++){
            for(int j=0;j<d[i];j++)
                str += data[s[i]];
        }
        return str;
 }
int main(){
	cout<<intToRoman(1066).c_str();
	return 0;
}
