/*
 *  Assignment  3                  p3.c                    Due August 12, 2015
 *  login #:  cs5vae
 *
 *  This program calculates the amount of change from $1.00 in numbers of coins(quarters, dimes, nickels, and pennies) from a
 *  CHARGE BOX machine.
 *
 *  Type integer cents stands for the price of the device.
 *  Type integer change stands for the cents that the user will take out from the CHANGE BOX.
 *  Type integer quarter stands for the number of quarters that the user need to take out from the CHANGE BOX.
 *  Type integer dime stands for the number of dimes that the user need to take out from the CHANGE BOX.
 *  Type integer nickel stands for the number of nickels that the user need to take out from the CHANGE BOX.
 *  Type integer penny stands for the number of pennies that the user need to take out from the CHANGE BOX.
 *  Type double dollar has the same value as the integer change, but it is float number.
 *  Type character input stands for the character that the user type in that will decide if the program will run again.
 *  The defined VALDOL indicates how many cents a dollar values.
 *  The defined VALQUA indicates how many cents a quarter values.
 *  The defined VALDIM indicates how many cents a dime values.
 *  The defined VALNIC indicates how many cents a nickel values.
 *  The defined VALPEN indicates how many cents a penny values.
 */
 
#include <stdio.h>

#define VALQUA 25
#define VALDIM 10
#define VALNIC 5
#define VALPEN 1
#define VALDOL 100

int main( void )
{
    int cents, quarter, dime, nickel, penny, change;
    double dollar;
    char input;
    
    printf("This program calculates your change from CHARGING your mobile device.\n");
    
    do
    {

        do                                                 //this do-while loop examines if the price entered is in the range
        {
            printf("Enter price to CHARGE your device in cents(1-99): ");
            scanf("%d", &cents);
            getchar();
            
            if ( cents < 1 || cents > 99 )                //this if decision makes sure that there will be error report.
                printf ( "ERR: OUT of the RANGE of 1 through 99\n");
        }while ( cents < 1 || cents > 99 );
        
        change = VALDOL - cents;
        dollar =(double) change / VALDOL;                 //this procedure convert the integer ‘change’ into a float number.
        
        printf("Using if-else your change of $%.2lf is:\n", dollar);
        {
            quarter = change / VALQUA;                    //this procedure calculates how many quarters the user should take.
            if ( quarter == 0 )
                printf("");
            else if ( quarter == 1 )
                printf ("                                      1 QUARTER\n");
            else
                printf("                                      %d QUARTERS\n", quarter);
        
            dime = change % VALQUA / VALDIM;              //this procedure calculates how many dimes the user should take.
            if ( dime == 0 )
                printf("");
            else if ( dime == 1 )
                printf ("                                      1 DIME\n");
            else
                printf("                                      %d DIMES\n", dime);
        
            nickel = change % VALQUA % VALDIM / VALNIC;   //this procedure calculates how many nickels the user should take.
            if ( nickel == 0 )
                printf("");
            else if ( nickel == 1 )
                printf ("                                      1 NICKEL\n");
            else
                printf("                                      %d NICKELS\n", nickel);
        
            penny = change % VALQUA % VALDIM % VALNIC / VALPEN; /*this procedure calculates how many pennies the user should 
                                                                 take.*/
            if ( penny == 0 )
                printf("");
            else if ( penny == 1 )
                printf ("                                      1 PENNY\n");
            else
                printf("                                      %d PENNIES\n", penny);
        }
    
        quarter = dime = nickel = penny = 0;              //initialize the numbers before the second calculation using switch.
        printf("Using switch your change of $%.2lf is:\n", dollar);
        
        {
            quarter = change / VALQUA;                    //this procedure calculates how many quarters the user should take.
            
            switch ( quarter )
            {
                case 0:
                    printf("");
                    break;
                case 1:
                    printf ("                                      1 QUARTER\n");
                    break;
                default:
                    printf("                                      %d QUARTERS\n", quarter);
                    break;
            }
            
            dime = change % VALQUA / VALDIM;              //this procedure calculates how many dimes the user should take.
           
            switch ( dime )
            {
                case 0:
                    printf("");
                    break;
                case 1:
                    printf ("                                      1 DIME\n");
                    break;
                default:
                    printf("                                      %d DIMES\n", dime);
                    break;
            }
            
            nickel = change % VALQUA % VALDIM / VALNIC;   //this procedure calculates how many nickels the user should take.
            
            switch ( nickel )
            {
                case 0:
                    printf("");
                    break;
                case 1:
                    printf ("                                      1 NICKEL\n");
                    break;
                default:
                    printf("                                      %d NICKELS\n", nickel);
            }
            
            penny = change % VALQUA % VALDIM % VALNIC / VALPEN; /*this procedure calculates how many pennies the user should
                                                                 take.*/

            switch ( penny )
            {
                case 0:
                    printf("");
                    break;
                case 1:
                    printf ("                                      1 PENNY\n");
                    break;
                default:
                    printf("                                      %d PENNIES\n", penny);
                    break;
            }
        }
        
        do                                          //this do-while loop makes sure that the user can only input y, n, Y, N
        {
            printf("Want to CHARGE another device (y/n)?");
            input = 0 ;
            scanf("%c", &input);
            getchar();
        }while ( input != 'y' && input != 'n' && input != 'N' && input != 'n');

    }while ( input == 'y' || input == 'Y' );   /*When user input y or Y, program run again. On the contrary, if user input n
                                                or N, the program will stop immediately.*/
    return 0;
}
