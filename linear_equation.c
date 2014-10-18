#include<stdio.h>
#include<stdlib.h>
//#include "dgesv.h"

void dgesv_(const int *N, const int *nrhs, double *A, const int 
*lda, int
	*ipiv, double *b, const int *ldb, int *info);

int main(){

/*
int n=3,i,j;

float A[3][3], b[3], AT[9], x[3];

A[0][0]=6; A[0][1]=-2; A[0][2]=2;
A[1][0]=12; A[1][1]=-8; A[1][2]=6;
A[2][0]=3; A[2][1]=-13; A[2][2]=3;

b[0]=16;
b[1]=26;
b[2]=-19;

for(i=0; i<3; i++){
for(j=0; j<3; j++)
AT[j+3*i]=A[j][i];
}*/

double A[9]={6,12,3,-2,-8,-13,2,6,3};
double b[3]={16,26,-19};

 int N = 3;
 int nrhs = 1;
 int lda = 3;
 int ipiv[3];
 int ldb = 3;
 int info;

 dgesv_(&N, &nrhs, A, &lda, ipiv, b, &ldb, &info);

    if(info == 0) /* succeed */
	printf("The solution is:\n %lf\n %lf\n %lf\n", b[0], b[1], b[2]);
    else
	fprintf(stderr, "dgesv_ fails %d\n", info);

return 0;
}

