#ifndef _SOLVE
#define _SOLVE
#ifndef _COMPLEX
#include "c_complex.h"
#endif
#include<vector>
using namespace std;
vector<complex> solve(complex a,float b){
	vector<complex>roots;
	float x,y;
	x=a.getnorm();
	x=pow(x,1.0/b);
	y=(a.getArg())/b;
	y=y*M_PI/180.0;
	float a1,a2;
	int i;
	for(i=0;i<b;i++){
		a1=x*(cos(y+(2*M_PI*i)/b));
		a2=x*(sin(y+(2*M_PI*i)/b));
		complex t(a1,a2);
		roots.insert(roots.end(),t);
	}
	return roots;
}
void printroots(vector<complex> param){
	int x,i;
	x=param.size();
	complex t(0,0);
	for(i=0;i<x;i++){
		t=param[i];
		cout<<i+1<<".root is : "<<t.getreal()<<"  + i "<<t.getimg()<<"   "<<endl;
	}
}
#endif
