#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int maxProfit(vector<int> &prices) {
	/// special case
	if(prices.size()<=1) return 0;
     vector<int> profits;// one day buy, next day sell

	/// construct the profits in the stock
	for(int i=0;i<prices.size()-1;i++){
		profits.push_back(prices[i+1] - prices[i]);
	}

	/// calculate the maximun profit, which is the sum
	int profit=0;
	for(int i=0;i<profits.size();i++){
		if(profits[i]>0)
			profit += profits[i];
	}
	return profit;
    }
int main(){
	vector<int> prices;
	int price[] = {5,4,3,2,1};
	for(int i=0; i<sizeof(price)/sizeof(price[0]);i++)
		prices.push_back(price[i]);
	cout<<maxProfit(prices);
	return 0;
}
