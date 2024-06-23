#include<stdio.h>
int Hanoi(char src,char dest,char aux,int n){
	if(n==1){
		printf("\nMove Disc 1 from %c to %c",src,dest);
		return;
	}
	Hanoi(src,aux,dest,n-1);
	printf("\nMove Disc %d from %c to %c",n,src,dest);
	Hanoi(aux,dest,src,n-1);
}

int main(){
	int n;
	printf("Enter number of discs: ");
	scanf("%d",&n);
	Hanoi('A','C','B',n);
	return 0;
}
