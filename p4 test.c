/*
 * Assignment 4        p4.c:         Due August 19, 2015
 * login #: cs5vbj
 *
 * This program reads in the settings that the user input and output certain graphs.  
 * The pyramid is basically a combination of two  triangles that have different direction.
 */
 
 #include <stdio.h>                                                                         // printf, scanf 
 #include <ctype.h>                                                                         // isgraph 
 
 void menu ( void )
 {
 	printf("Menu: \n1) Print Triangle \n2) Print Pyramid \n3) Change Line Length \n4) Change Symbolic Character \n5) Exit\n");
 }
 
 void print_triangle( int a, char b)
 {
    int i,j;
 	if( a>0 )
	{
		for(i=1; i<=a; i++)
		{
			for(j=1; j<=i; j++)
			   printf("%c", b);
			printf("\n");
		}    
	} 
	
	else
	{
		for(i=-a; i>=1; i--)
		{
			for(j=i; j>=1; j--)
			   printf("%c", b);
		    printf("\n");
		}
	}
 }
 
 int read_iterations( void )
 {
 	int iterations;  
	
	do                                                                                       //Store users input 
	{
		printf("\nEnter a positive or negative number of iterations:");
		scanf("%d", &iterations);
		getchar();
		if(iterations==0)
	    	printf("ERROR: Enter a valid positive or negative number!\n");
    }while(iterations==0);
	
	return iterations;
 }
 
 char read_character(void)                                                                      //¸ÄÁË 
 {
 	char character;                                                                          // Stores user input
 	int result;                                                                              // Stores result of isgraph()
 	
 	do
 	{
	    printf("\nEnter an alphanumeric or symbolic character:");
	    scanf("%c", &character);
 	    getchar();
 	    result = isgraph(character);
 	    if(result == 0)
 	       printf("ERROR: Enter alphanumeric or symbolic character! \n");
   }while(result == 0);
   
   return character;
 }
 
 void print_pyramid(int c, char d)
 {
 	int i,j;
 	
 	if( c>0 )
	{
		for(i=1; i<=c; i++)
		{
		    print_triangle(c, d);
		    print_triangle(1-c, d);
		}    
	} 
	
	else
	{
		for(i=-c; i>=1; i--)
		{
		    print_triangle(-c, d);
		    print_triangle(1+c, d);
		}
	} 
 } 
 
 int main( void )
 {
 	int choice;                                                                              // Stores user input
 	char ch = '*';                                                                           // Character modified by read_character() function
 	int it = -3;                                                                             // Integer modified by read_iterations() function
 	
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
        }while ( choice < 1 || choice > 5 );
        
 		switch (choice) 
 		{
 			case 1:
 				print_triangle(it, ch);
 				break;
            case 2:
                print_pyramid(it, ch);
                break;
            case 3:
                it = read_iterations();
                break;
            case 4:
                ch = read_character();
                break;
            case 5:
                printf("Exiting¡­\n");
                break;
            default:
                break; 				
		} 
	}while(choice != 5);
	
	return 0;
 }
