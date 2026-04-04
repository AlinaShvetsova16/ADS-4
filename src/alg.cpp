// Copyright 2021 NNTU-CS
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
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            } else {
                int leftVal = arr[left];
                int leftCount = 0;
                while (left <= right && arr[left] == leftVal) {
                    leftCount++;
                    left++;
                }
                int rightVal = arr[right];
                int rightCount = 0;
                while (right >= left && arr[right] == rightVal) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
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
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        for (int j = i + 1; j < len; j++) {
            int left = j;
            int right = len - 1;
            bool found = false;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    found = true;
                    break;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (found) {
                int k = j;
                while (k < len && arr[k] == target) {
                    count++;
                    k++;
                }
                break;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}
