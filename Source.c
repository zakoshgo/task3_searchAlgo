#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int minimum(int firstElement, int secondElement){
    return (firstElement > secondElement) ? secondElement : firstElement;
}
int isSorted(int* userArray, int arraySize) {
    int checkFlag = 1;
    for (int index = 0; index < arraySize - 1; index++) {
        if (userArray[index] > userArray[index + 1])
            checkFlag = 0;
    }
    return checkFlag;
}
void insertionSorting(int* arrayToBeSorted, int size) {
    for (int step = 1; step < size; step++) {
        int key = arrayToBeSorted[step];
        int j = step - 1;

        while (key < arrayToBeSorted[j] && j >= 0) {
            arrayToBeSorted[j + 1] = arrayToBeSorted[j];
            --j;
        }
        arrayToBeSorted[j + 1] = key;
    }
}
int jumpSearch(int* array, int size, int key) {
    if (isSorted(array, size) == 0)
        insertionSorting(array, size);
    int step = sqrt(size);

    int prev = 0;
    while (array[minimum(step, size) - 1] < key)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size) // check if the array endded
            return -1;
    }
    // at this point the prev is less than the key and the step is larger than the key
    // linear search
    while (array[prev] < key)
    {
        prev++;
        if (prev == min(step, size))
            return -1;
    }

    if (array[prev] == key)
        return prev;

    return -1;

}


///////////////////////////driver////////////////////
int main() {
    int arraySize;
    int TargetKey;
    printf("enter the size of the array \n");
    scanf("%d", &arraySize);
    int* userArray = (int*)malloc(arraySize * sizeof(int));
    printf("enter the elements of the array \n");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &userArray[i]);
    }
    printf("enter the elements to be found \n");
    scanf("%d", &TargetKey);

    int foundIndex = jumpSearch(userArray, arraySize, TargetKey);
    if (foundIndex == -1)
        printf("key is not found \n");
    else
        printf("%d", foundIndex);


}