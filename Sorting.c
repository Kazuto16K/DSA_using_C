// Online C compiler to run C program online
#include <stdio.h>
int c1=0,c2=0,k=0;

void Bubble(int A[],int n){
    int i,j,flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-i-1;j++){
            c1++;
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

void insertion(int A[],int n){
    int i;
    for(i=1;i<n;i++){
        int temp=A[i];
        int j=i-1;
        while(j>=0){
            c2++;
            if(A[j]>temp){
                A[j+1]=A[j];
                j--;
            }    
        }
        A[j+1]=temp;
    }
}

int par_ran(int A[],int low,int high){
    srand(time(NULL));
    int ran=low+rand()%(high-low);
    int temp=A[low];
    A[low]=A[ran];
    A[ran]=temp;
    //printf("Pivot is: %d",temp);
    
    return par(A,low,high);
    
}

void swap(int A[],int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

// int par(int A[],int low,int high){
//     int pivot=A[high];
//     int i=low-1,j;
//     for(j=low;j<high;j++){
//         k++;
//         if(A[j]<=pivot){
//             i++;
//             int temp=A[i];
//             A[i]=A[j];
//             A[j]=temp;
            
//         }
//     }
//     int temp=A[i+1];
//     A[i+1]=A[high];
//     A[high]=temp;
//     return i+1;
// }

int par(int A[],int low,int high){
    int pivot=A[low];
    int start=low+1;
    int end=high;
    while(start<end){
        while(A[start]<=pivot){
            start++;
            k++;
        }
        while(A[end]>pivot){
            end--;
            k++;
        }
        if(start<end){
            swap(A,start,end);
            
        }
    }
    swap(A,low,end);
    return end;
}

void Quick(int A[],int low, int high){
    if(high>low){
        int mid=par_ran(A,low,high);
        Quick(A,low,mid-1);
        Quick(A,mid+1,high);
    }
}
int main() {
    int A[20];
    int i;
    for(i=0;i<20;i++){
        A[i]=50-i;
    }
    
    for(i=0;i<20;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n\n");
    Bubble(A,20);
    for(i=0;i<20;i++){
        printf("%d ",A[i]);
    }
    printf("\n\nNo of comparisons: %d",c1);
    
    return 0;
}
