#include<stdio.h>
#include<stdlib.h>
//#include "dgesv.h"
//#include "mkl.h"

void dgesv_(const int *N, const int *nrhs, double *A, const int 
*lda, int *ipiv, double *b, const int *ldb, int *info);

void dgemm_(char *transa, char *transb, int *m, int  *n,  int  
*k, double  *alpha,  double *a, int *lda, double *b, 
int *ldb, double *beta, double *c, int *ldc);

int main(){


int n=5,m=5,k=5,i,j;

double b[25]={1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
int *ipiv=malloc(n*sizeof(int));


double 
A[25]={1,1./2,1./3,1./4,1./5,1./2,1./3,1./4,1./5,1./6,1./3,1./4,
1./5,1./6,1./7,1./4,1./5,1./6,1./7,1./8,1./5,1./6,1./7,1./8,1./9};
double
B[25]={1,1./2,1./3,1./4,1./5,1./2,1./3,1./4,1./5,1./6,1./3,1./4,
1./5,1./6,1./7,1./4,1./5,1./6,1./7,1./8,1./5,1./6,1./7,1./8,1./9};

double C[25]={1,1./2,1./3,1./4,1./5,1./2,1./3,1./4,1./5,1./6,1./3,1./4,
1./5,1./6,1./7,1./4,1./5,1./6,1./7,1./8,1./5,1./6,1./7,1./8,1./9};

double alpha=1.0,beta=0.0;

printf("A\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",A[i]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",A[i+5]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",A[i+10]);
        printf("\n");
for(i=0;i<5;i++)
         printf(" %-5e\t",A[i+15]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",A[i+5]);
printf("\n");


 int N = 5;
 int nrhs =5;
 int lda = 5;
 int ldb = 5;
 int info;

 dgesv_(&N, &nrhs, A, &lda, ipiv, b, &ldb, &info);
    if(info == 0){
printf("A^-1 \n");
for(i=0;i<5;i++)
	printf(" %-5e\t",b[i]);
	printf("\n");
for(i=0;i<5;i++)
	printf(" %-5e\t",b[i+5]);
  	printf("\n");
for(i=0;i<5;i++)       
	printf(" %-5e\t",b[i+10]);
  	printf("\n");
for(i=0;i<5;i++)
	 printf(" %-5e\t",b[i+15]);
  	printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",b[i+5]);
printf("\n");
}

    else
	fprintf(stderr, "dgesv_ fails %d\n", info);

char chn= 'N';



dgemm_(&chn,&chn, &m, &n, &k, &alpha, b, &n, B, &k,
&beta, C, &m);



printf("A^-1 * A \n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+5]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+10]);
        printf("\n");
for(i=0;i<5;i++)
         printf(" %-5e\t",C[i+15]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+5]);
printf("\n");





 dgemm_(&chn,&chn, &m, &n, &k, &alpha, B, &n, b, &k, 
&beta, C, &m);



printf("A * A^-1 \n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+5]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+10]);
        printf("\n");
for(i=0;i<5;i++)
         printf(" %-5e\t",C[i+15]);
        printf("\n");
for(i=0;i<5;i++)
        printf(" %-5e\t",C[i+5]);
printf("\n");




return 0;
}


