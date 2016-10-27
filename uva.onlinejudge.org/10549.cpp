#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct doll {
    int h,d,w;
} dol[201];

//a[i][j][k] = 1 means max(i,j) dolls are divided into pile1 with ith doll at the top and pile2 with 
// jth doll at the top.And pile1 has k dolls.
char a[201][201][201],set[201];
int n;

int comp( const void *a, const void *b )
{
    struct doll *x, *y;
    x = (struct doll *)a;
    y = (struct doll *)b;
    if( x->h != y->h ) return x->h - y->h;
    if( x->d != y->d ) return x->d - y->d;
    return y->w - x->w;
}

int holds( int a, int b )
{
    int r = dol[a].h-2*dol[a].w >= dol[b].h && dol[a].d-2*dol[a].w >= dol[b].d;
    return r;
}

int solve(int k, int i, int j, int ni )//put next i.e.,k+1th doll on pile1 that contains ith doll at the
// top or pile2 that contains jth doll at the top. ni is the number of doll in pile1.
{
   
     if( a[i][j][ni] == 1 ) return 0;// because we did not get solution from this condition before.
     if( ni > n/2 || k - ni > n/2 ) return 0;
	 if( k == n ) return 1;
     
	 if( holds(k+1,i) && solve(k+1,k+1,j,ni+1) )// trying to put next doll on pile1.
     {
        set[k+1] = 1;
	    return 1;
	 }	
     if( holds(k+1,j) && solve(k+1,i,k+1,ni))// trying to put next doll on pile2.
	 {
       set[k+1] = 0;
       return 1;     
	 }
	 a[i][j][ni] = 1;// from this situation we have done all possible calculation and didn't get solution. 

     return 0;
}
int main()
{
     int i;
     //freopen("f:\\a.in","r",stdin);
      //	 freopen("f:\\a.out","w",stdout);
     while( scanf("%d",&n) == 1 && n )
     {
	 n = 2*n;
	 for( i = 1; i <= n; i++ )
	   scanf("%d%d%d",&dol[i].h,&dol[i].d,&dol[i].w);
	 dol[0].h = dol[0].d = dol[0].w = 0;
	 qsort(dol,n+1,sizeof( struct doll),comp);
	 memset(a,0,sizeof(a));
	 memset(set,0,sizeof(set));
	 
	 solve(0,0,0,0);
	 for( i = n; i >= 1; i-- )
	   if( !set[i] ) printf("%d %d %d\n",dol[i].h,dol[i].d,dol[i].w);

       printf("-\n");
       for( i = n; i >= 1; i-- )
	   if( set[i] ) printf("%d %d %d\n",dol[i].h,dol[i].d,dol[i].w);
     
         
	 printf("\n");
     }
	 return 0;
}