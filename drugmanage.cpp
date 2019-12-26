#include <string>
#include <fstream>
#include <iostream>
#include "header.h"
#include <algorithm>


using namespace std;

DrugManage::~DrugManage(){
	for(auto e:pCommodities){
		delete e;
	}
}

void DrugManage::addDrug(Drug* p){
	Drug* pDrug=findDrugById(p->getId());
	if(pDrug!=nullptr){
		cout<<"编号为"<<p->getId()<<"的药品已经存在!累加其数量\n";
		pDrug->setNum(pDrug->getNum()+p->getNum());
		return;
	}
	pCommodities.push_back(p);
	sortCommodities(); //添加药品后根据当前规则重新排序
	return ;
}



void DrugManage::sortCommodities(){
	switch(sortType){
		case SORT_BY_ID: //根据 id 排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Drug* p1,Drug* p2){
				return p1->getId()<p2->getId();
			});
			break;
		case SORT_BY_NAME: //根据名称排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Drug* p1,Drug* p2){
				bool flag=0;
				if(p1->getName()==p2->getName()){
					flag=(p1->getId()<p2->getId());
				}else{
					flag=(p1->getName()<p2->getName());
				}
				return flag;
			});
			break;
		case SORT_BY_TOTAL_PRICE: //根据净价排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Drug* p1,Drug* p2){
				return p1->getNetPrice()<p2->getNetPrice();
			});
			break;
		case SORT_BY_PRICE:
			sort(pCommodities.begin (), pCommodities.end (),
				 [=](Drug* p1,Drug* p2){
				return p1->getPrice ()<p2->getPrice ();
			});
			break;
		case SORT_BY_NUM:
			sort(pCommodities.begin (), pCommodities.end (),
				 [=](Drug* p1,Drug* p2){
				return p1->getNum ()<p2->getNum ();
			});
			break;
		default:
			break;
	}
}

void DrugManage::sortCommoditiesByType(int type){
	if(type==sortType){ //已经按指定规则排序，直接返回
		return;
	}
	sortType=type;
	sortCommodities();
}

//todo: 添加菜单
void DrugManage::printSortMenu() const{
	printf(
				"指定排序方式: \n"
				"%d) 药品ID\n"
				"%d) 药品名称\n"
				"%d) 药品净价\n"
				"%d) 药品数量\n"
				"%d) 药品价格\n"
				"输入选择项: \n"
				, SORT_BY_ID, SORT_BY_NAME, SORT_BY_TOTAL_PRICE
				, SORT_BY_NUM, SORT_BY_PRICE);
	return ;
}

void DrugManage::editDrug(std::string _name){
	Drug *pDrug=findDrugByName (_name);
	if(pDrug==nullptr){
		cout<<"名称为"<<_name<<"的药品不存在!\n";
		return ;
	}
#ifdef	DEBUG
	pDrug->output ();
#endif
	cout<<"输入需要修改的药品信息项: \n";
	pDrug->editInfo ();
	return ;
}


void DrugManage::removeDrug(string _name){
	Drug *pDrug=findDrugByName (_name);
	if(pDrug==nullptr){
		cout<<"名称为"<<_name<<"的药品不存在!\n";
		return;
	}
	delete pDrug;
	pCommodities.erase(getIterator(pDrug));
}

void DrugManage::viewDrug(string _name)const{
	const Drug *pDrug=findDrugByName (_name);
	if(pDrug==nullptr){
		cout<<"名称为"<<_name<<"的药品不存在!\n";
		return;
	}
	pDrug->output();
}

void DrugManage::viewAllCommodities()const{
	cout<<"药品种类:"<< pCommodities.size()<<endl;
	if(pCommodities.size()==0)
		return;
	this->printSortMenu ();
	int type;
	cin>>type;
	while(getchar()!='\n');
	const_cast<DrugManage*>(this)->sortCommoditiesByType(type);
	for(auto e:pCommodities)
		e->output();
}

Drug* DrugManage::findDrugById(int id){
	vector<Drug*>::iterator it=
			find_if(pCommodities.begin(),pCommodities.end(),
					[=](Drug* p){
		return p->getId()==id;});
	if(it!=pCommodities.end()){
		return *it;
	}
	return nullptr;
}

const Drug* DrugManage::findDrugById(int id)const{
	vector<Drug*>::const_iterator it=
			find_if(pCommodities.begin(),pCommodities.end(),
					[=](const Drug* p){
		return p->getId()==id;});
	if(it!=pCommodities.end()){
		return *it;
	}
	return nullptr;
}

Drug *DrugManage::findDrugByName(string name){
	vector<Drug*>::const_iterator it=
			find_if(pCommodities.begin (), pCommodities.end (),
					[=](Drug* p){
		return p->getName ()==name;
	});
	if(it!=pCommodities.end ()){
		return *it;
	}
	return nullptr;
}

Drug *DrugManage::findDrugByName(string name) const{
	vector<Drug*>::const_iterator it=
			find_if(pCommodities.begin (), pCommodities.end (),
					[=](const Drug* p){
		return p->getName ()==name;
	});
	if(it!=pCommodities.end ()){
		return *it;
	}
	return nullptr;
}

vector<Drug*>::iterator DrugManage::getIterator(Drug* p){
	for(auto it=pCommodities.begin();it!=pCommodities.end();++it)
		if(*it==p){
			return it;
		}
	return pCommodities.end();
}

void DrugManage::checkOut()const{
	double totalPrice=0;
	int totalNum=0;
	cout<<"药品种类: "<< pCommodities.size()<<endl;
	cout<<" 药品名称\t\t"<<"价格\t"<<"件数\t"<<"总价\n";
	for(auto e : pCommodities){
		double price=e->getNetPrice();
		cout<<" "<<e->getName()<<"\t";
		cout<<e->getPrice()<<"\t"
		   <<e->getNum()<<"\t"
		  <<price<<endl;
		totalPrice+=price;
		totalNum+=e->getNum();
	}
	cout<<"购物篮药品总件数: "<<totalNum<<"\n";
	cout<<"购物篮结算总价: "<<totalPrice<<endl;
}

void DrugManage::saveData(string filename){
	ofstream out(filename);
	if(out){
		out<< pCommodities.size()<<endl;
		out<<Drug::getNextId()<<endl;
		for(auto e : pCommodities){
			out<<e->getInfo();
		}
	}
#ifdef DEBUG
	cerr<<"保存完成\n";
#endif
}


void DrugManage::readData(string filename) {
	ifstream in(filename);
	if(in) {
		int fileSize;
		long nextId;
		in>>fileSize>>nextId;
		Drug::setNextId(nextId);
		int type;
		long id;
		string name,buf;
		double price,discount;
		double tariff;
		int num;
		for(int i=0; i<fileSize; ++i) {
			in>>type;
			in>>id;
			getline(in,buf);
			getline(in,name);
			in>>price>>num;
			switch(type) {
				case NORMAL:
					in>>discount;
					addDrug(new
								 NormalDrug(id,name,price,num,discount));
					break;
				case IMPORT:
					in>>discount>>tariff;
					addDrug(new
								 ImportDrug(id,name,price,num,discount,tariff));
					break;
				case BARGAIN:
					double specialPrice;
					in>>specialPrice;
					addDrug (new BargainDrug
								  (id,name, price, num, specialPrice));
					break;
				default:
					break;
			}
		}
	}
	sortCommodities();
	return ;
}
