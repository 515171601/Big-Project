#ifndef NORMALDRUG_H
#define NORMALDRUG_H

#include "drug.h"

class NormalDrug : public Drug{
public:
	static const int DISCOUNT=3;

	virtual ~NormalDrug(){}

	NormalDrug(long id,std::string name,
					double p=0,int n=0,double d=0);
	NormalDrug(std::string name,double p=0,int n=0,double d=0);

	void setDiscount(double discount){this->discount=discount;}

	double getDiscount()const{return discount;}

	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const;
	virtual std::string getInfo()const;
	virtual void editInfo ();

	virtual void printEditMenu (void);
	virtual int getChoois (void);
	virtual void judgeChoois (int choois);

private:
	double discount;
};

#endif // NORMALDRUG_H
