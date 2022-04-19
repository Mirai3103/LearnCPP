/*
• Write a Program to read in one dimensional , calculate the sum and display it  
    ⮚ Initialize the array of 10 elements  
    ⮚ Read the elements using a loop  
    ⮚ Add all the elements  
    ⮚ Display the contents of the array and the sum  
*/
#include <stdio.h>


// function prototype
void inputArray(int arr[], int n);
void displayArray(int arr[], int n);
int sumOfAllElements(int arr[], int n);


// main function
int main()
{
    int arr[10]; // Initialize the array of 10 elements 
    int  length =10, sum;
    inputArray(arr, length);// Read the elements and add this to array using a loop  
    displayArray(arr, length); // Display the contents of the array
    sum = sumOfAllElements(arr, length);  // calculate the sum of all elements
    printf("\nSum of all elements: %d", sum); // Display the sum of all elements
    return 0;
}

// function definition
void inputArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int sumOfAllElements(int arr[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}