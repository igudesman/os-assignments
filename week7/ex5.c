#include <stdio.h> 


int main() { 
	char **s;
	char foo[] = "Hello World"; 
	s = &foo; // instead of 's = *foo', because s is a pointer to a pointer
	printf("s is %s\n", s);
	//printf("foo is %c\n", *foo);
	s[0] = foo;
	printf("s[0] is %s\n", s[0]); 
	return(0); 
}