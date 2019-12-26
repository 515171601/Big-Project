#include "header.h"
#include <iostream>
#include <sstream>

using namespace std;

BargainDrug::BargainDrug
(long id, std::string name, double p, int nn, double sp):
	Drug(id,name, p, nn), specialPrice(sp) {}

BargainDrug::BargainDrug
(std::string name, double p, int nn, double sp):
	Drug(name, p, nn), specialPrice(sp) {}

double BargainDrug::getPrice() const{
	return this->specialPrice;
}

double BargainDrug::getNetPrice() const{
	return this->specialPrice*getNum ();
}

void BargainDrug::output() const{
	Drug::output ();
	cout<<" 药品总价:"<<getNetPrice()<<" (特价:"
	   <<getSpecialPrice ()<<", 数量:"<<getNum()<<" )\n";
	return ;
}

int BargainDrug::getType() const{
	return BARGAIN;
}

std::string BargainDrug::getInfo() const{
	ostringstream ostr;
	ostr<<BargainDrug::getType ()<<" "; //先输出类型编码
	ostr<<Drug::getInfo (); //输出基类的信息
	ostr<<this->specialPrice<<endl; //输出子类信息
	return ostr.str();
}

void BargainDrug::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的药品如下: \n";
	this->output ();
	return ;
}

void BargainDrug::printEditMenu(){
	Drug::printEditMenu ();
	printf(
				"%d) 药品特价\n"
				,SPECIALPRICE);
	return ;
}

int BargainDrug::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+SPECIALPRICE){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void BargainDrug::judgeChoois(int choois){
	Drug::judgeChoois (choois);
	switch (choois) {
		case SPECIALPRICE:
			cout<<"输入药品特价: ";
			cin>>this->specialPrice;
			break;
		default:
			break;
	}
	return ;
}





