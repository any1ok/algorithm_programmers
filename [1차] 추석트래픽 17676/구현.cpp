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

int jisuf(int n) { // �ڸ��� Ȯ���ϴ� �Լ�
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
    for (int i = 1; i < len / 2 + 1; i++) { //  i == �ߺ� üũ�� ���ڿ� ����
        int pull = len;
        string tmp = "1";
        int cnt = 1; // cnt == �ߺ��� ���� aa �Ͻ� 2���� 1���ͽ�����
        int k = 1;
        int jisu = 0; // jisu == �ڸ��� - xxxxxxxxxxxy 10xy �� ��� 4�ڸ��� üũ�ؾ߉�
        for (int j = 0; j < len; j += i) {

            int length = 0;
            if (tmp == s.substr(j, i)) { // �ߺ��ȴٸ�
                pull = pull - i;

                cnt++;
                if (jisuf(cnt) != jisu) {  // �ڸ��� �ö󰡸� +1 ���ִ� ����
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
    return *min_element(v1.begin() + 1, v1.end()); // �ּڰ���

}
int main() {
    string a;


    while (1) {
        cin >> a;

        cout << solution(a) << endl;;
    }


}