void reverse_array(int* arr, int size) {
    // Initialize the pointers
    int* left = arr;
    int* right = arr + size - 1;

    // Loop to swap the elements
    while (left < right) {
        // Swap the elements
        int temp = *left;
        *left = *right;
        *right = temp;

        // Move the pointers towards each other
        left++;
        right--;
    }
}
