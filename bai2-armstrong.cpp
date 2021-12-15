#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int CountDigit(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}
 
float kiem_tra(int n)
{
    int numDigit = CountDigit(n);
    int tmp = n, sum = 0, last;
    while (tmp > 0)
    {
        last = tmp % 10; 
        tmp /= 10;       
        sum += pow(last, numDigit);
    }
    if (sum == n)
        return true;
    return false;
}
int main(){
	FILE *f=fopen("bai_armstrong","w");
	int n;
    printf("nhap so phan tu mang la: ");
    scanf("%d",&n);
    int *p;
    p = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		printf("\nnhap a[%d]=",i);
		scanf("%d",(p+i));
	}
	printf("_____________________________________");
	for(int i=0;i<n;i++){
		if(kiem_tra(*(p+i))==true){
			printf("\nso %d la so armstrong",*(p+i));
			fprintf(f,"\nso %d la so armstrong",*(p+i));
		}
		else if(kiem_tra(*(p+i)==false)){
			printf("\nso %d ko la so armstrong",*(p+i));
		}
	}
	fclose(f);
	free(p);
}
