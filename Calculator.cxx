#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
char s[5] = "sin", l[5] = "log",c[5]="cos",t[5]="tan",sc[5]="sec",ct[6]="cot";
class func
{
  public:
 float coeff, anscoeff, powr, anspow, inpow, ansinpow, incoeff, ansincoeff=1,cnst;
 char signn, anssign, f[10], ansf[10], inf[10], ansinf[10];

 void getfunc()
 {
cin>>signn;
cin>>coeff;
while(1)
{
if(cin.fail())
{ clrscr();
 cout << "\t\tNORMAL DIFFERENTIATION\n\n";
 cout << "\t\t Basic(With one step chain rule)\n\n";
cout << "\n\tSpecial Functions-\n\t-Sin\t-Log\t-Cos\n\t-Cot\t-Tan\n" << endl;
  cout << "Enter in order-- Sign : coefficent : function : power." << endl << endl;
  
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<signn<<"\n";
cin>>coeff;
}
if(!cin.fail())
break;
}
  cin>> f;
  cin>>powr;
  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
  {
   cout << "\nEnter details of sub-function--coefficent : function : power\n";
   cin >> incoeff >> inf;
   cin >> inpow;
  }
 }

 void putfunc()
 {
  if (coeff == 0)
   cout << " " << signn << " " << 0 ;
  else if (coeff < 0)
{
   coeff = coeff * (-1);
   if (signn == '+')
    signn = '-';
   else if (signn == '-')
    signn = '+';
  }
  if (coeff != 0)
 {
   if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0)|| (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
 {
    if (incoeff == 0)
     cout << " " << signn << " " << coeff << "[" << f << 0 << "]"
       << "^" << powr ;
    else if (incoeff != 0)
     cout << " " << signn << " " << coeff << "[" << f << "(" << incoeff << inf << "^" << inpow << ")]"
       << "^" << powr ;
   }
   else
    cout << " " << signn << " " << coeff << f << "^" << powr<<"\n" ;
  }
 }

 void differentiation()
{
  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0)|| (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
{  ansincoeff=1;
   ansincoeff = incoeff * inpow;
   anscoeff = powr * coeff * ansincoeff;
   if((strcmp(f, c) == 0) || (strcmp(f, ct) == 0))
   anscoeff*=-1;
   
   if (strcmp(f, s) == 0)
    strncpy(ansf, "cos", 7);
   else if (strcmp(f, l) == 0)
    strncpy(ansf, "1/", 7);
         else if (strcmp(f, c) == 0)
    strncpy(ansf, "sin", 7);
   else if (strcmp(f, t) == 0)
    strncpy(ansf, "sec^2", 7);
   else if (strcmp(f, ct)==0)
    strncpy(ansf, "cosec^2", 8);
   ansinpow = inpow - 1;
  }
  else
   anscoeff = powr * coeff;
  anspow = powr - 1;
  if (anscoeff < 0)
 {
   anscoeff = anscoeff * (-1);
   if (signn == '+')
    anssign = '-';
   else if (signn == '-')
    anssign = '+';
  }
  else if (anscoeff > 0)
   anssign = signn;
 }

 void putdiff()
 {
  if ((anscoeff == 0) || (ansincoeff == 0))
   cout << " " << anssign << " " << 0 ;
  else if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0)|| (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
 {
   if (anspow == 0)
   {
    if (ansinpow == 0)
     cout << " " << anssign << " " << anscoeff << "[" << ansf << "(" << incoeff << inf << ")"
       << "]"
       << " d" << inf ;
    else if (ansinpow == 1)
     cout << " " << anssign << " " << anscoeff << inf << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
    else
     cout << " " << anssign << " " << anscoeff << inf << "^" << ansinpow << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
   }
   else if (anspow == 1)
{
    if (ansinpow == 0)
     cout << " " << anssign << " " << anscoeff << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
    else if (ansinpow == 1)
     cout << " " << anssign << " " << anscoeff << inf << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
    else
     cout << " " << anssign << " " << anscoeff << inf << "^" << ansinpow << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
   }
   else
  {
    if (anspow == 0)
     cout << " " << anssign << " " << anscoeff << "[" << f << "(" << incoeff << inf << "^"
       << ")"
       << "]^" << anspow << "[" << ansf << "(" << incoeff << inf << "^"
       << ")"
       << "]"
       << " d" << inf ;
    else if (anspow == 1)
     cout << " " << anssign << " " << anscoeff << inf << "[" << f << "(" << incoeff << inf << "^" << inpow << ")"
       << "]^" << anspow << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
    else
     cout << " " << anssign << " " << anscoeff << inf << "^" << ansinpow << "[" << f << "(" << incoeff << inf << "^" << inpow << ")"
       << "]^" << anspow << "[" << ansf << "(" << incoeff << inf << "^" << inpow << ")"
       << "]"
       << " d" << inf ;
   }
  }
  else
{
   if (anspow == 0)
    cout << " " << anssign << " " << anscoeff << " d" << f ;
   else if (anspow == 1)
    cout << " " << anssign << " " << anscoeff << f << " d" << f ;
   else
    cout << " " << anssign << " " << anscoeff << f << "^" << anspow << " d" << f ;
  }
 }

void cof()
{ clrscr();
   
 cout << "\t\t ADVANCED DIFFERENTIATION\n\n";
 cout << "\t\t\t CONSTANT^f(x)\n\n";
  cout << "\n\tSpecial Functions-\n\t-Sin\t-Log\t-Cos\n\t-Cot\t-Tan\n\n" ;
 cout<<"Enter Constant:";
 cin>>cnst;
 cout << "\nEnter details of Function--coefficent : Function : Power\n";
  cin >> coeff >> f>>powr;
  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
 {
  cout << "\nEnter details of sub-function--coefficent : function : power\n";
   cin >> incoeff >> inf;
   cin >> inpow;
  }

  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
cout<<"\n\tProblem : "<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]" ;
else
cout<<"\n\t Problem : "<<cnst<<"^["<<coeff<<f<<"^"<<powr<<"]" ;


differentiation();

if((cnst==0)||(cnst==1))
cout<<"\n\n\tSolution : "<<0 ;

else if (anscoeff == 0)
 cout << 1 ;
  else if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0)|| (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
 {
   if (anspow == 0)
   {
    if (ansinpow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<ansf<<inf<<l<<cnst<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<<" d"<<inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<< " d" <<inf ;
   }
   else if (anspow == 1)
   {
    if (ansinpow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<")"<<ansf<<inf<<l<<cnst<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<< " d" << inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<< " d" <<inf ;
   }
   else
   {	if(ansinpow==0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<")]^"<<anspow<<ansf<<inf<<l<<cnst<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")]^"<<anspow<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<< " d" << inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<cnst<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")]^"<<anspow<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<l<<cnst<< " d" <<inf ;
   }
  }
  else
  {
   if (anspow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<cnst<<"^["<<coeff<<f<<"^"<<powr<<"]"<<l<<cnst<< " d" << f ;
   else if (anspow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<f<<"*"<<cnst<<"^["<<coeff<<f<<"^"<<powr<<"]"<<l<<cnst<< " d" << f ;
   else
cout<<"\n\n\tSolution :"<<anscoeff<<f<<"^"<<anspow<<"*"<<cnst<<"^["<<coeff<<f<<"^"<<powr<<"]"<<l<<cnst<< " d" << f ;
  }

}

void getfof()
{cin >>coeff >> f;
 if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))cin>>inf;
 cin>>powr;
}


void putfof(func fy)
{ fy.coeff=fy.coeff+powr;
 if(coeff==0)
  cout<<"\n\n\tProblem :"<<0 ;

  else if (fy.coeff==0)
  cout<<"\n\n\tProblem :"<<1 ;

  else if (((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))&&((strcmp(fy.f, s) == 0) || (strcmp(fy.f, l) == 0) || (strcmp(fy.f, c) == 0) || (strcmp(fy.f, t) == 0) || (strcmp(fy.f, ct) == 0)))
   cout<<"\n\n\tProblem : "<<coeff<<"["<<f<<inf<<"]^{"<<fy.coeff<<"("<<fy.f<<fy.inf<<")^"<<fy.powr<<"}*" ;

   else if(((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))&&((strcmp(fy.f, s) != 0) || (strcmp(fy.f, l) != 0) || (strcmp(fy.f, c) != 0) || (strcmp(fy.f, t) != 0) || (strcmp(fy.f, ct) != 0)))
   cout<<"\n\n\tProblem : "<<coeff<<"["<<f<<inf<<"]^("<<fy.coeff<<fy.f<<"^"<<fy.powr<<")"
 ;
   else if(((strcmp(f, s) != 0) || (strcmp(f, l) != 0) || (strcmp(f, c) != 0) || (strcmp(f, t) != 0) || (strcmp(f, ct) != 0))&&((strcmp(fy.f, s) == 0) || (strcmp(fy.f, l) == 0) || (strcmp(fy.f, c) == 0) || (strcmp(fy.f, t) == 0) || (strcmp(fy.f, ct) == 0)))
cout<<"\n\n\tProblem : "<<coeff<<f<<"^["<<fy.coeff<<"("<<fy.f<<fy.inf<<")^"<<fy.powr<<"]" ;

  else
cout<<"\n\tProblem : "<<coeff<<"("<<f<<"^"<<powr<<")"<<"^["<<fy.coeff<<fy.f<<"^"<<fy.powr<<"]" ;
}

void fofdiff()
{
if((strcmp(f, c) == 0) || (strcmp(f, ct) == 0))incoeff=powr*-1;
else
incoeff=powr;

  if(incoeff>=0)
{signn='+';}
else if (incoeff<0)
{signn='-';
incoeff=powr*-1;}

anspow=powr-1;

 if((strcmp(f, c) == 0) || (strcmp(f, ct) == 0))incoeff*=-1;

      if (strcmp(f, s) == 0)
    strncpy(ansf, "cos", 7);
   else if (strcmp(f, l) == 0)
    strncpy(ansf, "1/", 7);
else if (strcmp(f, c) == 0)
    strncpy(ansf, "sin", 7);
   else if (strcmp(f, t) == 0)
    strncpy(ansf, "sec^2", 7);
   else if (strcmp(f, ct)==0)
    strncpy(ansf, "cosec^2", 8);

}
void fof(func fy)
{clrscr();
 cout << "\t\t ADVANCED DIFFERENTIATION\n\n";
 cout << "\t\t\t g(x)^f(x)\n\n";
  cout << "\n\tSpecial Functions-\n\t-Sin\t-Log\t-Cos\n\t-Cot\t-Tan\n" ;
     cout<<"\tEnter in Order:\n\tCoefficient : Function : Sub-Function : Power";
  cout<<"\n\nEnter g(x) :\n";
  getfof();
 cout<<"\n\nEnter f(x) : \n";
  fy.getfof();
  putfof(fy);
  fofdiff();
  fy.fofdiff();

fy.coeff=fy.coeff+powr;
anscoeff=coeff*fy.coeff;

    if (((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))&&((strcmp(fy.f, s) == 0) || (strcmp(fy.f, l) == 0) || (strcmp(fy.f, c) == 0) || (strcmp(fy.f, t) == 0) || (strcmp(fy.f, ct) == 0)))
cout<<"\n\n\tSolution : \n\t "<<anscoeff<<"[("<<fy.f<<fy.inf<<")^"<<fy.anspow<<"]"<<"["<<f<<inf<<"]^{"<<fy.coeff<<"("<<fy.f<<fy.inf<<")^"<<fy.powr<<"}"<<"["<<ansf<<inf<<fy.f<<fy.inf<<"(1/"<<f<<inf<<")"<<"d"<<inf<<fy.signn<<fy.incoeff<<l<<"("<<f<<inf<<")"<<fy.ansf<<fy.inf<<"d"<<fy.inf<<"]" ;

else if(((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))&&((strcmp(fy.f, s) != 0) || (strcmp(fy.f, l) != 0) || (strcmp(fy.f, c) != 0) || (strcmp(fy.f, t) != 0) || (strcmp(fy.f, ct) != 0)))
cout<<"\n\n\tSolution : \n\t"<<anscoeff<<fy.f<<"^"<<fy.anspow<<"["<<f<<inf<<"]^{"<<fy.coeff<<fy.f<<"^"<<fy.powr<<"}"<<"["<<ansf<<inf<<"(1/"<<f<<inf<<")"<<"d"<<inf<<fy.signn<<fy.incoeff<<l<<"("<<f<<inf<<")"<<"d"<<fy.inf<<"]" ;

   else if(((strcmp(f, s) != 0) || (strcmp(f, l) != 0) || (strcmp(f, c) != 0) || (strcmp(f, t) != 0) || (strcmp(f, ct) != 0))&&((strcmp(fy.f, s) == 0) || (strcmp(fy.f, l) == 0) || (strcmp(fy.f, c) == 0) || (strcmp(fy.f, t) == 0) || (strcmp(fy.f, ct) == 0)))
 cout<<"\n\n\tSolution : \n\t "<<anscoeff<<f<<"^{"<<fy.coeff<<"("<<fy.f<<fy.inf<<")^"<<fy.powr<<"}"<<"[("<<fy.f<<fy.inf<<")^"<<fy.anspow<<"]["<<fy.f<<fy.inf<<"(1/"<<f<<")"<<"d"<<f<<fy.signn<<fy.incoeff<<l<<f<<fy.ansf<<fy.inf<<"d"<<fy.inf<<"]" ;

   else{
 if(anscoeff==0)
 cout<<"\n\n\tSolution : "<<0 ;
 else if (powr==0)
 cout<<"\n\n\tSolution : "<<anscoeff<<fy.f ;
  else
cout<<"\n\n\tSolution : "<<anscoeff<<fy.f<<"^"<<fy.anspow<<"("<<f<<"^"<<powr<<")^("<<fy.coeff<<fy.f<<"^"<<fy.powr<<")["<<powr<<signn<<fy.incoeff<<l<<"("<<f<<"^"<<powr<<")" ;
   }
}


void eof()
{
clrscr();
   
 cout << "\t\t ADVANCED DIFFERENTIATION\n\n";
 cout << "\t\t\t e^f(x)\n\n";
  cout << "\n\tSpecial Functions-\n\t-Sin\t-Log\t-Cos\n\t-Cot\t-Tan\n" ;
 cout << "\nEnter details of Function--coefficent : Function : Power\n";
  cin >> coeff >> f>>powr;
  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
  {
   cout << "\nEnter details of sub-function--coefficent : function : power\n";
   cin >> incoeff >> inf;
   cin >> inpow;
  }

  if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
cout<<"\n\tProblem : "<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]" ;
else
cout<<"\n\t Problem : "<<"e" <<"^["<<coeff<<f<<"^"<<powr<<"]";


differentiation();


if (anscoeff == 0)
 cout<<"\n\n\tSolution : "<<1;
  else if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0)|| (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
  {
   if (anspow == 0)
   {
    if (ansinpow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<ansf<<inf<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<" d"<<inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<< " d" <<inf ;   }
   else if (anspow == 1)
   {
    if (ansinpow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<")"<<ansf<<inf<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<< " d" << inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<< " d" <<inf ;
   }
   else
   {	if(ansinpow==0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<")]^"<<anspow<<ansf<<inf<< " d" << inf ;
    else if (ansinpow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")]^"<<anspow<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<< " d" << inf ;
    else	cout<<"\n\n\tSolution : "<<anscoeff<<inf<<"^"<<ansinpow<<"*"<<"e" <<"^["<<coeff<<"{"<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")"<<"}^"<<powr<<"]"<<"["<<f<<"("<<incoeff<<inf<<"^"<<inpow<<")]^"<<anspow<<ansf<<"("<<incoeff<<inf<<"^"<<inpow<<")"<< " d" <<inf ;
   }
  }
  else
  {
   if (anspow == 0)	cout<<"\n\n\tSolution : "<<anscoeff<<"*"<<"e" <<"^["<<coeff<<f<<"^"<<powr<<"]"<< " d" << f ;
   else if (anspow == 1)	cout<<"\n\n\tSolution : "<<anscoeff<<f<<"*"<<"e" <<"^["<<coeff<<f<<"^"<<powr<<"]"<< " d" << f ;
   else
cout<<"\n\n\tSolution :"<<anscoeff<<f<<"^"<<anspow<<"*"<<"e" <<"^["<<coeff<<f<<"^"<<powr<<"]"<< " d" << f ;
  }
}


int getchain(int i,int cc)
{ int a=0;
   if(i==0) cout<<"\n\tEnter in Order : Coefficient : Function\n";
     cout<<"Function "<<i+1<<"\t : ";
 cin>>coeff;
 cout<<"\t\t ";
 cin>>f;
 if(i==cc-1)
  { if ((strcmp(f, s) == 0) || (strcmp(f, l) == 0) || (strcmp(f, c) == 0) || (strcmp(f, t) == 0) || (strcmp(f, ct) == 0))
  {cout<<"\tFunction "<<i+1<<" is replaced with 'x'";
  strncpy(f, "x",3);
  }
   cout<<"\n\tEnter Power : ";
   cin>>powr;

 }
 else if((strcmp(f, s) != 0) && (strcmp(f, l) != 0) &&(strcmp(f, c) != 0)&&(strcmp(f, t) != 0) && (strcmp(f, ct) != 0))
  {a=0;
 cout<<"\tEnter Power : ";
   cin>>powr;
 a=1;}
 return(a);
  }


};
func f[5], fx,fy;

void chain()
{ int a=0,n,cc,y;
  clrscr();
cout << "\t\tNORMAL DIFFERENTIATION\n\n";
 cout << "\tf(g(h(q(w)))) { Multi step chain rule}";
 cout<<"\n\n\tEnter maximum no. Of Functions";
 cin>>cc;
 if(cc>10)
 cc=10;
 for(int i=0;a==0&&i<cc;i++)
 { a=f[i].getchain(i,cc);
  n=i;}
  clrscr();
cout << "\t\tNORMAL DIFFERENTIATION\n\n";
 cout << "\tf(g(h(q(w)))) { Multi step chain rule}";
cout<<"\n\n\tProblem : ";
f[0].anscoeff=1;
  for( int i=0;i<=n;i++)
 { if(i==n)
{ cout<<f[i].coeff<<f[i].f<<"^"<<f[i].powr;
  for(int y=0;y<n;y++)
  cout<<")";
}
else
cout<<f[i].coeff<<f[i].f<<"( ";

    f[0].anscoeff*=f[i].coeff;
     if(i<n)
     {	if (strcmp(f[i].f, s) == 0)
    strncpy(f[i].ansf, "cos", 7);
   else if (strcmp(f[i].f, l) == 0)
    strncpy(f[i].ansf, "1/", 7);
else if (strcmp(f[i].f, c) == 0)
    strncpy(f[i].ansf, "sin", 7);
   else if (strcmp(f[i].f, t) == 0)
    strncpy(f[i].ansf, "sec^2", 7);
   else if (strcmp(f[i].f, ct)==0)
    strncpy(f[i].ansf, "cosec^2", 8);
     }
     f[n].anspow=f[n].powr-1;
     if((strcmp(f[i].f, ct)==0)||(strcmp(f[i].f, c)))
     f[0].anscoeff*=-1;
 }
 f[0].anscoeff*=f[n].powr;
 if(f[0].anscoeff==0)
 cout<<"\n\n\tSolution : "<<0;
 else{
 cout<<"\n\n\tSolution : ";
 cout<<f[0].anscoeff;
 for(int i=0;i<n;i++)
 {
 cout<<f[i].ansf;
 y=i+1;
 for( ;y<=n;y++)
 {cout<<"("<<f[y].coeff<<f[y].f;
  if(y==n)
{  if(f[n].anspow==1)
  cout<<" ";
  else if(f[n].anspow==0)
  cout<<1;
  else
  cout<<"^"<<f[n].powr;
  }
  }
 for(y=0;y<=n-i;y++)
 cout<<")";
 cout<<"*";
 }
if(f[n].anspow==1)
cout<<f[n].f<<" d"<<f[n].f;
else if(f[n].anspow==0)
cout<<" d"<<f[n].f;
 else
 cout<<f[n].f<<"^"<<f[n].anspow<<" d"<<f[n].f;

 }
}


void ndiff()
 { char ans='y',ch;
     int n;

     clrscr();
   for(int error=0;error==0;)
 {
 cout << "\t\tNORMAL DIFFERENTIATION\n\n";
 cout << "\t\t1- Basic(With one step chain rule)\n\n\t\t2- f(g(h(q(w)))) { Multi step chain rule}\n\n\t\t3- Product/Quotient rule\n\n\t\t4- Exit" << endl;
 cin >> ch;
 if((ch!='1')&&(ch!='2')&&(ch!='3')&&(ch!='z')&&(ch!='4'))
 { clrscr();
    error=0;}
 else
 error=1;
    }
    if(ch=='1')
    {
  cout << "\n\tSpecial Functions-\n\t-Sin\t-Log\t-Cos\n\t-Cot\t-Tan\n" << endl;
  cout << "Enter in order-- Sign : coefficent : function : power." << endl
    << endl;

  for (int i = 0; i < 5 && (ans == 'y'); i++)
  {
   f[i].getfunc();
   n = i;
   cout << "\tEnter More? YES : y NO : Press Any key";
   cin >> ans;
   cout << endl;
  }


  cout << "\n\n";
  cout << "\t Problem : ";

  for ( int i = 0; i <= n; i++)
   f[i].putfunc();

  for ( int i = 0; i <= n; i++)
   f[i].differentiation();

  cout << "\n\n";
  cout << "\tSolution : ";

  for (int i = 0; i <= n; i++)
   f[i].putdiff();

}

else if(ch=='2')
{ clrscr();
  cout << "\t\tNORMAL DIFFERENTIATION\n\n";
 cout << "\tf(g(h(q(w)))) { Multi step chain rule}\n\n";
chain();
}
else if (ch=='3')
cout<<"working";
else if (ch=='4')
exit(0);
else if (ch=='z')
cout<<"Credits-PuRgE_CoDeE";
 }

void adiff()
 { char ch;
  clrscr();
 for(int error=0; error==0;) 
 {
  cout << "\t\t ADVANCED DIFFERENTIATION\n\n";
  cout << "\t\t1- constant^f(x)\n\n\t\t2- f(x)^g(x)\n\n\t\t3- e^f(x)"<< endl;
  cin >> ch;
   if((ch!='1')&&(ch!='2')&&(ch!='3')&&(ch!='z'))
 { clrscr();
    error=0;}
 else
 error=1;
    } 
  
  if (ch == '1')
   fx.cof();
  else if (ch == '2')
   fx.fof(fy);
     else if (ch=='3')
         fx.eof();
      else if (ch=='z')
    cout<<"Credits-PuRgE_CoDeE";
 }



int main()
{ clrscr();
     
 int error,w=0;
 char ch,waste,wstint=0;
 while(1)
 {  if(wstint!=0)
  {cout<<"\n\n\t\tPress Any Key...";
 cin>>waste;
 clrscr(); }
 wstint=1;
 for(error=0;error==0;)
 {
 cout << "\t\tDIFFERENTIATION\n\n";
 cout << "\t\t1- Normal\n\n\t\t2- Advanced\n\n\t\t3- Exit" << endl;
 cin >> ch; 
 if((ch!='1')&&(ch!='2')&&(ch!='3')&&(ch!='z'))
 { clrscr();
    error=0;}
 else
 error=1;
    } 
  if(ch=='1')
 ndiff();
     
     else if (ch == '2')
   adiff();
    
    else if (ch=='3')
    exit(0);
    
    else if (ch=='z')
    cout<<"Credits-PuRgE_CoDeE";
    
    
 getch();

}
}