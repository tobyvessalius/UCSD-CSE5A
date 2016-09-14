/* Assignment 0                    p0.c                    Due Aug 4, 2015
 * login:  cs5vae
 *
 * This program converts from inches to feet. The user will type in one whole number. Type integer
 * is used for the variable to hold the inches value. Type double is used to calculate the number of
 * feet. The program will print out the input number of inches and display the computed value in feet.
 */


#include <stdio.h>

#define INCH_PER_FOOT   12.0                // Constant conversion factor

double inchToFeet( int inch );           // Function declaration

/*
 *  Driver for function inchToFeet().  Reads user input.
 */

int main(void)
{
    int     inches= 0;                   // Initialize to zero values
    double  feet  = 0;                   // Converted value
    
    do
    {
        printf("Enter a positive whole number in inches for conversion to feet: ");
        scanf("%d", &inches );
    }while ( inches < 0 ) ;
    
    feet = inchToFeet( inches );
    printf("%d inches are equal to %lf feet.\n", inches, feet );
    
    return 0;
}

/*
 * Function inchToFeet() computes the value of feet using a symbolic constant.
 * The function returns the number in feet type double
 */

double inchToFeet( int inch )
{
    double ft;                                          // Local variable, converted value
    ft = inch / INCH_PER_FOOT;
    return ft;

}
