string solution(vector<string> participant, vector<string> completion) {  // 꿀팁 다른값 하나 찾을땐 정렬이 굉장히 좋다
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
