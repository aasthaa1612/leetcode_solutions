int missingNumber(int* nums, int numsSize) {
    int sum = 0;

    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    int expected = numsSize * (numsSize + 1) / 2;

    return expected - sum;
}
