								//ACM 579 ClockHands
                        //Solved By Bikas Cse Sust

#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
 int i,h,x,y,m;
 char a[10],b[4];
 double hAngle,mAngle;

 while( scanf(" %[^\n]",a)==1)
 {
		// determining h and m
		//////////////////////////////
		x=strlen(a);
		a[x]=':';
		y=0;

		for(i=0;i<=x;i++)
		 {
			 if(a[i]!=':')
			  {
				 b[y]=a[i];
				 y++;
			  }
			 else
			  {
				 b[y]=NULL;
				 if(i<3) sscanf(b,"%d",&h);
				 else 	sscanf(b,"%d",&m);
				 y=0;
			  }
		 }
		//////////////////////////////


      //////////////////////////////
		 if(h==0 && m==0)
			 break;
		///////////////////////////////
      
		hAngle=h;
		mAngle=m;

	  /////////////////////////////////
		hAngle= (hAngle*30)+ ( ( mAngle/60) *30 );
		mAngle= mAngle*6;
		if(hAngle>=mAngle)
		 mAngle= hAngle-mAngle;
		else
		 mAngle= mAngle-hAngle;

		mAngle=mAngle>180?(360-mAngle):mAngle;

	  //////////////////////////////////



	  ///////////////////////////////////

		 printf("%.3f\n",mAngle);

	  ////////////////////////////////////////

   
  }
}
