
int solution(vector<int> priorities, int location) {
    vector < pair<int, bool>> v1;
    for (int i = 0; i < priorities.size(); i++) {
        pair<int, int> p;
        p.first = priorities[i];
        p.second = false;
        if (location == i) {
            p.second = true;
        }
        v1.push_back(p); // 정렬후
    }
    vector<int> temp = priorities;
    sort(temp.begin(), temp.end());
    int pt = temp.size() - 1;
    int res = 0;
    while (1) { // 알고리즘이랑 똑같이함
        int t1 = v1[0].first;
        int t2 = v1[0].second;
        if (t1 == temp[pt - res]) {
            if (t2 == false) {
                v1.erase(v1.begin());
                res++;
            }
            else {
                res++;
                return res;
            }
        }
        else {
            v1.push_back(v1[0]);
            v1.erase(v1.begin());
        }

    }
    return 0;
}