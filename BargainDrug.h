#ifndef BARGAINDRUG_H
#define BARGAINDRUG_H

#include "drug.h"

class BargainDrug : public Drug{
public:
	static const int SPECIALPRICE=3;

	virtual ~BargainDrug() =default;

	BargainDrug(long id,std::string name,double p=0,int nn=0, double sp=0);
	BargainDrug(std::string name,double p=0,int nn=0, double sp=0);

	double getSpecialPrice(void) const{
		return this->specialPrice;
	}

	void setSpecialPrice(double sp){
		this->specialPrice=sp;
		return ;
	}

	virtual double getPrice () const ;

	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const;
	virtual std::string getInfo()const;
	virtual void editInfo ();

	virtual void printEditMenu (void);
	virtual int getChoois (void);
	virtual void judgeChoois (int choois);

private:
	double specialPrice;
};

#endif // BARGAINDRUG_H
