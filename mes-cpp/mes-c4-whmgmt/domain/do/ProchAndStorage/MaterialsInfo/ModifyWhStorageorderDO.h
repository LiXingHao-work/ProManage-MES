#pragma once
#ifndef _MODIFYWHSTORAGEORDER_DO_
#define _MODIFYWHSTORAGEORDER_DO_
/*
�޸���ⵥ�е����ݿ�ʵ����
*/
#include "../../DoInclude.h"
class ModifyWhStorageorderDO
{
	//���ϱ��� item_code varchar
	CC_SYNTHESIZE(string, item_code, Item_code);
	//�������� item_name varchar
	CC_SYNTHESIZE(string, item_name, Item_name);
	//��λ unit_of_measure varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//������� quantity_recived double
	CC_SYNTHESIZE(double, quantity_recived, Quantity_recived);
	//������κ� batch_code varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//��Ч�� expire_date String
	CC_SYNTHESIZE(string, expire_date, Expire_date);
	//���ֿ� warehouse_name varchar
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//�Ƿ���� iqc_check char
	CC_SYNTHESIZE(string, iqc_check, Iqc_check);
	//���ϼ��鵥���� iqc_code varchar
	CC_SYNTHESIZE(string, iqc_code, Iqc_code);
	//���ϼ��鵥ID iqc_id bigint
	CC_SYNTHESIZE(uint64_t, iqc_id, Iqc_id);
	//��ע remark varchar
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ModifyWhStorageorderDO() {
		item_code = "";
		item_name = "";
		unit_of_measure = "";
		quantity_recived = 0.00;
		batch_code = "";
		expire_date = "";
		warehouse_name = "";
		iqc_check = "";
		iqc_code = "";
		iqc_id = 0;
		remark = "";
	}
};
#endif // !_MODIFYWHSTORAGEORDER_DO_
