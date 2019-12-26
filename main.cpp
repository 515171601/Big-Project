#include <iostream>
#include "header.h"

using namespace std;

int main(){
	//todo: 本部分先跳过密码输入的环节
		cout<<"欢迎使用药品管理系统!\n";
		char choice;
		DrugManage cm;
		cm.readData("d:\\DrugSys.data");
		while(true){
			choice=menu();
			if(choice=='0')
				break;
			switch(choice){
				case '1':
					doAddDrug(cm);
					break;
				case '2':
					doRemoveDrug(cm);
					break;
				case '3':
					doEditDrug(cm);
					break;
				case '4':
					doViewDrug(cm);
					break;
				case '5':
					doViewAllDrug(cm);
					break;
				case '6':
					doCheckout(cm);
					break;
				default:
					cout<<"无效输入! 请重试!\n";
					break;
			}
		}
		cm.saveData("d:\\DrugSys.data");
		cout<<"再见!\n";
		return 0;
}
