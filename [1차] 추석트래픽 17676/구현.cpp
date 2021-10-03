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
    vector<string> temp; // �ӽ� �����
    vector<int> start_point; // �Ϸ� �ð�
    vector<int> end_point; // ���� �ð�

    int size = lines.size();
    int start_p;
    int end_p;
    int doing;
    for (int i = 0; i < size; i++) {
        temp = Split(lines[i], ' ');
        end_p = stoi(Split(temp[1], ':')[0]) * 3600000 + stoi(Split(temp[1], ':')[1]) * 60000 + stof(Split(temp[1], ':')[2]) * 1000;

        end_point.push_back(end_p);
        doing = stof(temp[2]) * 1000 - 1; // ����ð�
        start_point.push_back(end_p - doing);

    }
    int check;
    int answer = 0;
    for (int i = 0; i < size; i++) {
        check = 0;

        // ������ ���۽����� 1�� ���̴�.
        int range = start_point[i] - 999;
        for (int i = 0; i < size; ++i)
        {
            // --------------------------------------------------------- ���� ���� �˻�

            // ����� �ʱ�ȭ && �����߰�
            check = 0;

            // ������ ���۽����� 1�� ���̴�.
            int range = start_point[i] - 999;

            for (int j = 0; j < size; ++j)
            {
                // 1. ��������Ʈ�� ������ �����ϴ� ��� ��������� �����ϴ�.) ���������� �������� ũ�ų� ���� ���� ������������ ���� ��� 
                // 2. ��������Ʈ�� ���� ������ ������ ��������� ���� �̻� �ִ� ��� ) 
                if (range <= start_point[j] && start_point[j] <= start_point[i])
                    check++;
                else if (range >= start_point[j] && end_point[j] >= range)
                    check++;
            }

            // �ִ� ��û�� ����
            if (answer < check)
                answer = check;
        }

        return answer;



    }
}

