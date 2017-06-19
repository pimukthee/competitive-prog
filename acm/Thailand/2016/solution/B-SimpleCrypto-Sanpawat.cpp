#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This file is a former test2.cpp
// Problem setter: Sanpawat Kantabutra
// 2016 ACM Thailand at Mahasarakham University

unsigned long int gcdExtended(unsigned long int a, unsigned long int b, long int *x, long int *y);

int main ()
{
	
	unsigned long int i=0, kprod=1;
	unsigned long int t,j,k,m1,m2,p,m,g;
	long int x,y;
	char buffer[256];
	char* array[100];
	unsigned long int keys[100];
	char* st;

    k=j=0;

    fgets(buffer, 256, stdin);
    st = strtok(buffer," ");
    
    t=atoi(st);
    st = strtok(NULL, " ");
	
	for (i=0;i<t;i++){
	    
	    fgets(buffer, 256, stdin);
        
		j=0; kprod=1;
        char *p1 = strtok(buffer," ");
	    
	     while (p1 != NULL)
         {
             array[j++] = p1;
             p1 = strtok (NULL, " ");
         }     
         
           
         /* convert number strings into integers */   
         m2 = atoi(array[0]);
	     p  = atoi(array[1]);
	     
	     for (k = 2; k < j; k++) {		 
             keys[k] = atoi(array[k]);
		      
		     kprod = kprod * keys[k];
		     
        }
		          
        
        
       
	    // decryption process	
	    // compute multiplicative inverse
	    
	    
	    g = gcdExtended(kprod,p,&x,&y);       // x is the multiplicative inverse of 50
	    
	
	    while (x < 0) x = x + p; // make sure the multipicative inverse is positive
	    
	
	    m1 = (m2*x) % p; // 10 is a multiplicative inverse of k, 2 is a multiplicative inverse of 50
	
	    printf("%lu\n", m1);
	    
	}     
           
            
           
	return 0;
}

// C function for extended Euclidean Algorithm
unsigned long int gcdExtended(unsigned long int a, unsigned long int b, long int *x, long int *y)
{
	
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    long int x1, y1; // To store results of recursive call
    long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
