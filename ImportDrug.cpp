#include <iostream>
#include "header.h"
#include <sstream>

using namespace std;

ImportDrug::ImportDrug(long id,std::string name,
								   double p,int n,double d,double t)
	:Drug(id,name,p,n),discount(d),tariff(t){}

ImportDrug::ImportDrug(std::string name,double p,
								   int n,double d,double t)
	:Drug(name,p,n),discount(d),tariff(t){}

double ImportDrug::getNetPrice()const{
	return Drug::getNetPrice()*discount+tariff;
}

void ImportDrug::output()const{
	Drug::output();
	cout<<" 药品总价:"<<getNetPrice()<<" (价格:"
	   <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
	  <<discount<<", 关税:"<<tariff<<" )\n";
}


int ImportDrug::getType()const{
	return IMPORT; //1 表示进口药品
}

string ImportDrug::getInfo()const{
	ostringstream ostr;
	ostr<<getType()<<" "; //先输出类型编码
	ostr<<Drug::getInfo(); //输出基类的信息
	ostr<<discount<<" "<<tariff<<endl; //输出子类信息
	return ostr.str();
}

void ImportDrug::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的药品如下: \n";
	this->output ();
	return ;
}

void ImportDrug::printEditMenu(){
	Drug::printEditMenu ();
	printf(
				"%d) 药品折扣\n"
				"%d) 药品关税\n"
				, DISCOUNT, TARIFF);
	return ;
}

int ImportDrug::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+TARIFF){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void ImportDrug::judgeChoois(int choois){
	Drug::judgeChoois (choois);
	switch (choois) {
		case DISCOUNT:
			cout<<"输入药品折扣: ";
			cin>>this->discount;
			break;
		case TARIFF:
			cout<<"输入药品关税: ";
			cin>>this->tariff;
			break;
		default:
			break;
	}
	return ;
}

