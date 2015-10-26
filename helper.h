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




#define MAX 100

int ipop();			/* remove a element */

void ipush(int x);		/* insert an element in stack */

int isEmpty();			/* check for stack empty */

char getch();			/*  */

void ungetch(char ch);		/*  */

void put(char ch,int a);        /*  */

char get();                     /*  */

void blsp();                    /*  */

void stepwise();                /* shows each step of process, expression converted to postfix */


typedef struct {
    char k;
    int a;
}def;



