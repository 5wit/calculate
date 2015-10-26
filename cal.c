/*****************************************************************************
 * Copyright (C) Shubham S. Wadhe 
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/





/* CALCULATOR PROGRAM USING C LANGUAGE   */



#include<stdio.h>		/* INFIX EVALUTION CODE TO BE ADDED */  /*  MATRIX OPERATIONS, log, */
#include<stdlib.h>		
#include"my.h"              /*Contains functions used in calculator OR simply math library*/
										
	
void add() {
	long int a , b, s;		
	printf("Enter two nos.\n");
	scanf("%ld%ld", &a, &b);
	s = a + b;
	printf("=============================\n");	
	printf("  %ld\n+\n  %ld\n-----------\n  %ld\n", a, b, s);
	printf("=============================\n");	
}		
void sub() {
	long int a , b, s;		
	printf("Enter two nos.\n");
	scanf("%ld%ld", &a, &b);
	s = a - b;
	printf("=============================\n");	
	printf("  %ld\n-\n  %ld\n-----------\n  %ld\n", a, b, s);
	printf("=============================\n");	
}		
void mult() {
	long int a , b, s;		
	printf("Enter two nos.\n");
	scanf("%ld%ld", &a, &b);
	s = a * b;
	printf("=============================\n");	
	printf("  %ld\n*\n  %ld\n-----------\n  %ld\n", a, b, s);
	printf("=============================\n");	
}		
void divd() {
	double a , b;	
	double s;	
	printf("Enter two nos.\n");
	scanf("%lf%lf", &a, &b);
	if(b == 0) {
		    printf("div 0 err, can't divide by zero\n");
	}	
	else {
		s =  a / b;
		printf("=============================\n");	
		printf("  %lf\n/\n  %lf\n-----------\n  %lf\n", a, b, s);
		printf("=============================\n");	
	}
}		
void square() {
	long int s = 0;
	printf("Enter a no.\n");
	scanf("%ld",&s);	
	printf("=============================\n");
	printf("%ld\n", s*s);
	printf("=============================\n");
}								
void sqroot() {
	float m,n;
	float num;
	n=0.0001;                       /* we can calculate upto decimal places also */
	printf("Enter a no. : \n");
	scanf("%f",&num);
 	for(m=0;m<num;m=m+n) {				
        	if((m*m)>num) {
  	        	m=m-n;          // This if() is used to calculate the final value as soon as the square of the number exceeds
   			break;          //  the number then we deduct the value exceeded and stop the procedure using break; this is our final 							value which is stored in m;
  }              
}
	printf("=============================\n");
	printf("%.2f\n",m);	
	printf("=============================\n");
}		
void powr() {
	int pow, num, i = 1;	  
	long int sum = 1;	  
	printf("Enter a no.\n");	  
	scanf("%d",&num);	  
	printf("Enter power \n");	  
	scanf("%d", &pow);	  
	while(i <= pow){
		sum = sum * num;
		i++;
	}
	printf("=============================\n"); 	
	printf("%d^%d =  %ld\n",num,pow,sum);
	printf("=============================\n");
}
void fact() {
	int c, n;
	long long int fact = 1;
	printf("Enter a number to calculate it's factorial\n");
	scanf("%d", &n); 
		for (c = 1; c <= n; c++)
	fact = fact * c;
	printf("=============================\n");	
	printf("Factorial of %d = %lld\n", n, fact);
	printf("=============================\n");
	 
}
void GCD_LCM() {
	int a, b, x, y, t, gcd, lcm;
	printf("Enter two integers\n");
	scanf("%d%d", &x, &y);
	a = x;
	b = y;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	gcd = a;
	lcm = (x*y)/gcd;
	printf("=============================\n");
	printf("Greatest common divisor of %d and %d = %d\n", x, y, gcd);
	printf("  Least common multiple of %d and %d = %d\n", x, y, lcm);
	printf("=============================\n");	 
}
void decimal_to_binary() {
	int n, c, k; 
	printf("Enter an integer in decimal number system\n");
	scanf("%d", &n); 
	printf("%d in binary number system is:\n", n);
	for (c = 31; c >= 0; c--) {
		k = n >> c; 
		if (k & 1)
		printf("1");
	else
		printf("0");
	} 
	printf("\n");
	}	 

int ncr_npr() {
	long factorial(int n) {
	int c;
	long result = 1;
	for (c = 1; c <= n; c++)
	result = result*c;
	return result;
	}
		
	long find_npr(int n, int r) {
	long result;
	result = factorial(n)/factorial(n-r);
	return result;
	} 
	
	long find_ncr(int n, int r) {
	long result;
	result = factorial(n)/(factorial(r)*factorial(n-r)); 
	return result;
	} 
	
	int n, r;
	long ncr, npr;
	printf("Enter the value of n and r\n");
	scanf("%d%d",&n,&r); 
	ncr = find_ncr(n, r);
	npr = find_npr(n, r);
	printf("=============================\n");	
	printf("%dC%d = %ld\n", n, r, ncr);
	printf("%dP%d = %ld\n", n, r, npr); 
	printf("=============================\n");	
	return 0;
	 
}

/*void addn() {
	int n, sum = 0, c, value;
	printf("Enter the number of integers you want to add\n");
	scanf("%d", &n);
	printf("Enter %d integers\n",n);
	for (c = 1; c <= n; c++) {
		scanf("%d", &value);
		sum = sum + value;
	}
	printf("=============================\n");	
	printf("Sum of entered integers = %d\n",sum);
	printf("=============================\n");
} 		

*/

void addn() {
	int n, sum = 0;
	printf("Enter integers\n");
	printf("Enter ctrd + d for termination\n");	
	while((scanf("%d", &n)) != -1) 			
		sum = sum + n;
	printf("=============================\n");	
	printf("Sum of entered integers = %d\n",sum);
	printf("=============================\n");
} 			
void cmplxnoadr() {
	
	struct complex a, b, c;
	printf("Enter a and b where a + ib is the first complex number.\n");
	printf("a =  ");
	scanf("%d", &a.real);
	printf("b =  ");
        scanf("%d", &a.img);
        printf("Entered complex number = (%d) + (%d)i\n", a.real, a.img); 	
        printf("Enter c and d where c + id is the second complex number.\n");
        printf("c =  ");
        scanf("%d", &b.real);
   	printf("d =  ");
   	scanf("%d", &b.img);
	printf("Entered complex number = (%d) + (%d)i\n", b.real, b.img); 	
  	c.real = a.real + b.real;
 	c.img = a.img + b.img;
	printf("=====================================\n");
	if ( c.img >= 0 )
	printf("Sum of two complex numbers = (%d) + (%d)i\n", c.real, c.img);
	else
	printf("Sum of two complex numbers = (%d) - (%d)i\n", c.real, c.img); 
	printf("=====================================\n");
}
void series() {
            int i,n,j,ch;
            float x,t,s,r;
            char c='y';
      
            do {
                printf("===================================================\n");
                printf("1.SINE SERIES\n");
                printf("2.COSINE SERIES\n");
                printf("3.EXPONENTIAL SERIES\n");
                printf("4.EXIT \n");
                printf("===================================================\n");
                printf("ENTER THE CHOICE\n");	
                scanf("%d",&ch);
                switch(ch) {
              
                  case 1:
                             printf("\nENTER THE LIMIT");
                             scanf("%d",&n);
                             printf("\nENTER THE VALUE OF x:");
                             scanf("%f",&x);
                             printf("===================================================\n");
                             printf("Sine series : sin x = x - ((x^3)/3!) + ((x^5)/5!) - …………..\n");

                             r=((x*3.1415)/180);
                             t=r;
                             s=r;
                             i=2;
                             for(j=2;j<=n;j++) {
                
                                    t=(t*(-1)*r*r)/(i*(i+1));
                                    s=s+t;
                                    i=i+2;
                             }
                             printf("\nSUM OF THE GIVEN SINE SERIES IS %4f\n",s);
                             printf("===================================================\n");           
                             break;
                  case 2:
                             printf("\nENTER THE LIMIT ");
                             scanf("%d",&n);
                             printf("\nENTER THE VALUE OF x:");
                             scanf("%f",&x);
                             printf("===================================================\n");     
                             printf(" Cosine Series : cos x = 1 - ((x^2)/2!) + ((x^4)/4!) -…………...\n");
                                 
                             r=((x*3.14)/180);
                             t=1;
                             s=1;
                             i=1;
                             for(j=2;j<=n;j++) {
                        
                                    t=((-1)*t*r*r)/(i*(i+1));
                                    s=s+t;
                                    i=i+2;
                             }
                             printf("\n SUM OF THE COSINE SERIES IS %f\n",s);
                             printf("===================================================\n"); 
                             break;
                  case 3:
                             printf("\nENTER THE LIMIT");
                             scanf("%d",&n);
                             printf("\nENTER THE VALUE OF x:");
                             scanf("%f",&x);
                             printf("===================================================\n");        
                             printf("Exponential Series  : e^x  = 1 + (x/1!) + ((x^2)/2!) + ((x^3)/3!)+…….\n");
                           ;          
                             t=1;
                             s=1;
                             for(i=1;i<n;i++) {

                                    t=(t*x)/i;
                                    s=s+t;
                             }
                             printf("\nSUM OF EXPONENTIAL SERIES IS %f\n",s);
                             printf("===================================================\n");
                             break;
                       case 4: 
                            break;// exit(0);
                  default:
                             printf("\n WRONG CHOICE");
                }
                
               
            }
            while(ch != 4);
}






















































































