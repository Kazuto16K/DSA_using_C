#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int c=0;

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
		c++;
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

int ran_partition(int a[],int low,int high){
	int ran=(rand()%(high-low))+low;
	swap(&a[ran],&a[high]);
	return l_partition(a,low,high);
}

void quick(int a[],int low,int high){
	if(low<high){
		int q=ran_partition(a,low,high);
		quick(a,low,q-1);
		quick(a,q+1,high);
	}
}

int main(){
	int a[100],i,n,j,k,m;
	float total;
	srand(time(NULL));
	FILE *fi,*fo;
	fi=fopen("array3.txt","w+");
	fo=fopen("output3.txt","w+");
	printf("Enter the Required Number of Array: ");
	scanf("%d",&n);
	printf("Enter the Number of Elements in each Array: ");
	scanf("%d",&k);
	
	for(j=0;j<n;j++){
		for(i=0;i<k;i++){
			fprintf(fi,"%d ",rand()%1000);
		}
		fprintf(fi,"\n\n");
	}
	rewind(fi);
	for(j=0;j<n;j++){
		for(i=0;i<k;i++){
			fscanf(fi,"%d ",&a[i]);
		}
		quick(a,0,k-1);
		fprintf(fo,"Sorted Array:: ");
		for(m=0;m<k;m++){
			fprintf(fo,"%d ",a[m]);
		}
		fprintf(fo,"\nNumber of comparisons: %d\n\n",c);
		printf("Number of comparisons: %d\n",c);
		total=total+c;
		c=0;
	}
	printf("\nAverage Number of Comparisons: %.2f",total/n);
	fprintf(fo,"\nAverage Number of Comparisons: %.2f",total/n);
	fclose(fi);
	fclose(fo);
	
}
