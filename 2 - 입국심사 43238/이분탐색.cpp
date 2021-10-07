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
using namespace std;





long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long temp = 1000000000;
    long long right = temp * n;
    long long left = 1;
    long long len = times.size();
    long long result = right;

    // 시간을 기준으로 이분탐색
    while (left <= right) {
        long long sum = 0;
        long long mid = (right + left) / 2;
        for (long long i = 0; i < len; i++) {
            sum += mid / times[i];
        }
        if (sum >= n) {
            right = mid - 1;  
            result = min(result, mid); // 가장 작은값을 리턴한다 solution( 2 , [1,2,2,2,100]) 의 경우 mid 가 2 일때 정답이지만 sum 은 5이다 5!=2 이지만 정답이지 아니한가  
        }
        else {
            left = mid + 1;
        }
    }
    answer = result;
    return answer;
}
