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

vector<string> Split(string str, char delim) {
    vector<string> ret;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delim)) {
        ret.push_back(temp);
    }
    return ret;
}


int solution(vector<string> lines) {
    vector<string> temp; // 임시 저장소
    vector<int> start_point; // 완료 시간
    vector<int> end_point; // 시작 시간

    int size = lines.size();
    int start_p;
    int end_p;
    int doing;
    for (int i = 0; i < size; i++) {
        temp = Split(lines[i], ' ');
        end_p = stoi(Split(temp[1], ':')[0]) * 3600000 + stoi(Split(temp[1], ':')[1]) * 60000 + stof(Split(temp[1], ':')[2]) * 1000;

        end_point.push_back(end_p);
        doing = stof(temp[2]) * 1000 - 1; // 진행시간
        start_point.push_back(end_p - doing);

    }
    int check;
    int answer = 0;
    for (int i = 0; i < size; i++) {
        check = 0;

        // 범위는 시작시점의 1초 전이다.
        int range = start_point[i] - 999;
        for (int i = 0; i < size; ++i)
        {
            // --------------------------------------------------------- 시작 시점 검사

            // 저장소 초기화 && 본인추가
            check = 0;

            // 범위는 시작시점의 1초 전이다.
            int range = start_point[i] - 999;

            for (int j = 0; j < size; ++j)
            {
                // 1. 시작포인트가 범위에 포함하는 경우 종료시점은 무관하다.) 시작지점이 범위보다 크거나 같고 현재 시작지점보다 작을 경우 
                // 2. 시작포인트가 범위 이전에 있지만 종료시점이 범위 이상에 있는 경우 ) 
                if (range <= start_point[j] && start_point[j] <= start_point[i])
                    check++;
                else if (range >= start_point[j] && end_point[j] >= range)
                    check++;
            }

            // 최대 요청량 갱신
            if (answer < check)
                answer = check;
        }

        return answer;



    }
}

