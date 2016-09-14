/*
 *  Assignment  6                       p6.c:                                   Due August 29, 2015
 *  login #:  cs5vae
 *
 *  This program will use functions and a one-dimensional array to sort and print lowest and highest of temperatures.
 *  Also one important algorithm used in this program is bubble sort.
 *
 *  The defined numbers and characters are aimed at avoiding hard coding.
 *  The function bubbleSort is used to sort the value in the array and makes sure that they are in the right direction from the smallest to the biggest.
 *  The function swap use pointers to store two addresses of two values that are passed as parameter. Then it will swap the value of these two numbers using a temporary character temp.
 *  The function readInput use for loop to receive the user's input and store them in array if the numbers matche the requirement of range.
 *
 */

#include <stdio.h>

#define NUM_TEMP 6
#define n 'n'
#define N 'N'
#define min 0
#define max 100

void bubbleSort( double a[] );
void swap (double *p, double *q);
void readInput (double a[]);

/*
 *  This function have no parameter, but it does all the work of printing out the results and calls other 2 functions: readInput(weather) and bubbleSort(weather). Also it uses array to store the values of temperature.
 */
int main()
{
    int i, firstRun = 1;
    char input;
    double weather[NUM_TEMP] = {77.7, 55.5, 88.8, 99.9, 66.6, 100};
    
    do
    {
        if(firstRun)                        //This if-else is used to make sure that the default temperatures will only print out once.
            firstRun = 0;
        else
            readInput(weather);             //The program will read the temperatures that the user input after the first time.
        
        printf("        Temperatures:");
        
        for ( i = 0 ; i < NUM_TEMP ; i++ )  //I use the for loop to print out the values stored in array weather[].
            printf("%7.1lf", weather[i]);
        
        bubbleSort(weather);                //Function main() calls function bubbleSor(weather) to sort the values in array weather[].
        
        printf("\n        Sorted:      ");
        
        for ( i = 0 ; i < NUM_TEMP ; i++ )  //I use the for loop to print out the sorted values stored in array weather[].
            printf("%7.1lf", weather[i]);
        
        printf("\n        Lowest:        %5.1lf\n        Highest:       %5.1lf\n", weather[0], weather[5]);
        
        printf("Want to calculate temperatures?");//This is an instruction that suggest user to input something in order to decide if the program need to run again.
        scanf("%c", &input);                //The program receive the character that the user input.
        getchar();
        
    }while ( input != n && input != N );    //If user input n or N, the program will stop. Other wise it will run again.
    
    return 0;
}

/*
 *  This function pass the array as parameter and let user input numbers which are ensured in range to replace the number that was stored in the array.
 */
void readInput (double a[])
{
    double num = 0.0;                       //Initialize the num. It is a variable used to temporarily store the value that the user input.
    int x;
    for ( x = 0 ; x < NUM_TEMP ; x++ )
        {
        printf("ENTER Temperature #%d:  ", x+1 );//Instruct user to input the value of temperature.
        scanf("%lf", &num);                 //Receive the value of temperature.
        getchar();
            
        if ( num < min || num > max )
            {
            printf("ERROR! Enter a number (0-100)!\n");//If the value is out of range, there will be an error report and the x will decrease.
            x--;
            }
        else
            a[x] = num ;                    //If the value is in the correct range, it will be stored in the array.
        }
}

/*
 *  This function pass the array as parameter and sort it as a direction from the smallest to the biggest.
 *  Also this function will call function swap.
 */
void  bubbleSort( double a[] )
{
    int  i, j;
    for(i = 0 ; i < NUM_TEMP-1 ; ++i)
        for(j = NUM_TEMP-1 ; i < j ; --j)
            if( a[j-1] > a[j] )
                swap(&a[j-1], &a[j]);       //In order to swap the two value, this function need to call function swap.
}

/*
 *  This function pass the address of two values in array as parameter and swap them using pointer.
 */

void swap (double *p, double *q)
{
    double temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
