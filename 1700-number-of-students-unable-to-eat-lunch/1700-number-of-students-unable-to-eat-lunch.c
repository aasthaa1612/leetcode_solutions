int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0};

    // Count students who prefer 0 and 1
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }

    // Serve sandwiches
    for (int i = 0; i < sandwichesSize; i++) {
        if (count[sandwiches[i]] == 0) {
            return sandwichesSize - i;
        }
        count[sandwiches[i]]--;
    }

    return 0;
}