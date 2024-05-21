#pragma once
#ifndef _GETPRODWORKORDERLIST_DO_
#define _GETPRODWORKORDERLIST_DO_
#include "../DoInclude.h"

/**
 * ��ȡ���������б����ݿ�ʵ����
 */
class GetProdWorkorderListDO
{
	//����ID;workorder_id;bigint
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//��������;workorder_code;varchar
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//��������;workorder_name;varchar
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	//��Դ����;source_code;varchar
	CC_SYNTHESIZE(string, source_code, Source_code);
	//��Ʒ���;product_code;varchar
	CC_SYNTHESIZE(string, product_code, Product_code);
	//��Ʒ����;product_name;varchar
	CC_SYNTHESIZE(string, product_name, Product_name);
	//�ͻ�����;client_code;varchar
	CC_SYNTHESIZE(string, client_code, Client_code);
	//�ͻ�����;client_name;varchar
	CC_SYNTHESIZE(string, client_name, Client_name);
	//��������;workorder_type;varchar
	CC_SYNTHESIZE(string, workorder_type, Workorder_type);
	//��������;request_date;datetime
	CC_SYNTHESIZE(string, request_date, Request_date);

public:
	GetProdWorkorderListDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		source_code = "";
		product_code = "";
		product_name = "";
		client_code = "";
		client_name = "";
		workorder_type = "";
		request_date = "";	
	}
};
 

#endif // !_GETPRODWORKORDERLIST_DO_