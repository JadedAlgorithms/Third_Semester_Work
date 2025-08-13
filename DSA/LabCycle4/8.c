#include <stdio.h>

int main(){
	int n,d,fra=-1,rea=-1;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);}
    printf("Enter window length:");
    scanf("%d",&d);
    int q[n-d+1];
    for (int i=0;i<n-d+1;i++){
        int max=a[i];
        for (int k=i;k<i+d;k++){
            if (a[k]>max) max=a[k];
        }
        q[i]=max;
    }
    printf("The max element stack:\n");
    for (int i=0;i<n-d+1;i++) printf("%d ",q[i]);
    printf("\n");
}