#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, num2;
	int temp;
	cin >> num;
	
	vector<int> v;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> num2;
	for (int i = 0; i < num2; i++) {
		cin >> temp;
		if (binary_search(v.begin(), v.end(), temp))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
	}
}