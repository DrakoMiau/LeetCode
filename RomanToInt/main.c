#include <stdio.h> //standard input ouput header
#include <stdlib.h>
#include <math.h>
#include <search.h>
#include <string.h>

#define PI 3.1416 //esta es una macro

//roman to integer


int romanToInt(char * s){

    int sum = 0;
    int lenght = strlen(s);

    for (int i = 0; i < lenght; ++i) {

        if(s[i] == 'I') {
            if(s[i+1] == 'V' || s[i+1] == 'X'){
                sum -= 1;
            } else{
                sum += 1;
            }

        } else if(s[i] == 'V') {
            sum += 5;
        } else if(s[i] == 'X') {
            if(s[i+1] == 'L' || s[i+1] == 'C'){
                sum -= 10;
            } else{
                sum += 10;
            }
        } else if(s[i] == 'L') {
            sum += 50;
        } else if(s[i] == 'C') {
            if(s[i+1] == 'D' || s[i+1] == 'M'){
                sum -= 100;
            } else{
                sum += 100;
            }
        } else if(s[i] == 'D') {
            sum += 500;
        } else if(s[i] == 'M') {
            sum += 1000;
        }
    }

    return sum;
}

int main() {

    char s [20];

    printf("Ingrese un string");

    scanf("%s",s);

    printf("El resultado es: %i",romanToInt(s));

    return 0; //esta linea no es obligatoria, pero es muy buena practica
}

