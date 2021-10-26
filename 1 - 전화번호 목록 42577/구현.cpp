
bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> v1 = phone_book; // 정렬하면 첫글자 아스키 코드로 정렬함
    sort(v1.begin(), v1.end());
    string pre;
    for (int i = 1; i < v1.size(); i++) {
        int len = v1[i - 1].length();
        if (v1[i - 1] == v1[i].substr(0, len)) {

            return false;
        }
    }
    return answer;
}