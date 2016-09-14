/*
 * Assignment 1               p1.c:          Due August 8, 2015
 * login #:   cs5vae
 *
 * This program reads in student's information of: birth year,
 * GPA, and letter grade using int, double, and char data types.
 * Age is calculated from birth year.
 *
 * Type integer is used for the variables to hold the age and
 * year values. Type double is used to store the GPA.
 * Type char is used for the single character letter grade.
 *
 * Symbolic constant "THIS_YEAR" is used for current year.
 */

#include <stdio.h>
#define THIS_YEAR 2015

int main ( void )
{
    char grade;                    //Student's grade
    int birthyear;                 //Student's year of birth
    int age;                       //Student's age
    double gpa;                    //Student's gpa

    printf ("Enter your grade in the class: ");
    grade = getchar();             //Read single character input
    

    printf ("Enter your birthyear: ");
    scanf ("%d", &birthyear);           //Read integer input
    getchar();                          //Read <ENTER> key
    age = THIS_YEAR - birthyear;         //Calculate the age
    
    printf("Enter your GPA (Grade Point Average):");
    scanf ("%lf", &gpa);                   //Read long float input
    getchar();                          //Read <ENTER> key
    
    printf("I am %d years old with a GPA of %.1lf and a class grade of %c. \n", age, gpa, grade);
    
    printf ("In %d I will be %d. ", THIS_YEAR+1, ++age);
    printf ("If I study hard, I will get a fabulous grade of ++%c.\n", grade);
    return 0;
}