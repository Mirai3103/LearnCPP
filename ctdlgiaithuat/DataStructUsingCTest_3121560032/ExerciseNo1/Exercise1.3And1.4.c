/*
 • Write a Program to demonstrate the concept of structure and array of structures 
 • Write a Program to demonstrate passing the structure and array of structures to  a function. 
*/

#include <stdio.h>
#include <string.h>

// define the student structure
typedef struct
{
    int rollNo;
    char name[20];
    float percentage ;
} Student;  

// function prototype
void inputStudent(Student *s);
void displayStudent(Student s);
void inputListStudent(Student studentList[], int n);
void displayListStudent(Student studentList[], int n);




// main function
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student studentList[n];

    inputListStudent(studentList, n);
    printf("\nyou entered the student record:\n");
    displayListStudent(studentList, n);

    return 0;
}

// function definition;
void inputStudent(Student *s)
{
    printf("Enter roll No: ");
    scanf("%d", &s->rollNo);
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter percentage: ");
    scanf("%f", &s->percentage);
}

void displayStudent(Student s)
{
    printf("%d %s %2.2f\n", s.rollNo, s.name, s.percentage); 
}

void inputListStudent(Student studentList[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter student %d: ", i + 1);
        inputStudent(&studentList[i]);
    }
}

void displayListStudent(Student studentList[], int n)
{
    printf("\n");
    int i;
    for (i = 0; i < n; i++)
    {
        displayStudent(studentList[i]);
    }
}
