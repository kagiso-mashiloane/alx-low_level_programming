#include<stdio.h>
int main(void) {
char a;
int b;
long int c;
long long int d;
float f;
printf("size of a char: %d byte(s)\n",  sizeof(a));
printf("size of an int: %d byte(s)\n",  sizeof(b));
printf("size of a long int: %d byte(s)\n",  sizeof(c));
printf("size of a long long int: %d byte(s)\n",  sizeof(d));
printf("size of a float: %d byte(s)\n",  sizeof(f));
return (0);
}

