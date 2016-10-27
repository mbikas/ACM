#include<stdio.h>  
#include<stdlib.h>    
typedef struct  {   
	long i,j,c;  
}Graph;
 
Graph mat[100010];  
long index[50010],heap[50010],hind[50010],heapsize,cost[50010];    
int comp(const void * A, const void * B)  
{   
	Graph * a=(Graph*)A;   
	Graph* b=(Graph*)B;   
	return a->i-b->i;  
}    
void MinHeapify(long root)  
{   
	long left,right,ind=root;   
	while(1)   
	{    
		left=root<<1;right=(root<<1)+1;     
		if(left<=heapsize&&cost[heap[left]]<cost[heap[ind]])     
			ind=left;    
		if(right<=heapsize&&cost[heap[right]]<cost[heap[ind]])     
			ind=right;    
		if(ind==root)return;    
		hind[heap[root]]=ind;    
		hind[heap[ind]]=root;    
		long tmp=heap[root];
		heap[root]=heap[ind];
		heap[ind]=tmp;    
		root=ind;   
	}  
}    

long ExtractMin()  
{   
	long tmp;   
	tmp=heap[1];   
	heap[1]=heap[heapsize];   
	heapsize--;   
	MinHeapify(1);   
	return tmp;  
}    
void HeapInsert(long root,long tmp)  
{   
	long child;   
	heap[root]=tmp;   
	child=root;
	root=child>>1;   
	while(root>0&&cost[heap[root]]>cost[heap[child]])   
	{    
		hind[heap[root]]=child;    
		hind[heap[child]]=root;    
		tmp=heap[root];
		heap[root]=heap[child];
		heap[child]=tmp;    
		child=root; 
		root=child>>1;   
	}  
}    
void Dijkstra(long s,long d,long n,long e)  
{   
	long i,u,v;   
	for(i=0;i<n;i++)cost[i]=2147483647,hind[i]=-1;   
	cost[s]=0;   
	heapsize=1;
	heap[1]=s;   
	while(heapsize>0)   
	{    
		u=ExtractMin();    
		if(u==d)return;    
		for(i=index[u];i<e;i++)    
		{     
			if(mat[i].i!=u)break;     
			v=mat[i].j;     
			if(mat[i].c+cost[u]<cost[v])     
			{      
				cost[v]=mat[i].c+cost[u];      
				if(hind[v]==-1)hind[v]=++heapsize;      
				HeapInsert(hind[v],v);     
			}    
		}     
	}  
}      

int main()  {   
	//freopen("929b.in","r",stdin);   
	long i,s,d,n,e,u,v,c,t=0,k,test;   
	scanf("%ld",&test);   
	while(test--)   
	{    
		scanf("%ld %ld %ld %ld",&n,&e,&s,&d);    
		k=0;    
		for(i=0;i<e;i++)    
		{     
			scanf("%ld %ld %ld",&u,&v,&c);    
			mat[k].i=u,mat[k].j=v,mat[k].c=c;k++;     
			mat[k].i=v,mat[k].j=u,mat[k].c=c;k++;    
		}    
		qsort(mat,k,sizeof(Graph),comp);    
		u=-1;    
		for(i=0;i<k;i++)    
		{     
			if(u!=mat[i].i)     
			{      
				u=mat[i].i;      
				index[u]=i;     
			}    
		}    
		Dijkstra(s,d,n,k);    
		if(cost[d]<2147483647)     printf("Case #%ld: %ld\n",++t,cost[d]);    
		else     printf("Case #%ld: unreachable\n",++t);   
	}   
	return 0;  
}