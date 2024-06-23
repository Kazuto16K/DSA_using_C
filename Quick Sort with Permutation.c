#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int c=0;
int fact(int n){
	if(n==1){
		return 1;
	}
	return n*fact(n-1);
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int l_partition(int a[],int low, int high){
	int pivot=a[high];
	int i=low-1;
	int j;
	for(j=low;j<high;j++){
		//c++;
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quick(int a[],int low,int high){
	if(low<high){
		int q=l_partition(a,low,high);
		quick(a,low,q-1);
		quick(a,q+1,high);
	}
}

void print_file(int a[]){
	FILE *fp;
	fp=fopen("input2.txt","a+");
	int i;
	for(i=0;i<5;i++){
		fprintf(fp,"%d ",a[i]);
	}
	fprintf(fp,"\n");
	fclose(fp);
}

void permutation(int a[],int start,int end){
	if(start==end){
		print_file(a);
		return;
	}
	int i;
	for(i=start;i<=end;i++){
		swap(&a[i],&a[start]);
		permutation(a,start+1,end);
		swap(&a[i],&a[start]);
	}
}

int main(){
	FILE *fo,*fk,*fr;
	fo=fopen("output2.txt","w+");
	int a[10],i,j,k=0;
	float total;
	for(i=0;i<5;i++){
		a[i]=i+1;
	}
	fr=fopen("input2.txt","w+");
	fclose(fr);
	permutation(a,0,4);
	fk=fopen("input2.txt","r");
	for(i=0;i<fact(5);i++){
		for(j=0;j<5;j++){
			fscanf(fk,"%d",&a[j]);
		}
		quick(a,0,4);
		k++;
		printf("No of comparisons in case %d: %d\n\n",k,c);
		fprintf(fo,"Sorted Array:: ");
		for(j=0;j<5;j++){
			fprintf(fo,"%d ",a[j]);
		}
		fprintf(fo,"\nNo of Comparisons in case %d: %d\n\n",k,c);
		total=total+c;
		c=0;
	}
	fprintf(fo,"\nAverage No of Comparisons: %.2f\n\n",total/fact(5));
	printf("\nAverage No of Comparisons: %.2f\n\n",total/fact(5));
	fclose(fk);
	fclose(fo);
}






