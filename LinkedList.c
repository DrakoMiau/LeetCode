#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    /* data */
};

int * geeks(int myNumber){



    for (int i = 0; i < 10; i++)
    {
        myNumber += 10;
    }
    

    return myNumber;
}


int main(int argc, char const *argv[])
{
    int *p1;
    int miVariable = 10, numero;
    p1 = &miVariable;

    printf("Hola mundo \n");
    printf("%i",*p1);

    scanf("%i",&numero);

    printf(geeks(numero));



    return 0;
}
