#pragma once
#ifndef _MODIFYWHSTORAGEORDER_DO_
#define _MODIFYWHSTORAGEORDER_DO_
/*
�޸���ⵥ�е����ݿ�ʵ����
*/
#include "../../DoInclude.h"
class ModifyWhStorageorderDO
{
	////��ⵥ���� recpt_name varchar
	CC_SYNTHESIZE(string, recpt_name, Recpt_name);
	//��ⵥ��� recpt_code varchar
	CC_SYNTHESIZE(string, recpt_code, Recpt_code);
	//��Ӧ������ vendor_name varchar
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	//�ɹ������� po_code varchar
	CC_SYNTHESIZE(string, po_code, Po_code);
	//����״̬ status varchar
	CC_SYNTHESIZE(string, status, Status);
	//������� recpt_date String
	CC_SYNTHESIZE(string, recpt_date, Recpt_date);
	//���ֿ� warehouse_name varchar
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//��ע remark varchar
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ModifyWhStorageorderDO() {
		recpt_name = "";
		recpt_code = "";
		vendor_name = "";
		po_code = "";
		status = "";
		recpt_date = "";
		warehouse_name = "";
		remark = "";
	}
};
#endif // !_MODIFYWHSTORAGEORDER_DO_
