using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = { 1,2,3,4,5 };
    int a_len = 5;
    int a_p = 0;
    int b[8] = { 2,1,2,3,2,4,2,5 };
    int b_len = 8;
    int b_p = 0;
    int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int c_len = 10;
    int c_p = 0;
    int q = 0, w = 0, e = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a[q]) {
            a_p++;
        }
        if (answers[i] == b[w]) {
            b_p++;

        }
        if (answers[i] == c[e]) {
            c_p++;
        }
        q++;
        w++;
        e++;
        if (q == a_len) {
            q = 0;
        }
        if (w == b_len) {
            w = 0;
        }
        if (e == c_len) {
            e = 0;
        }

    }
    int gap = max(a_p, max(b_p, c_p));
    if (gap == a_p) {
        answer.push_back(1);
    }
    if (gap == b_p) {
        answer.push_back(2);
    }
    if (gap == c_p) {
        answer.push_back(3);
    }

    return answer;
}

