// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int count;
  for (int i = 0; i < len - 1; i++) {
    for (int k = i + 1; k < len; k++) {
      if (arr[i] + arr[k] == value) {
        count = count + 1;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int tail1;
  int count = 0;
  tail1 = len - 1;
    while (arr[tail1] > value) {
      tail1 = tail1 - 1;
    }
  for (int i = 0; i < tail1 - 1; i++) {
    for (int k = tail1; k > i; k--) {
      if (arr[i] + arr[k] == value) {
        count = count + 1;
      }
    }
  }
      return count;
}

int bin_search(int* arr, int begin, int len, int value) {
    int count = 0, i = begin, end = len - 1, midd, tmp;
    while (i <= end) {
        midd = i + (end - i) / 2;
        if (arr[midd] == value && midd != begin && midd != len) {
            count++;
            tmp = midd;
            while (arr[--midd] == value && midd > begin) count++;
            while (arr[++tmp] == value && tmp < len) count++;
            break;
        } else if (arr[midd] > value) {
            end = midd - 1;
        } else {
            i = midd + 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
int count = 0;
  for (int i = 0; i < len; i++) {
  count = count +  bin_search(arr, i, len, value - arr[i]);
  }
  return count;
}
