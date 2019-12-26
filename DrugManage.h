#ifndef DRUGMANAGE_H
#define DRUGMANAGE_H
#include "header.h"
#include <vector>


class DrugManage{
public:
	DrugManage()=default;
	~DrugManage();
	DrugManage(const DrugManage& c)=delete;
	DrugManage& operator=(const DrugManage& c)=delete;
	void addDrug(Drug* p);
	void addDrug(const Drug& p);
	void editDrug(std::string _name);
	void removeDrug(std::string _name);
	void viewDrug(std::string _name)const;
	void viewAllCommodities()const;
	void checkOut()const;
	void readData(std::string filename);
	void saveData(std::string filename);
	Drug* findDrugByName(std::string name);
	Drug* findDrugByName(std::string name) const;

private:
	std::vector<Drug*> pCommodities;
	Drug* findDrugById(int id);
	const Drug* findDrugById(int id)const;

	std::vector<Drug*>::iterator getIterator(Drug* p);
	int sortType=0; //记录当前排序类型
	void sortCommodities();
	void sortCommoditiesByType(int type);
	void printSortMenu(void) const;

	static const int SORT_BY_ID=0, SORT_BY_NAME=1, SORT_BY_TOTAL_PRICE=2,
	SORT_BY_NUM=3, SORT_BY_PRICE=4;
};

#endif // DRUGMANAGE_H
