#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> line;
int depth[20001]; // �Ÿ� 

vector<string> split(string str, char deli) {
    vector<string> inter;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, deli)) {
        inter.push_back(temp);
    }
    return inter;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> v;  // [i][0] ���̵�  [i][1] �г���
    vector<pair<string, string>> v2;
    int len = record.size(); // ���ڵ� ����

    for (int i = 0; i < len; i++) {
        int index = -1;
        vector<string> temp = split(record[i], ' ');  // ���ø��� [0] ��ɾ� [1] ���̵� [2] �г���

        if (v.find(temp[1]) != v.end()) {
            index = i;

        }

        if (temp[0] == "Enter") {

            v2.push_back({ temp[1], "���� ���Խ��ϴ�." });
            if (index == -1) {
                v.insert({ temp[1], temp[2] });
            }
            else {
                v[temp[1]] = temp[2];
            }
        }
        else if (temp[0] == "Leave") {

            v2.push_back({ temp[1], "���� �������ϴ�." });
            //if (index == -1) {
              //  v.insert({ temp[1], temp[2] });
            //}
        }
        else if (temp[0] == "Change") {
            v[temp[1]] = temp[2];
        }

    }
    for (int i = 0; i < v2.size(); i++) {
        string k;
        k = v[v2[i].first];
        k += v2[i].second;
        answer.push_back(k);
    }

    return answer;
}
