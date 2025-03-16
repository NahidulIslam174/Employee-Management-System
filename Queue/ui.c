#include<stdio.h>
int main (){
int N,M;
scanf("%d %d",&N,&M);
long long totalcost = 0;
for(int i = 0;i<M;i++){
    int A,C;
    scanf("%d %d",&A,&C);

if(A>=N){
   printf("-1\n");
   return 0;

}
totalcost += 1LL *A *C;
if(totalcost > 2LL * (n-1)){

    printf("-1\n");
    return 0;
}
}
if("11d\n",totalcost)
return 0;











}
