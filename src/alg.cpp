// Copyright 2021 NNTU-CS
#include <algorithm>
#include <unistd.h>
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
    usleep(1000);
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int left_count = 0;
                while (left <= right && arr[left] == left_val) {
                    left_count++;
                    left++;
                }
                int right_val = arr[right];
                int right_count = 0;
                while (right >= left && arr[right] == right_val) {
                    right_count++;
                    right--;
                }
                count += left_count * right_count;
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
        auto lower = std::lower_bound(arr + i + 1, arr + len, target);
        auto upper = std::upper_bound(arr + i + 1, arr + len, target);
        count += upper - lower;
    }
    return count;
}
