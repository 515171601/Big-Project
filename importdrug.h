#ifndef IMPORTDRUG_H
#define IMPORTDRUG_H

class ImportDrug : public Commodity{
public:
	static const int DISCOUNT=3, TARIFF=4;
	virtual ~ImportDrug(){}

	ImportDrug(long id,std::string name,
					 double p=0,int n=0,double d=1.0,double t=0);
	ImportDrug(std::string name,double p=0,
					 int n=0,double d=1.0,double t=0);

	void setDiscount(double discount){this->discount=discount;}
	void setTariff(double tariff){this->tariff=tariff;}

	double getDiscount()const{return discount;}
	double getTariff()const{return tariff;}

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
	double tariff;
};

#endif // IMPORTDRUG_H
