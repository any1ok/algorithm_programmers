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





string solution(string sentence) {
	string answer = "";
	int len = sentence.length();

	vector<char> imogi;
	vector<string> word;
	int k = 0;
	char before_char = 0;
	for (int i = 0; i < len; i++) {
		char start_char = 0;
		char mid_char = 0;
		string temp = "";
		while (1) {
			if (sentence[i] < 'a') {
				if (before_char < 'a' && mid_char != 0) {
					before_char = 0;
					i--;
					break;
				}

				temp.append(sentence[i], 1);
				before_char = sentence[i];
			}
			else {
				for (int j = 0; j < imogi.size(); i++) {
					if (imogi[i])
				}
				if (temp.length() == 0) { // 0번째 소문자
					start_char = sentence[i];

				}
				else if (start_char == sentence[i]) { // 마무리
					start_char = 0;
					mid_char = 0;
					break;
				}
				else if (mid_char == 0) { // 중간짜리
					mid_char = sentence[i];
				}
				else if (before_char >= 'a') { // 소문자 연속두개
					before_char = 0;
					return "invalid";
				}


			}

			before_char = sentence[i];
		}
		if (start_char != 0) {
			return "invaild";
		}
		k++;
	}
	return answer;
}

int main() {
	string a;
	cin >> a;
	cout << solution(a);

}

