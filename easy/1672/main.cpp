//https://leetcode.com/explore/featured/card/the-leetcode-beginners-guide/692/challenge-problems/4423/
#include <iostream>
#include <set>

int maximumWealth(std::vector<std::vector<int>>& accounts) {
	int max_wealth = 0;
	std::set<int> s;

	for (int i = 0; i < accounts.size(); i++) {
		max_wealth = 0;
		for (int j = 0; j < accounts[i].size(); j++) {
			max_wealth = max_wealth + accounts[i][j];
		}
		s.insert(max_wealth);
	}

	return *s.rbegin();
}

void check_answer(int sol, int my_sol) {
	if (sol == my_sol) {
		std::cout << "Equal\n";
	} else {
		std::cerr << "Failure\n";
	}
}

int main() {
	std::cout << "Init..." << std::endl;

	// Example 1
	std::vector<std::vector<int>> account_1 = {{1,2,3},
											   {3,2,1}};
	int ans_1 = 6;

	// Example 2
	std::vector<std::vector<int>> account_2 = {{1,5},
											   {7,3},
											   {3,5}};
	int ans_2 = 10;

	// Example 3
	std::vector<std::vector<int>> account_3 = {{2,8,7},
											   {7,1,3},
											   {1,9,5}};
	int ans_3 = 17;
	
	// Testing...
	int my_ans_1 = maximumWealth(account_1);
	check_answer(ans_1, my_ans_1);

	int my_ans_2 = maximumWealth(account_2);
	check_answer(ans_2, my_ans_2);

	int my_ans_3 = maximumWealth(account_3);
	check_answer(ans_3, my_ans_3);

	return 0;
}
