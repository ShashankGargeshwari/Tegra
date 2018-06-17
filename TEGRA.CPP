#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream.h>
double Ax = 0 , Ay = 0 , Az = 0 , rx = 300 , ry = 250 , pi = 4*atan(1) , zoom = 1 ;
char key='a' ;
int c = 0 , nplane , kye ;

struct connect
{ int pl1 ; int po1 ;int pl2 ;int po2 ;
};
connect k[30];

class plane
{ public :
  int n ;
  double x[10] , y[10] , z[10] , az[10] , ax[10] , ay[10] , ampx[10] , ampy[10] , ampz[10] ,  prox[10] , proy[10] , proz[10] , dx[10] , dy[10] , dz[10] ;
   void initialize()
   { cout<<"Enter number of points to be Generated " ;
    cin>>n ;
    clrscr();
    cout<<" Enter x , y , z co-ordinates of points ";
    for( int i = 0 ; i<n ; i++ )
    { cin>>x[i]>>y[i]>>z[i];
      dx[i] = x[i] ;
      dy[i] = y[i] ;
      dz[i] = z[i] ;
      ampz[i] = sqrt( pow( x[i] , 2 ) + pow( y[i] , 2 ) ) ;
      ampx[i] = sqrt( pow( z[i] , 2 ) + pow( y[i] , 2 ) ) ;
      ampy[i] = sqrt( pow( x[i] , 2 ) + pow( z[i] , 2 ) ) ;
      /*if( ampz[i]!= 0 ) az[i] = acos(x[i]/ampz[i]) ;
       else
      az[i] = 0 ;
       if(ampy[i] != 0 ) ay[i] = acos(z[i]/ampy[i]) ;
	 else
       ay[i] = 0 ;
      if( ampx[i] != 0 ) ax[i] = acos(y[i]/ampx[i]) ;
	  else
       ax[i] = 0 ;*/
     }
    cout<<" DONE " ;
    getch();
    clrscr();
    dispdat();
     getch();
   }
   void dispdat()
   { clrscr();
   cout<<" \t\t Plain info " ;
   for( int j = 0 ; j < n ; j++ )
      cout<<"Point "<<j+1<<" --> "<<x[j]<<" "<<y[j]<<" "<<z[j]<<" \n" ;
     }
   void modpoint()
   { dispdat();
     int a , b , c ;
     cout<<"\n Enter Point to be modified \n" ;
     cin>>a ;
     a-- ;
     cout<<"\n Enter new co-ordinates \n";
     cin>>x[a]>>y[a]>>z[a];
     dx[a] = x[a] ;
      dy[a] = y[a] ;
      dz[a] = z[a] ;
     dispdat();
    }
    void delpoint()
    { dispdat();
      int a , b , c ;
      cout<<"\n Enter Point to be deleted \n" ;
      cin>>a ;
      a-- ;
      for( ; a < n-1 ; a++ )
	{ x[a] = x[a+1];
	  y[a] = y[a+1];
	  z[a] = z[a+1];
	  dx[a] = x[a] ;
      dy[a] = y[a] ;
      dz[a] = z[a] ;
	}
	n--;
	c = 0 ;
	dispdat();
    }
    void addpoint()
    { dispdat();
      cout<<"\n Enter x , y , z co-ordinates of new point \n" ;
      cin>>x[n]>>y[n]>>z[n];
      dx[n] = x[n] ;
      dy[n] = y[n] ;
      dz[n] = z[n] ;
      n++;

    }
    void gen()
   { for( int i = 0 ; i < n ; i++ )
      {  if( i != n-1 )
	line( (x[i]*(300/(300+z[i]))) + rx , (y[i]*(300/(300+z[i])))+ry , (x[i+1]*(300/(300+z[i+1]))) + rx , (y[i+1]*(300/(300+z[i+1]))) + ry );
	 else
	line( (x[i]*(300/(300+z[i]))) + rx , (y[i]*(300/(300+z[i])))+ry , (x[0]*(300/(300+z[0])))+rx , (y[0]*(300/(300+z[0])))+ry ) ;
       //outtextxy( x[i] + rx , y[i] + rx , "+") ;
      }
      line( rx , ry , rx , ry ) ;
   }
   void movex( double a )
   { for( int i =0 ; i < nplane ; i++ )
       for( int j = 0 ; j < n ; j++ )
	 p1[i].x[j]+=a ;
   }
   void movey( double a )
   { for( int i =0 ; i < nplane ; i++ )
       for( int j = 0 ; j < n ; j++ )
	 p1[i].y[j]+=a ;
   }
   void rotz( double a )
   { for( int i = 0 ; i<n ; i++ )
     { ampz[i] = sqrt( pow( y[i] , 2 ) + pow( x[i] , 2 ) ) ;
       if(ampz[i] != 0 )
	{  if( x[i] > 0 )
	      {  az[i] = asin(y[i]/ampz[i])  ;
	      }
	     else
	   {  if( y[i] > 0 ) az[i] = pi - asin(y[i]/ampz[i]);
		else
	      az[i] = pi - asin(y[i]/ampz[i]);
	   }
	}

	else
	az[i] = 0 ;
	az[i]+= a;
	}
      for( i = 0 ; i< n ; i++ )
     {
       y[i] = ampz[i]*sin(az[i]) ;
       x[i] = ampz[i]*cos(az[i]) ;

     }
   }
   void rotx( double a)
   { for( int i = 0 ; i<n ; i++ )
     { ampx[i] = sqrt( pow( y[i] , 2 ) + pow( z[i] , 2 ) ) ;
       if(ampx[i] != 0 )
       { if( y[i] > 0 )
	      {  ax[i] = asin(z[i]/ampx[i])  ;
	      }
	     else
	   {  if( z[i] > 0 ) ax[i] = pi - asin(z[i]/ampx[i]);
		else
	      ax[i] = pi - asin(z[i]/ampx[i]);
	   }
	 }
	 else
       ax[i] = 0 ;
       ax[i]+= a;
     }
      for( i = 0 ; i< n ; i++ )
     {
       z[i] = ampx[i]*sin(ax[i]) ;
       y[i] = ampx[i]*cos(ax[i]) ;

     }
   }
   void roty( double a)
   {
     for( int i = 0 ; i<n ; i++ )
     { ampy[i] = sqrt( pow( x[i] , 2 ) + pow( z[i] , 2 ) ) ;
       if(ampy[i] != 0 )
       { if( z[i] > 0 )
	      {  ay[i] = asin(x[i]/ampy[i])  ;
	      }
	     else
	   {  if( x[i] > 0 ) ay[i] = pi - asin(x[i]/ampy[i]);
		else
	      ay[i] = pi - asin(x[i]/ampy[i]);
	   }
	}
	 else
       ay[i] = 0 ;
       ay[i]+= a ;
     }
      for( i = 0 ; i< n ; i++ )
     {
       x[i] = ampy[i]*sin(ay[i]) ;
       z[i] = ampy[i]*cos(ay[i]) ;

     }
   }
void moveplane()
{ clrscr();
int a , b ,g ;
  cout<<" Enter x , y , z distances through  which plane is to be moved ";
  cin>>a>>b>>g;
  for( int i = 0 ; i < n ; i++ )
 {  x[i] += a ;
    y[i] += b ;
    z[i] += c ;
    dx[i] = x[i] ;
    dy[i] = y[i] ;
    dz[i] = z[i] ;


 }


}

};
plane p1[10] ;
void newconnection()
{ int a , b , d , e ;
 char ch = 'q' ;
 while( ch != '0')
 { cout<<" Enter plane number , point number of the 2 points int the two planes to be connected " ;
   cin>>k[c].pl1>>k[c].po1>>k[c].pl2>>k[c].po2 ;
   cout<<"/n Continue ? \n"<<" 1. yes /n"<<"\n 0. no \n";
   cin>>ch;
   c++ ;
  }
}
void connections( plane p1[10] )
{ for( int i = 0 ; i < c ; i++ )
    line( p1[k[i].pl1 - 1 ].x[k[i].po1 - 1 ]*(300/(300+p1[k[i].pl1 - 1 ].z[k[i].po1 - 1 ])) + rx , p1[k[i].pl1 - 1 ].y[k[i].po1 - 1 ]*(300/(300+p1[k[i].pl1 - 1 ].z[k[i].po1 - 1 ])) + ry , p1[k[i].pl2 - 1 ].x[k[i].po2 - 1 ]*(300/(300+p1[k[i].pl2 - 1 ].z[k[i].po2 - 1 ])) + rx ,  p1[k[i].pl2 - 1 ].y[k[i].po2 - 1 ]*(300/(300+p1[k[i].pl2 - 1 ].z[k[i].po2 - 1 ])) + ry );
}
void delconnection( )
{ int a , b , f , g , kb = 1 ;
   while( kb != 0 )
   { cout<<" Enter plane number , point number of the 2 points in the two planes whose connector is to be erased " ;
     cin>>a>>b>>f>>g;
     for( int i = 0 ; i < c ; i++ )
     {  if(  (k[i].pl1 == a && k[i].po1 == b && k[i].pl2 == f && k[i].po2 == g ) || (k[i].pl1 == f && k[i].po1 == g && k[i].pl2 == a && k[i].po2 == b )  )
	 {for( int j = i ; j < c ; j++ )
	   k[j] = k[j+1] ;
		c-- ;
	 }

      }
    cout<<"/n Continue ? \n"<<" 1. yes /n"<<"\n 0. no \n";
    cin>>kb ;
   }
}
/*void delconnectionpl( int delpl )
{ int a , b , f , g , kb = 1 ;
   while( kb != 0 )
   {  for( int i = 0 ; i < c ; i++ )
     {  if(  k[i].pl1 == delpl || k[i].pl2 == delpl  )
	 {for( int j = i ; j < c ; j++ )
	   k[j] = k[j+1] ;
		c-- ;
	 }

      }
    cout<<"/n Continue ? \n"<<" 1. yes /n"<<"\n 0. no \n";
    cin>>kb ;
   }
}
void delconnectionpo( int delpo )
{ int a , b , f , g , kb = 1 ;
   while( kb != 0 )
   {  for( int i = 0 ; i < c ; i++ )
     {  if(  k[i].po1 == delpo  )
	 {for( int j = i ; j < c ; j++ )
	   k[j] = k[j+1] ;
	   k[j].po1-- ;
	     c-- ;
	 }
	 else
	 if(k[i].po2 == delpo  )
	 { for( int j = i ; j < c ; j++ )
	   k[j] = k[j+1] ;
	   k[j].po2-- ;
	     c-- ;
	 }
      }
    cout<<"/n Continue ? \n"<<" 1. yes /n"<<"\n 0. no \n";
    cin>>kb ;
   }
}*/
void modplane( plane p1[10] )
{ int ent = 7 , i ;
  while( ent != 0 )
 { cout<<" Enter plane number to be modified \n" ;
  cin>>i;
  i-- ;
  cout<<" \t\t\tMENU\n" ;
  cout<<" 1. Add point \n";
  cout<<" 2. Delete point \n";
  cout<<" 3. Modify point \n";
  cout<<" 4. Modify connections \n";
  cout<<" 5. Move Plane ";
  cout<<" 0. Quit Menu\n";

  cin>>ent ;
  switch(ent)
  { case 1 : p1[i].addpoint();
      break ;
    case 2 : p1[i].delpoint();
      break ;
    case 3 : p1[i].modpoint();
      break;
    case 4 : cout<<" \n 1. New connection 2. Delete connection " ;
	cin>>kye ;
	if( kye == 1 ) newconnection() ;
	  else
	delconnection() ;
      break;
     case 5 : p1[i].moveplane();
      break ;
    }
    }
    }
void delplane()
{ clrscr();
  int plan ;
  cout<<"Enter plane number to be deleted \n" ;
  cin>>plan ;
  plan-- ;
  for( int i = plan ; i < nplane-1 ; i ++ )
   { p1[i] = p1[i+1] ;
   }
   nplane-- ;
   c = 0 ;
}
void menu(plane p1[10])
{ cleardevice();
  closegraph();
  int ent = 7 ;
  int i , j , k ;
  for( k = 0 ; k < nplane ; k++ )
	     for( j = 0 ; j < p1[k].n ; j++ )
		{ p1[k].x[j] = p1[k].dx[j] ;
		  p1[k].y[j] = p1[k].dy[j] ;
		  p1[k].z[j] = p1[k].dz[j] ;

     }
  while( ent != 0 )
  {cout<<" 1. Add new plane \n";
  cout<<" 2. Edit plane    \n" ;
  cout<<" 3. Delete plane \n" ;
  cout<<" 0.  Exit \n";
  cin>>ent;
  switch(ent)
  { case 1 : p1[nplane].initialize();
	nplane++;
     break;
    case 2 : modplane(p1);
     break ;
    case 3 : delplane();
     break ;
    case 0 : {};
     break;
  }
  }
}


void main()
{
  cout<<" ENTER NUMBER OF PLANE " ;
  cin>>nplane;
  for( int i = 0 ; i < nplane ; i++ )
  { p1[i].initialize();
  }
  if( nplane > 1 ) newconnection();

  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   while( key != '*' )
    {
      key = getch() ;
      switch(key)
      { case 'a' :
      for( int i = 0 ; i<nplane ; i++ )
	  p1[i].roty(0.1);
	   break;
	case 'd' :   for(  i = 0 ; i<nplane ; i++ )
	  p1[i].roty(-0.1)   ;
	   break;
	case 'w' :   for(  i = 0 ; i<nplane ; i++ )
	  p1[i].rotx(-0.1) ;
	   break;
	case 's' :   for(  i = 0 ; i<nplane ; i++ )
	  p1[i].rotx(+0.1) ;
	   break;
	case 'q' :   for(  i = 0 ; i<nplane ; i++ )
	  p1[i].rotz(-0.1) ;
	   break;
	case 'e' :   for(  i = 0 ; i<nplane ; i++ )
	  p1[i].rotz(+0.1) ;
	   break;
	 case '=' : zoom+=0.1 ;
	  for( int s = 0 ; s < nplane ; s++ )
	     for( int j = 0 ; j < p1[s].n ; j++ )
		{ p1[s].x[j] *= zoom ;
		  p1[s].y[j] *= zoom ;
		  p1[s].z[j] *= zoom ;
		}
	   break ;
	 case '-' : if( zoom > 0 ) zoom-=0.1 ;
	 for( s = 0 ; s < nplane ; s++ )
	     for( j = 0 ; j < p1[s].n ; j++ )
		{ p1[s].x[j] *= zoom ;
		  p1[s].y[j] *= zoom ;
		  p1[s].z[j] *= zoom ;

     }
     break ;
     case 'i' : for(  i = 0 ; i < nplane ; i ++ )
		     p1[i].movey(-1);
	       break ;
     case 'k' : for( i = 0 ; i < nplane ; i ++ )
		      p1[i].movey(1);
	       break ;
     case 'j' : for(  i = 0 ; i < nplane ; i ++ )
		       p1[i].movex(-1);
	       break ;
     case 'l' : for(  i = 0 ; i < nplane ; i ++ )
		       p1[i].movex(1);
	       break ;
	   case 'm' :{ menu(p1) ;
		      int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  }
     break ;
     }

     zoom = 1 ;
     cleardevice();
      for(  i = 0 ; i<nplane ; i++ )
	  p1[i].gen();
      connections(p1);
    }



}