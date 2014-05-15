#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
void buildAllPermutations(vector<int> &num, vector<int> &curPermutation, map<int,bool> &included, vector<vector<int>> &result)
{
	if(num.size()==curPermutation.size()){
		result.push_back(curPermutation);
	}else{
		for(int i=0;i<num.size();i++)
		{
			if(included.find(num[i])==included.end())
			{
				included.insert(make_pair(num[i],true));
				curPermutation.push_back(num[i]);
				buildAllPermutations(num,curPermutation,included,result);
				curPermutation.pop_back();
				included.erase(included.find(num[i]));
			}
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int>> result;
	vector<int> curPermutation;
	map<int, bool> included;
	buildAllPermutations(num,curPermutation,included,result);
	return result;
}
int main(){
	vector<vector<int>> result;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	result = permute(num);
	return 0;
}
