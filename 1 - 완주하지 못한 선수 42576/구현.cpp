string solution(vector<string> participant, vector<string> completion) {  // ���� �ٸ��� �ϳ� ã���� ������ ������ ����
    string answer = "";
    vector<string> v1 = participant;
    vector<string> v2 = completion;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int flag = 1;
    int i;
    for (i = 0; i < v2.size(); i++) {
        if (v1[i] != v2[i]) {
            answer = v1[i];
            flag = 0;
        }
    }
    if (flag == 1) {
        answer = v1[i];
    }


    return answer;
}
