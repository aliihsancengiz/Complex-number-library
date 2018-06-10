#ifndef _COMPLEX
#define _COMPLEX
#include<cmath>
#include<iostream>
#include "polarform.h"


class complex : polar{
	private:
		double real,im,Arg;
		//calculate principal argument of complex number
		void calcArg(){	this->Arg=atan2(this->im,this->real)*(180/M_PI);}
		//calculate polar fporm of complex number
		void calcPolar(){	this->module=this->getnorm();	this->s=asin((this->im)/module)*(180/M_PI);		this->c=acos((this->im)/module)*(180/M_PI);	}						 
		public:
		complex(double,double);						//Default Constructor
		complex operator+(const complex b);			//Addition operator
		complex operator-(const complex s);			//Substraction operator
		complex operator*(const complex m);			//Multiplication operator
		complex operator~();						//Conjugate operator
		complex operator/(float x);					//divede the copmlex number to x
		friend complex powc(complex x,int a);		//calculte power of complex number
		double getimg(){	return (this->im);}		//Getting imaginary part of complex number
		double getreal(){	return (this->real);}	//Getting real part of complex number
		double getnorm();							//Get norm of number
		double getsin();							//Get sin of Arg
		double getcos();							//Get cos of Arg
		double getArg();							//Get principal argument of complex number
		void polarform();							//print the polar form of complex Number
		friend complex expc(complex a);				//Calculate the exp of given complex number
		friend complex cosc(complex param);			//Calculate cosine of given complex number	
		friend complex sinc(complex param);			//Calculate sin of given complex number
		friend complex sinhc(complex param);		//Calculate sinh of given complex number	
		friend complex coshc(complex param);		//Calculate cosh of given complex number	
		
};
complex :: complex(double r=0,double i=0){	this->real=r;	this->im=i;	this->calcArg();	this->calcPolar();	}	//Default constructor
complex complex::operator+(const complex b){
	complex t(0,0);	//temporary object
	t.real=(this->real)+(b.real);
	t.im=(this->im)+(b.im);
	return t;
}
complex complex::operator-(const complex s){
	complex t(0,0);	//temporary object
	t.real=(this->real)-(s.real);
	t.im=(this->im)-(s.im);
	return t;
}
complex complex::operator*(const complex m){	
	/*
	complex number mmultiplication
	(a+ib)*(c+id)=(ac-bd)+i(ad+bc)
	*/
	complex t(0,0);	//temporary object
	t.real=((this->real)*(m.real))-((this->im)*(m.im));
	t.im=((this->real)*(m.im))+((this->im)*(m.real));
	return t;
}
complex complex::operator~(){
	complex t(0,0);	//temporary object
	t.real=(this->real);
	t.im=(-1)*(this->im);
	return t;
}
complex complex::operator/(float x){
	float a,b;
	a=this->real/x;
	b=this->im/x;
	complex temp(a,b);
	return temp;
}
double complex::getnorm(){
	//norm = ((real)^2+(im)^2)^(1/2)
	return (sqrt((this->real*this->real)+(this->im*this->im)));
}
double complex::getArg(){
	return (this->Arg);
}
void complex::polarform(){
		std::cout<<"Polar form :"<<this->module;	
		std::cout<<"( cos("<<this->c<<") + isin(";
		std::cout<<this->s<<")"<<") "<<std::endl;
}
double complex::getsin(){
	return (this->s);
}
double complex::getcos(){
	return (this->c);
}
complex powc(complex x,int a){
	int i=0;
	complex temp=x;
	for(i=1;i<a;i++){
		temp=temp*x;	
	}
	return temp;	
}
complex expc(complex a){
	float x,y;
	x=exp(a.getreal())*cos(a.getimg()*M_PI/180);
	y=exp(a.getreal())*sin(a.getimg()*M_PI/180);
	complex temp(x,y);
	return temp;
	
}
complex cosc(complex param){
	complex a(0,1),b(0,-1),r(0,0);
	r=((expc(a*param))+(expc(b*param)))/2;
	return r;
}
complex sinc(complex param){
	complex a(0,1),b(0,-1),r(0,0);
	r=((expc(a*param))-(expc(b*param)))/2;
	return r;
}
complex cosh(complex param){
	complex r(0,0);
	r=((expc(param))+(expc(~param)))/2;
	return r;	
}
complex sinh(complex param){
	complex r(0,0);
	r=((expc(param))-(expc(~param)))/2;
	return r;	
}

#endif
