#include<stdio.h>
#include<string.h>
#define MAX 1000

int main() {
	char str[MAX];
	char temp;
	int len, start = 0, end, i, t;
	scanf("%d", &t);
	
	while(t--){
    	scanf("%s", str);
    	
    	len = strlen(str);
    	
    	end = len-1;
    	while(start < end){
    	    temp = str[start];
    	    str[start] = str[end];
    	    str[end] = temp;
    	    start++;
    	    end--;
    	}
    	start = 0;
    	
    	printf("%s\n", str);
	}
	return 0;
}