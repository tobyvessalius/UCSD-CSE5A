/* 
 *  Assignment  2                     p2.c                           Due August 12,2015
 *  login #:   cs5vae
 *
 *  This is a program reads in user's hourly wage and monthly rent both in double types. Then it will calculate the gross wage 
 *  for a number of weeks using algorithm. Also it will calculate the federal tax that the user have to pay using another
 *  algorithm. Last but not least, it will calculate the net wage left for the user. Additionally, it will calculate the money 
 *  left after paying the rent.
 *
 *  Type double hourly stands for the hourly wage.
 *  Type double rent stands for the rent user have to pay monthly
 *  Type double gross stands for the gross.
 *  Type double fedtax stands for the federal tax that the user have to pay.
 *  Type double net stands for the net wage of the user.
 *  Type double grosssub stands for the subtotal of gross.
 *  Type double fedtaxsub stands for the subtotal of federal tax.
 *  Type integer week stands for the number of the week that the user have been working.
 *  Type character input is used to decide whether this programme should start from the beginning again and again.
 *  The defined constant HRS_PER_WEEK stands for the hours that the user works per week.
 *  The defined constant NUM_WEEKS stands for the numbers that the users worked.
 *  The defined constant FED_TAX_RATE stands for the rate of the federal tax.
 *  The defined constant MAX_HOURLY stands for the maximum hourly wage.
 *  The defined constant MIN_HOURLY stands for the minimum hourly wage.
 *  The defined constant MAX_RENT stands for the maximum rent the user have to pay monthly.
 *  The defined constant MIN_RENT stands for the minimum rent the user have to pay monthly.
 */

#include <stdio.h>

#define HRS_PER_WEEK  40
#define NUM_WEEKS     4
#define FED_TAX_RATE  0.13
#define MAX_HOURLY    100
#define MIN_HOURLY    1
#define MAX_RENT      1000
#define MIN_RENT      0

int main(void)
{
    double hourly , rent , gross , fedtax , net , grosssub , fedtaxsub ;
    int week ;
    char input ;
    
        do
        {
            hourly = 0;                                                                   //initialize the user's hourly wage
            rent = 0;                                                                     //initialize the user's monthly rent
            input = 0;                                                                    //initialize the input
          
            do
            {
                printf( "Enter your houly wage (1-100) for payroll:" );                   //instruct user to type in the payroll
                scanf( "%lf", &hourly);                                                   //receive the user's payroll
                getchar();
            }while ( hourly < MIN_HOURLY || hourly > MAX_HOURLY);                         /*this do-while loop makes sure that the
                                                                                           input hourly wage is in the correct range(error check)*/
            do
            {
                printf( "\nEnter your monthly rent (0-1000):");                           //instruct user to type in the payroll
                scanf( "%lf", &rent);                                                     //receive the user's rent
                getchar();
            }while ( rent < MIN_RENT || rent > MAX_RENT);                                 /*this do-while loop makes sure that the
                                                                                           input rent is in the correct range(error check)*/
            
            printf("*********************EARNED WAGES*************************\n");       //this is the title of the table
            printf(" Week    Gross_Wages      FEDTax    Net_wages - while loop\n");       //this is the items of the table
            printf("==========================================================\n");
    
            week = 1 ;                                                                    //initialize the week
            grosssub = 0 ;                                                                //initialize the gross subtotal
            fedtaxsub =0 ;                                                                //initialize the federal tax subtotal
            
            while ( week < 5 )                                                        /*start the while loop and set up
                                                                                      the condition that enables the loop*/
            {
                gross = hourly * HRS_PER_WEEK;                                        //set up the algorithm of gross
                fedtax = gross * FED_TAX_RATE;                                        //set up the algorithm of federal tax
                grosssub += gross ;                                                   //set up the algorithm of gross subtotal
                fedtaxsub += fedtax ;                                                 //set up the algorithm of federal tax subtotal
                net = grosssub - fedtaxsub ;                                          //set up the algorithm of net wage
                printf("%3d%13.2lf%16.2lf%17.2lf\n", week , grosssub , fedtaxsub , net );//display the data of the table
                week += 1 ;                                                           //change the counter(using increment)
            }
    
            printf("\n Week    Gross_Wages      FEDTax    Net_wages - for loop\n");   //this is the items of the table
            printf("==========================================================\n");
            grosssub = 0 ;                                                            //initialize the gross subtotal
            fedtaxsub =0 ;                                                            //initialize the federal tax subtotal
    
            for ( week = 1 ; week < 5 ; ++week)                            /*start the for loop and initialize the week, set up the
                                                                           condition that enables the loop and set up the way to 
                                                                           change the counter*/
            {
                gross = hourly * HRS_PER_WEEK;                                        //set up the algorithm of gross
                fedtax = gross * FED_TAX_RATE;                                        //set up the algorithm of federal tax
                grosssub += gross ;                                                   //set up the algorithm of gross subtotal
                fedtaxsub += fedtax ;                                                 //set up the algorithm of federal tax subtotal
                net = grosssub - fedtaxsub ;                                          //set up the algorithm of net wage
                printf("%3d%13.2lf%16.2lf%17.2lf\n", week , grosssub , fedtaxsub , net );//display the data of the table
            }
          
            printf("\n Week    Gross_Wages      FEDTax    Net_wages - for loop\n");   //this is the items of the table
            printf("==========================================================\n");
            grosssub = 0 ;                                                            //initialize the gross subtotal
            fedtaxsub =0 ;                                                            //initialize the federal tax subtotal
            week = 1 ;                                                                //initialize week
           
            do                                                                        //the start of a do loop
            {
                gross = hourly * HRS_PER_WEEK;                                        //set up the algorithm of gross
                fedtax = gross * FED_TAX_RATE;                                        //set up the algorithm of federal tax
                grosssub += gross ;                                                   //set up the algorithm of gross subtotal
                fedtaxsub += fedtax ;                                                 //set up the algorithm of federal tax subtotal
                net = grosssub - fedtaxsub ;                                          //set up the algorithm of net wage
                printf("%3d%13.2lf%16.2lf%17.2lf\n", week , grosssub , fedtaxsub , net );//display the data of the table
                week += 1 ;                                                           //change the counter
            }while ( week < 5 );
    
            printf("Spending money after %.2lf rent is: $%.2lf\n", rent , net - rent );//display the summary of the data
          
            do                                            //this do-while loop is used to limit the input to 'y' or 'n'(error check)
            {
                printf("Want to generate another payroll (y/n)?");                      /*display the instruction that asks us
                                                                                        if we want to generate another payroll*/
                input = 0;
                scanf("%c", &input);
                getchar();
            }while ( input != 'y' && input != 'n' );      //if user input charater other than y or n, it will activate the loop
        }while ( input == 'y' );                          //if user input y, the program will run again and create payroll again.
    return 0;
}

