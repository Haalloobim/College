#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int top; 
	char data[10]; 
}stack;

stack st; 

void init();
int  isEmpty();
void push(char str);
void pop();
int  compare(char str);
void solve();

int main(){
	init();
	solve(); 
	return 0; 
}

/*
test case:
2+3
23+
2+3*4
234*+
3*4+2*5
34*25*+
1+2+3+4+5+6
12+3+4+5+6+
*/

void init(){
	st.top = -1; 
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

int compare(char str){
	if (str == '+' || str == '-'){
		return 1; 
	}
	return 2; 
}

void solve(){
	char str[25]; 
	scanf("%s", str); 
	int n = strlen(str), i; 
	for(i = 0; i < n; i++){
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/') && isEmpty()){
			push(str[i]); 
			continue; 
		}
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/') && !isEmpty()){
			while (compare(str[i]) <= compare(st.data[st.top]) && !isEmpty()){
				pop(); 
			}
			push(str[i]); 
			continue; 
		}
		printf("%c ", str[i]); 
	}

	while (!isEmpty()){
		pop(); 
	}
}
