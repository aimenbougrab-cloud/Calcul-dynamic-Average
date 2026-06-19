#include<stdio.h>
#include<stdlib.h>



int main()
{
    int i , morevalues, number;
    char ask;
    float Average, Sum = 0;


    printf(" Enter the number of elements . . \n");
    scanf("%d", &number);

    float* T = calloc(number , sizeof(float));

    if (T == NULL)
    {
        printf(" The memory can't be reserved !\n");
        exit(0);
    }

    printf("\n Enter the Values of the Elements \n");
    for (i = 0; i < number; i++)
    {
        printf("\n Enter the Value number %d\n", i + 1);
        scanf("%f", T + i);
        Sum += *(T + i);
    }

	Average = Sum / (float)number;
    
    printf(" The Average of all values is = %.3f\n", Average);

    printf("\n\n Would you might more values enter , and new Average calcul ?\n [Yes]: Y , [No]: N !\n");
    scanf(" %c", &ask);



    while (ask == 'Y' || ask == 'y')
    {
        printf("\n\n Enter how added values that you want ? \n");
        
        scanf("%d", &morevalues);
        
        number = number + morevalues;

         T = realloc(T, number * sizeof(float));

        if (T == NULL)
        {
            printf(" The memory can't be reserved !\n");
            exit(0);
        }

		
        for (i = 0; i < number - morevalues; i++)
			printf(" Element number %d = %.3f\n", i + 1, *(T + i));



        printf("\n Enter the Values of the new added Elements \n");

        for (i = number - morevalues; i < number; i++)
        {

            printf(" Enter the Value number %d\n", i + 1);
            scanf("%f", (T + i));
            Sum += *(T + i);

        }

        Average = (float)Sum / (float)number;
        printf(" The new Average is = %.3f\n", Average);

        printf("\n\n Would you might more values enter , and new Average calcul ?\n if yes enter Y , and the opposite enter N !\n");
        scanf(" %c", &ask);

       
    }

    system("color 1F");

	printf("\n\n The final Average is = %.3f\n", Average);

    printf("\n\n End Programm (: \n\n");
    free(T);
    return 0;

}
