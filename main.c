#include <stdio.h>
#include <ctype.h>

#define A 'A'
#define B 'B'
#define C 'C'
#define D 'D'
#define E 'E'
#define F 'F'
#define a 'a'
#define b 'b'
#define c 'c'
#define d 'd'
#define e 'e'
#define f 'f'
#define Dif 97-65
#define n 'n'
#define N 'N'

void rotate(char *p1, char *p2, char *p3, char *p4);//Declaration of function rotate
void uppercase(char *p);//Declaretion of function uppercase
char average(char n1, char n2, char n3, char n4);//Declaration of function average

int main() //This is the main function
{
    char c1, c2, c3, c4, input;
    int x;
    
    do//do loop to determine whether you want another input
    {
        do//do loop to make sure the input is in the correct range
        {
            printf ("Enter 4 letter grades to rotate and find the average:  ");
            scanf ("%c %c %c %c", &c1, &c2, &c3, &c4);
            getchar();
            if ( c1 == E || c1 == e || c2 == E || c2 == e || c3 == E || c3 == e || c4 == E || c4 == e )
                printf ("ERR: Grade is out of range(A-D, F)!");
        }while ( c1 == E || c1 == e || c2 == E || c2 == e || c3 == E || c3 == e || c4 == E || c4 == e );
        
        if ( c1 >= 97 )
            uppercase(&c1);
        
        if ( c2 >= 97 )
            uppercase(&c2);
        
        if ( c3 >= 97 )
            uppercase(&c3);
        
        if ( c4 >= 97 )
            uppercase(&c4);
        
        for( x = 1 ; x <= 4 ; x++ )
        {
            rotate(&c1, &c2, &c3, &c4);
            printf("Grades Rotated #%d:              %c %c %c %c\n", x, c1, c2, c3,c4);
        }
        
        printf("AVERAGE grade is:  %c\n", average( c1 , c2 , c3 , c4 ));
        
        printf("Want to calculate more grades?");
        scanf("%c", &input);
        getchar();
        
    }while( input != n && input != N );
    
    return 0;
}
/*
 * main() calls uppercase() to convert lowercase to uppercase
 */
void uppercase(char *p)//Definition of function uppercase
{
    *p -= Dif;
}
/* 
 * main() calls rotate() to complete the letter-rotation process
 */
 void rotate(char *p1, char *p2, char *p3, char *p4)//Definition of function rotate
{
    char tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = *p3;
    *p3 = *p4;
    *p4 = tmp;
}
/* 
 * main() calls average() to calculate the average letter of the input and return the value of the average
 */
char average(char n1, char n2, char n3, char n4)//Definition of function average
{
    char avg=(n1+n2+n3+n4)/4;
    if (avg == E)
        avg =avg+1;
    return avg;
}
