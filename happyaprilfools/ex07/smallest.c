#include<stdio.h>
int main(int a,char**b){if(a!=3)return(0);puts(*(b+1));puts(*(b+2));return(2);}