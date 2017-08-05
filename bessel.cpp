#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

const double pi = 3.1415926;


double f(double x,double g, double t){
double y=(cos(g*x-t*sin(x)))/pi;
return y;
}

double f1(double x,double g, double t){
double y=sin(g*pi)*((exp(-(t*sinh(x))-(g*x)))/pi);
return y;
}


double trapezoid(double (f)(double,double,double),double a, double b, int n,double g, double t){

double r, dx, x;
r=0.0;
dx=(b-a)/(static_cast<float>(n));

for(int i=1; i<=n-1;i++){
x= a+static_cast<float>(i)*dx;
r=r+f(x,g,t);
}

r=(r+(f(a,g,t)+f(b,g,t))/2)*dx;
return r;

}

int main(){
double a,a1,b1,b,simp,simp1,simpi,simp1i,g,t,ti,tc;
int m,mc, n,n1, nofun;
long int k, ntimes;
cout.precision(4);
cout.setf(ios::fixed | ios::showpoint);
cout<<"que orden de la Bessel quiere?"<<endl;
cin>>g;
cout<<"que cero de la Bessel quiere?"<<endl;
cin>>m;
mc=0;
t=0.005;
a=0;
b=pi;
a1=0;
b1=40000;
n=2000;
n1=200000;
ntimes=80000000;
simp=0,
simp1=0;

for(k=1; k<=ntimes;k++){
	simpi=simp;
	simp1i=simp1;
	ti=t;
	simp=trapezoid(f,a,b,n,g,t);
	simp1=trapezoid(f1,a1,b1,n1,g,t);
	t=t+0.002;
	if(((simpi-simp1i)<0 &&(simp-simp1)>0) ||((simpi-simp1i)>0 &&(simp-simp1)<0) ){
		mc=mc+1;
		tc=(ti+t)/2;
	}
	if(mc==m){
		break;
	}
}
cout<<"El cero numero "<<m<<" es aproximadamente "<<tc<<endl;
}

