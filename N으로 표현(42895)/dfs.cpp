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

int answer = 9;
int N_input = 9;
int number_input = 9;

void dfs(int now, int depth) {
    if (depth > 8) { // 8이상이면 
        return;
    }
    if (now == number_input) { //해당숫자와 같은경우중
        answer = min(depth, answer); //  depth 가 가장 낮은값
        return;
    }
    int temp = 0;
    for (int i = 0; i + depth < 9; i++) {
        temp = temp * 10 + N_input; // 5 55 555 5555
        dfs(now + temp, depth + i + 1);
        dfs(now - temp, depth + i + 1);
        dfs(now * temp, depth + i + 1);
        dfs(now / temp, depth + i + 1);
    }
}


int solution(int N, int number) {
    N_input = N;
    number_input = number;
    dfs(0, 0);
    if (answer == 9) return -1;
    return answer;
}


