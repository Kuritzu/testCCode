#include <stdio.h>

void quickSortIterative(int array[], int left, int right) {
    int stack[right - left + 1];  //  auxiliary stack for segment limits
    int top = -1;  // signals top of stack (empty stack)
    // push limits of initial segment into the stack
    stack[++top] = left;
    stack[++top] = right;

    while (top > 0) {  // while stack not empty, get next segment and process it
        // Pop array segment limits
        left = stack[top--];
        right = stack[top--];
        // partition array segment [left,right] and finds pivot element
        int pivotval = array[right];
        int i = (left - 1);
        int tmp;
        // finds pivot position
        for (int j = left; j <= right - 1; j++)
            if (array[j] > pivotval) {
                i++;
                tmp = array[i];      // swaps array[i] with array[j]
                array[i] = array[j];
                array[j] = tmp;
            }
        // swap final array[i + 1] with array[right]
        tmp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = tmp;
        int p = (i + 1);  // p is the pivot position

        // Push left-side segment to stack
        stack[++top] = left;
        stack[++top] = p - 1;

        // Push right-side segment to stack
        stack[++top] = p + 1;
        stack[++top] = right;
    }
}
