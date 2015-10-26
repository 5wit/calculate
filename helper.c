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



#include<stdio.h>
#include<ctype.h>

#include"helper.h"

#include"calculate.h"

static int sp=0;
static int bf=0;
static int pt=0;
static int gt=0;
static int stack[MAX]; 
static char buffer[MAX];
static def function[MAX];

def f;


int ipop() {
    if(sp == 0) {
	printf("the istack is null\n");
	return ;
    }
    return stack[--sp];
} 



void ipush(int x) {
    if(sp > MAX) {
	printf("the istack is full \n");
	return ;                              //  return
    } 
    stack [sp++] = x;
}



int isEmpty() {
    if(sp <= 0)
	return 1;
    return 0;
}



char getch() {
    char ch;
    if(bf <= 0) {
	ch = getchar();
    }
    else {
	ch = buffer[--bf];
    }
    return ch;
}



void ungetch(char ch) {
    if(bf > MAX) {
	printf("cant ungeth,the buffer is full\n");
    }
    else {
	buffer[bf++] = ch;
    }
}



void put(char ch, int a) {
    def fc;
    fc.k = ch;
    fc.a = a;
    if(pt > MAX)
	printf("the function array is full\n");
    
    else { 
	function[pt++] = fc;
    }
}



char get() {
    if(gt >= pt) {
	return EOF;
    }
    else {
	 f = function[gt++];
	 return f.k;
    }
}




void blsp() {
  int i;
  for(i = 0; i < sp; i++)
      printf("%d  ", stack[i]);
  putchar('\n');
}


void stepwise() {
    int i;
    printf("**********************************\n");
    for(i = 0; i < pt; i++)
	printf("%c %10d \n",function[i].k,function[i].a);
    printf("**********************************\n");
}
