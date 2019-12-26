#ifndef DRUG_H
#define DRUG_H

#include <string>

class Drug{

public:
	static const int NAME=0, PRICE=1, NUM=2;

	virtual ~Drug() =default;

	Drug()=default;
	Drug(long i,std::string n,double p,int nn);
	Drug(std::string n,double p,int nn);

	void setPrice(double price){this->price=price;}
	void setNum(int num){this->num=num;}
	void setName(std::string name){this->name=name;}

	std::string getName()const{return name;}
	virtual double getPrice()const{return price;}
	int getNum()const{return num;}
	double getId()const{return id;}

	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const=0; //纯虚函数
	virtual std::string getInfo()const;

	virtual void printEditMenu(void) const;
	virtual int getChoois(void)const;
	virtual void judgeChoois(int choois);
	virtual void editInfo(void);

	static void setNextId(long id){nextId=id;}
	static long getNextId(){return nextId;}


private:
	long autoNextId(){return nextId++;}

	long id;
	std::string name;
	double price;	//商品价格
	int num;		//购买数量
	static long nextId;
};


#endif // DRUG_H
