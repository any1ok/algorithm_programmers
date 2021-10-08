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
int depth[20001]; // 거리 

int solution(int n, vector<vector<int>> edge) {
    queue<pair<int, int>> q;
    int answer = 0;
    int len = edge.size();
    line.resize(n + 1);
    for (int i = 0; i < len; i++) {   // 양방향이기때문에 양방향으로 가는길 열어놔야됨
        int f, s;
        f = edge[i][0];
        s = edge[i][1];
        line[f].push_back(s);
        line[s].push_back(f);
    }
    q.push({ 1,0 }); //시작
    depth[1] = -1;  //체크하기
    while (!q.empty()) {
        pair<int, int> now;

        now = q.front();

        q.pop();

        for (int i = 0; i < line[now.first].size(); i++) { // bfs 간다!!
            if (depth[line[now.first][i]] != 0) {  // 헌본 간길이면 그냥 넘어감
                continue;
            }

            q.push({ line[now.first][i],now.second + 1 });  // 처음오면 해당 노드와 거리 넣고
            depth[line[now.first][i]] = now.second + 1; // 거리를 거리 배열에도 넣어준다

        }
    }
    int max = 0;  //밑에 두개는 최댓값 찾기
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