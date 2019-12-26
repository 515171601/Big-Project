#include <iostream>
#include "drug.h"
#include <sstream>

using namespace std;

long Drug::nextId=100;

Drug::Drug(string n,double p,int nu)
	:Drug(autoNextId(),n,p,nu){}

Drug::Drug(long i,std::string n,double p,int nu)
	:id(i),name(n),price(p),num(nu){}

double Drug::getNetPrice()const{
	return price*num;
}

void Drug::output()const{
	cout<<" 药品编号(id):"<<id<<endl;
	cout<<" 药品名称:"<<name<<endl;
}

string Drug::getInfo()const{
	ostringstream ostr;
	ostr<<getId()<<endl;
	ostr<<getName()<<endl;
	ostr<<price<<" "<<num<<" ";
	return ostr.str();
}

void Drug::printEditMenu()const{
	printf (
				"%d) 药品名称\n"
				"%d) 药品价格\n"
				"%d) 药品数量\n"
				,NAME, PRICE, NUM);
	return ;
}

int Drug::getChoois() const{
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+NUM){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void Drug::judgeChoois(int choois){
	switch(choois){
		case NAME:
			cout<<"输入药品名称: ";
			cin>>this->name;
			break;
		case PRICE:
			cout<<"输入药品价格: ";
			cin>>this->price;
			break;
		case NUM:
			cout<<"输入药品数量: ";
			cin>>this->num;
			break;
		default:
			break;
	}
	return ;
}

void Drug::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的药品如下: \n";
	this->output ();
	return ;
}


