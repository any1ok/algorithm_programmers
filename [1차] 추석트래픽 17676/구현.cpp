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

using namespace std;

int jisuf(int n) { // 자리수 확인하는 함수
    int k = 0;
    while (n != 0)
    {
        n = n / 10;
        ++k;
    }
    return k;

}


int solution(string s) {
    int answer = 0;
    int len = s.length();
    vector<int> v1(1001, 100001);
    if (len == 1) {
        return 1;
    }
    for (int i = 1; i < len / 2 + 1; i++) { //  i == 중복 체크할 문자열 길이
        int pull = len;
        string tmp = "1";
        int cnt = 1; // cnt == 중복된 개수 aa 일시 2개라서 1부터시작함
        int k = 1;
        int jisu = 0; // jisu == 자리값 - xxxxxxxxxxxy 10xy 의 경우 4자리라 체크해야됭
        for (int j = 0; j < len; j += i) {

            int length = 0;
            if (tmp == s.substr(j, i)) { // 중복된다면
                pull = pull - i;

                cnt++;
                if (jisuf(cnt) != jisu) {  // 자리수 올라가면 +1 해주는 로직
                    jisu++;
                    pull++;
                }
            }
            else {
                cnt = 1;
                jisu = 0;
            }
            tmp = s.substr(j, i);
        }
        v1[i] = pull;
    }
    return *min_element(v1.begin() + 1, v1.end()); // 최솟값값

}
int main() {
    string a;


    while (1) {
        cin >> a;

        cout << solution(a) << endl;;
    }


}