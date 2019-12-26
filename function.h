#ifndef FUNCTION_H
#define FUNCTION_H

#include "drug.h"
#include "drugmanage.h"

char menu();
void doAddDrug(DrugManage& cm);
void doRemoveDrug(DrugManage& cm);
void doViewDrug(const DrugManage& cm);
void doViewAllDrug(const DrugManage& cm);
void doCheckout(const DrugManage& cm);
void doEditDrug(DrugManage& cm);

#endif // FUNCTION_H
