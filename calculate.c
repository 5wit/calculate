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



/*
 *	CALCULATOR  IN  C  LANGUAGE 		
 *	
 *	MIS : 	111408064
 *
 *	SYIT : 2015-16   */
 


#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>			/* checking for whether input is digit character or else */ 

#include"helper.h"			/* contains functions prototypes and structured declared especially for stack */

#include"calculate.h"			/* contains functions prototypes and structured declared */

#include"my.h"				/* contains functions prototypes and structured declared */

extern def f;				/* structure defined in another file */

int main() {
    printf("Enter a valid expression\n");
    getsymbol();
    opr();
    stepwise();				/* shows each step of process, expression converted to postfix */
    cal();
    int choice;
	do {	
		printf("===================================================\n");			
		printf("1 : ADD\t\t\t2 : SUB\n3 : MULT\t\t4 : DIVD\n5 : SQUARE\t\t");
		printf("6 : SQUARE ROOT\n7 : POWER\t\t8 : FACT\n9 : GCD_LCM\t\t10 : DECIMAL_TO_BINARY\n");
		printf("11 : NCR-NPR\t\t12 : ADD_N_INTEGERS\n13 : ADD_of_complex_no.\n14 : SERIES\t\t15 : EXIT\n");
		printf("===================================================\n");
		                       /*This printfs are only for distinction between choices and output on terminal when run*/				
		printf("Enter your choice\n");		
		scanf("%d", &choice);
	        switch(choice) {		/* available choices */
			case 1:
				add();
				break;	      
			case 2:
				sub();
				break;
			case 3:
				mult();
				break;	
			case 4:
				divd();
				break;									
			case 5:
				square();
				break;			
			case 6:
				sqroot();
				break;				
			case 7:
				powr();
				break;			
			case 8:
				fact();
				break;		
			case 9:
				GCD_LCM();
				break;
			case 10:
				decimal_to_binary(); 
				break;
			case 11:
				ncr_npr();
				break;
			case 12:				
				addn();
				break;
			case 13:
				cmplxnoadr();
				break;
			case 14:
				series();
				break;
			case 15:
				exit(0);			
			default:
				printf("KINDLY ENTER A VALID CHOICE\n");
				break;
		}		      			
	}while(choice != 15);
//}		
    return 0;
}



void getsymbol() {
   
    char ch = getch(); 			/* getch() -> single character input at a time */
    if(isdigit(ch)) {
        number = 0;
	while(isdigit(ch)) {
	    number = 10*number + (ch-'0');	/* string to number */
	    ch = getch();
	}
	ungetch(ch);
	sym = 0;
    }
    else {
	sym = ch;		/* keep operator as it is */
    }
}



void opr() { 
    char chsym;
    oprt();
    while(sym == '+'|| sym == '-') {
	chsym = sym;
	getsymbol();
	oprt();
	put(chsym, 0);
    }
}



void oprt() {
    char chsym;
    prnth();
    while(sym == '*'|| sym == '/') {
	chsym=sym;
	getsymbol();
	prnth();
	put(chsym,0); 
    }
}



void prnth() { 			/* check for paranthesis */
    if(sym == '(') {
	getsymbol();
	opr();
	if(sym != ')') {
	    printf("error in expression input\nEnter a valid expression\n");
	    exit(0);
	}

    }
    else if(sym == 0) {
	put('l', number);
	
    }

    getsymbol();
}




void cal() {
    char ch;
    int n;
    while((ch = get()) != EOF) {
	switch(ch) {
	    case '+':
		ipush(ipop()+ipop());			/*  remove last two nos and add them, and insert sum */
		break;
	    case '-':
		n = ipop();
		ipush(ipop()-n);
		break;
	    case '*':
		ipush(ipop()*ipop());
		break;
	    case '/':
		n = ipop();
		if(n == 0) {
		    printf("div 0 err, can't divide by zero\n");
		    exit(0);
		}
		ipush(ipop()/n);
		break;
	    case 'l':
		ipush(f.a);
		break;
	    default:
		printf("Err \n");
		exit(0);
		break;
	}
    }
    printf("%d\n", ipop());			/* result of expression */
    if(!isEmpty()) {
	printf("Big err \n");
	exit(0);
    }
}

