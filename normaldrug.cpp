#include <iostream>
#include "header.h"
#include <sstream>

using namespace std;

NormalDrug::NormalDrug(long id,std::string name,
								 double p,int n,double d)
	:Commodity(id,name,p,n),discount(d){}

NormalDrug::NormalDrug(std::string name,double p,
								 int n,double d)
	:Commodity(name,p,n),discount(d){}

double NormalDrug::getNetPrice()const{
	return Commodity::getNetPrice()*discount;
}

void NormalDrug::output()const{
	Commodity::output();
	cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
	   <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
	  <<discount<<" )\n";
}


int NormalDrug::getType()const{
	return NORMAL;
}

string NormalDrug::getInfo()const{
	ostringstream ostr;
	ostr<<getType()<<" "; //先输出类型编码
	ostr<<Commodity::getInfo (); //输出基类的信息
	ostr<<discount<<endl; //输出子类信息
	return ostr.str();
}

void NormalDrug::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}

void NormalDrug::printEditMenu(){
	Commodity::printEditMenu ();
	printf(
				"%d) 商品折扣\n"
				, DISCOUNT);
	return ;
}

int NormalDrug::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+DISCOUNT){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void NormalDrug::judgeChoois(int choois){
	Commodity::judgeChoois (choois);
	switch (choois) {
		case DISCOUNT:
			cout<<"输入商品折扣: ";
			cin>>this->discount;
			break;
		default:
			break;
	}
	return ;
}
