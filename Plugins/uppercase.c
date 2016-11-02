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
**------------------------------------------------------------------------------------------------------------------------------------------
*	Plugin Name : uppercase.c
*	Function : Converts all text to uppercase
*	Credits : Rohith Srivathsav
*-------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 1024

//Function which changes the string s i.e. data in tmp.txt
char* upper_case(char *s) {
	
	int j = 0;
	for( j = 0; s[j] != '\0'; j++) 
		s[j] = toupper(s[j]);
	
	return s;
	
}

int main() {
	//Initialize variables
	FILE *fp1, *fp2;
	char *s = (char *) malloc(sizeof(char)*MAX_SIZE);
	char *new =  (char *) malloc(sizeof(char)*MAX_SIZE);
	int i = 0, max = MAX_SIZE;
	char ch;
	
	//Read from a file tmp.txt and put data into s
	fp1 = fopen("Plugins/tmp.txt", "r");
	
	while((ch = getc(fp1)) != EOF) {
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
	new = upper_case(s);
	
	//Write the new string back into the file tmp.txt
	fp2 = fopen("Plugins/tmp.txt", "w");
	fprintf(fp2, "%s", new);
	fclose(fp2);
	
	free(new);
	
	return 0;
}



