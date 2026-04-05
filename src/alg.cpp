// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = sorted_arr[left] + sorted_arr[right];
        if (sum == value) {
            if (sorted_arr[left] == sorted_arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_count = 1, right_count = 1;
                while (left + 1 < right && sorted_arr[left] == sorted_arr[left + 1]) {
                    left_count++;
            left++;
                }
                while (right - 1 > left && sorted_arr[right] == sorted_arr[right - 1]) {
            right_count++;
            right--;
                }
                count += left_count * right_count;
                left++;
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        auto range = std::equal_range(arr + i + 1, arr + len, target);
        count += range.second - range.first;
    }
    return count;
}
