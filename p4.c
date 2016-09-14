/*
 *  Assignment 4                            p4.c:                           Due August    ,2015
 * 
 *  This program reads in the settings that the user input and output certain graphs. The pyramid is basically a combination of two 
 *  triangles that have different direction.
 *
 *  The function menu displays the menu of this program.
 *  The function print_triangle prints out the triangle graph.
 *  The function print_pyramid prints out the pyramid graph.
 *  The function read_iteration reads the number and use it to adjust and create new triangle or pyramid.
 *  The function read_character reads the character and use it to output the triangle or pyramid using different character.
 *  
 *  The type int a stands for the number of rows of one triangle.
 *  The type int b stands for the number of columns of one triangle.
 *  The type int choice stands for the user's input.
 *  The type character stands for the character that is displayed in the triangle or pyramid.
 *  The type int iterations stands for the number of rows and columns of one triangle.
 *
 *
 */

#include <stdio.h>                      /* printf, scanf */
#include <ctype.h>                      /* isgraph */

void menu ( void )
{
    printf("Menu:\n1) Print Triangle\n2) Print Pyramid\n3) Change Line Length\n4) Change Symbolic Character\n5) Exit\n");
}

void print_triangle( int it, char ch)                //this is the function used to display the triangle graph
{
    int a, b;
    if ( it > 0 )                                 /*the if and else if enables us to switch the direction of triangle by 
                                                   entering positive of negative number it.*/
    {
        for ( a = 1 ; a <= it ; a++ )
        {
            for ( b = 1 ; b <= a ; b++ )
            printf("%c", ch);
            printf("\n");
        }
    }
    
    else if ( it < 0 )
    {
         for ( a = -it ; a > 0 ; a-- )
         {
            for ( b = 1 ; b <= a ; b++ )
            printf("%c", ch);
            printf("\n");
         }
    }
}

void print_pyramid( int it, char ch)                   //this is the function used to display the pyramid.
{
    int a;
    
    if ( it > 0 )
    {
        for ( a = 1 ; a <= it ; a++ )
        {
            print_triangle( it, ch);
            print_triangle(1-it, ch);
        }
    }
    
    else if ( it < 0 )
    {
        for ( a = -it ; a >= 1 ; a-- )
        {
            print_triangle( -it, ch);
            print_triangle( 1+it, ch);
        }
    }
}

int read_iterations( void )                           //this function read in the iteration of triangle.
{
    int iterations;                                 /* Stores user input */
    do                                              //this do-while loop makes sure that user can only input qualified number.
    {
        printf("Enter a positive or negative number of iterations: ");
        scanf("%d", &iterations);
        getchar();
        if ( iterations == 0 )                              //this if makes sure that there will be error report.
            printf("ERROR: Enter a valid positive or negative number!");
    }while ( iterations == 0 );
    return iterations;
}

char read_character ( void )
{
    char character;                                         /* Stores user input */
    int result;                                             /* Stores result of isgraph()*/
    do
    {
        printf("Enter an alphanumeric or symbolic character: ");
        scanf("%c", &character);
        getchar();
        result = isgraph(character);
        if ( result == 0 )
            printf("ERROR: Enter and alphanumeric or symbolic character");
    }while ( result == 0 );                                 /* Examing if the input is in the right range */
    return character;
}

int main ( void )
{
    int choice;                 /* Stores user input */
    char ch = '*';              /* Character modified by read_character() function */
    int it = -3;                /* Integer modified by read_iterations() function */
    
    menu();

    do
    {
        do
        {
        printf ("\nEnter a number (1-5) to choose an option from the menu above: " );
        scanf ("%d", &choice);
        getchar();
        if ( choice < 1 || choice > 5 )
            printf("ERROR: The input number must between 1 and 5");
        }while ( choice < 1 || choice > 5 );            //this do-while loop make sure that the input is in correct range.
        
        switch (choice)
        {
            case 1:
                print_triangle( it, ch);
                break;
            case 2:
                print_pyramid( it, ch);
                break;
            case 3:
                it = read_iterations ();
                break;
            case 4:
                ch = read_character();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                break;
        }
        
    }while ( choice != 5 );
    return 0;
}


