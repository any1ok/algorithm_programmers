
bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> v1 = phone_book; // �����ϸ� ù���� �ƽ�Ű �ڵ�� ������
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