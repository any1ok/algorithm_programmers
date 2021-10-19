#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<list>
#include<string>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<random>
#include<complex>
#include<algorithm>

using namespace std;


string solution(int n) {
	char coun[3];
	coun[0] = '4';
	coun[1] = '1';
	coun[2] = '2';
	string answer = "";
	int gap = n;
	int namo;

	while (gap) {
		answer = coun[gap % 3] + answer;
		if (gap % 3 == 0) {
			gap = (gap / 3) - 1;
		}
		else {
			gap = gap / 3;
		}
	}

	return answer;
}



int main() {
	int a;
	cin >> a;
	cout << solution(a);

}

