#include <iostream>
#include "header.h"

using namespace std;

char menu(){
	cout<<" 0) 退出系统\n";
	cout<<" 1) 向购物篮添加药品\n";
	cout<<" 2) 从购物篮移除药品\n";
	cout<<" 3) 修改指定的药品\n";
	cout<<" 4) 查看指定药品\n";
	cout<<" 5) 查看所有药品\n";
	cout<<" 6) 结算\n";
	cout<<"请输入功能选项:";
	char choice;
	cin>>choice;
	return choice;
}

void doEditDrug(DrugManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.editDrug (name);
	return ;
}

void doRemoveDrug(DrugManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.removeDrug(name);
}

void doViewDrug(const DrugManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.viewDrug(name);
}

void doViewAllDrug(const DrugManage& cm){
	cm.viewAllCommodities();
}

void doCheckout(const DrugManage& cm){
	cm.checkOut();
}

char DrugClassificationMenu(void){
	printf(
				"选择药品类型:\n"
				"%d) 普通药品\n"
				"%d) 进口药品\n"
				"%d) 特价药品\n"
				,NORMAL, IMPORT, BARGAIN);
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');			//清空缓冲区
	while(choois<'0'||choois>BARGAIN+'0'){
		cout<<"无效输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');		//清空缓冲区
	}
	return choois;
}

void doAddDrug(DrugManage& cm){
	string name;
	double price,discount;
	double tariff;
	int num;
	char choois=DrugClassificationMenu ();
	cout<<"输入药品名称:";
	getline(cin,name);
	Drug* pDrug=cm.findDrugByName (name);
	if(pDrug!=nullptr){
		cout<<"名称为"<<name<<"的药品已经存在\n";
		cout<<"输入添加的数量: ";
		int newNum=0;
		cin>>newNum;
		pDrug->setNum (newNum);
	}else{
		cout<<"输入价格和药品数量:";
		cin>>price>>num;
		switch(choois){
			case '0'+NORMAL:
				cout<<"输入药品折扣:";
				cin>>discount;
				cm.addDrug(new
								NormalDrug(name,price,num,discount));
				break;
			case '0'+IMPORT:
				cout<<"输入药品折扣和关税:";
				cin>>discount>>tariff;
				cm.addDrug(new
								ImportDrug(name,price,num,discount,tariff));
				break;
			case '0'+BARGAIN:
				cout<<"输入药品特价: ";
				double specialPrice;
				cin>>specialPrice;
				cm.addDrug (new BargainDrug
								 (name, price, num, specialPrice));
				break;
			default:
				break;
		}
	}
	return ;
}
