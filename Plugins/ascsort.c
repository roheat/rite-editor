/*
    This file is part of Rite Editor.

    Rite Editor is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Rite Editor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rite Editor.  If not, see <http://www.gnu.org/licenses/>.

*/

/*
*------------------------------------------------------------------------------------------------------------------------------------------
*	Plugin Name : ascsort.c
*	Function : Sorts the text word by word in ascending order with one word in each line
*	Credits : Rohith Srivathsav
*------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 128

char* getnext(char *string) {

	static int count = 0;
	char *token = (char *) malloc(sizeof(char)*MAX_SIZE);
	if(count == 0) {
		token = strtok(string, " \t");
		count++;
	}
	else
		token = strtok(NULL, " \t");	
	/* TOKEN=substring is ready */
	return token;
}
//Function which changes the string s i.e. data in tmp.txt
char* asc_sort(char *s) {
	
	int i = 0, j = 0, count, k = 0;
	char p[MAX_SIZE][MAX_SIZE], *q, temp[MAX_SIZE];
	//Getting each word into a 2d array p[][]
	while(1) {
		q = getnext(s);
		if(q != NULL) {
			strcpy(p[i], q);
			i++;
		}
		else 
			break;
		
	}
	
	count = i;
	//sorting the 2d array in ascending order
	for(i = 0; i < count; i++) {
     
    		for(j = 0; j < count-1; j++) {
        		if(strcmp(p[j], p[j+1]) > 0){
        			strcpy(temp, p[j]);
        			strcpy(p[j], p[j+1]);
        			strcpy(p[j+1], temp);
        		}
     		}
        }
	
	//copying the sotred words from 2d array p to string s
	s[0] = '\0';
	for(i = 0; i < count; i++) {
		strcat(s, p[i]);
		strcat(s, "\n");
	}
	
	return s;
	
}

int main() {
	//Initialize variables
	FILE *fp1, *fp2;
	char *s = (char *) malloc(sizeof(char)*MAX_SIZE);
	char *new =  (char *) malloc(sizeof(char)*MAX_SIZE);
	int i = 0, j = 0, max = MAX_SIZE;
	char ch;
	
	//Read from a file tmp.txt and put data into s
	fp1 = fopen("Plugins/tmp.txt", "r");
	
	while((ch = getc(fp1)) != EOF) {
    		if(ch == '\n')
    			s[i] = ' ';
    		else
    			s[i] = ch;
    		i++;
    		if(i == max) {
    			char *p = realloc(s, max*2);
    			max*=2;
    			s = p;
    		}
    	
    	}
    	
    	fclose(fp1);
	s[i] = '\0';
	
	//Call the funtion which changes s
	new = asc_sort(s);
	
	//Write the new string back into the file tmp.txt
	fp2 = fopen("Plugins/tmp.txt", "w");
	fprintf(fp2, "%s", new);
	fclose(fp2);
	
	free(new);
	
	return 0;
}



