#include<stdio.h>
#include<stdlib.h>
void fusion (int t[],unsigned a,unsigned c,unsigned b){
    int aux[100],l,i=a,j=c+1,k=a;
    if (t[i]<=t[j])
    {
        aux[k]=t[i];
        i++;
    }
    else{

        aux[k]=t[j];
        j++;
    }
    k++;

if(i<=c)
    for (l=i; l<=c; l++){
        aux[k]=t[l];
        k++;
    }
if (j<=b)
    for(l=j;l<=b;l++){
        aux[k]=t[l];
        k++;
    }
for (l=a;l<=b;l++){
    t[l]=aux[l];
}
}
void tri_fusion(int t[],unsigned a,unsigned b){
    unsigned c;
    if (a!=b){
        c=(a+b)/2;
        tri_fusion(t,a,c);
        tri_fusion(t,c+1,b);
        fusion(t,a,c,b);
    }
}

void main(){
    int *t,n,i;
    printf("ecrire n");
    scanf("%d",&n);
    t=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("ecrire l'element num %d: ",i+1);
        scanf("%d",(t+i));
    }
    printf("avant le trissage: \n");
    for(i=0;i<n;i++){
        printf("%d ",*(t+i));
    }
    tri_fusion(t,0,n);
    printf("\n");
    printf("apres le trissage: \n");
    for(i=0;i<n;i++){
        printf("%d ",*(t+i));
    }



}