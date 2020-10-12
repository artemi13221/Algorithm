#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	vector<vector<string>> r;
	vector<string> v;
	r.resize(51);
	string temp = "";
	int temp2 = 0;
	int size = 0;
	cin >> size;
	cin.clear();
	cin.ignore();
	
	for (int i = 0; i < size; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < size; i++) {
		temp2 = v[i].length();
		r[temp2].push_back(v[i]);
	}
	
	for (int i = 0; i < 51; i++) {
		sort(r[i].begin(), r[i].end());
		r[i].erase(unique(r[i].begin(), r[i].end()), r[i].end());
	}

	for (int i = 0; i < 51; i++) {
		for (size_t j = 0; j < r[i].size(); j++)
			cout << r[i][j] << "\n";
	}
}