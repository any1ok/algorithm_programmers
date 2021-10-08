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

int solution(int n, vector<vector<int>> edge) {
    queue<pair<int, int>> q;
    int answer = 0;
    int len = edge.size();
    line.resize(n + 1);
    for (int i = 0; i < len; i++) {   // ������̱⶧���� ��������� ���±� ������ߵ�
        int f, s;
        f = edge[i][0];
        s = edge[i][1];
        line[f].push_back(s);
        line[s].push_back(f);
    }
    q.push({ 1,0 }); //����
    depth[1] = -1;  //üũ�ϱ�
    while (!q.empty()) {
        pair<int, int> now;

        now = q.front();

        q.pop();

        for (int i = 0; i < line[now.first].size(); i++) { // bfs ����!!
            if (depth[line[now.first][i]] != 0) {  // �庻 �����̸� �׳� �Ѿ
                continue;
            }

            q.push({ line[now.first][i],now.second + 1 });  // ó������ �ش� ���� �Ÿ� �ְ�
            depth[line[now.first][i]] = now.second + 1; // �Ÿ��� �Ÿ� �迭���� �־��ش�

        }
    }
    int max = 0;  //�ؿ� �ΰ��� �ִ� ã��
    for (int i = 0; i <= n; i++) {
        if (max < depth[i])
            max = depth[i];
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (max == depth[i])
            cnt++;
    }
    answer = cnt;
    return answer;
}