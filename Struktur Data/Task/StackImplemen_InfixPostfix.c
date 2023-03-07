#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int top; 
	char data[10]; 
}stack;

stack st; 

void init(){
	st.top = -1; 
}

int isFull(){
	return (st.top == 10 - 1) ? 1: 0; 
}

int isEmpty(){
	return(st.top == -1) ? 1 : 0; 
}

void push(char str){
	st.data[++st.top] = str;
}

void pop(){
	char temp = st.data[st.top];
	st.top--;    
	printf("%c ", temp); 
}

int main(){
	init();
	char str[25]; 
	scanf("%s", str); 
	int n = strlen(str), i; 
	for(i = 0; i < n; i++){
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/') && isEmpty()){
			push(str[i]); 
			continue; 
		}
		else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/') && !isEmpty()){
			if ((str[i]== '+' || str[i] == '-') && (st.data[st.top] == '*' || st.data[st.top] == '/') ){
				pop(); 
				push(str[i]); 
			}
			else
				push(str[i]); 
			}
			continue; 
		}
		printf("%c ", str[i]); 
	}

	while (!isEmpty()){
		pop(); 
	}
	return 0; 
}
