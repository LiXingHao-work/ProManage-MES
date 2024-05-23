#pragma once
#ifndef _INSPECT_DO_
#define _INSPECT_DO_
#include "../DoInclude.h"

/**
 * ���ϼ����б����ݿ�ʵ����
 */
class InspectDO
{
	// ���ݿ����id
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	// ���ϼ��鵥���
	CC_SYNTHESIZE(string, code, Code);
	// ���ϼ��鵥����
	CC_SYNTHESIZE(string, name, Name);
	//����ģ��ID
	CC_SYNTHESIZE(uint64_t, template_id, Template_id);
	//��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, vendor_id, Vendor_id);
	//��Ӧ�̱���
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	//��Ӧ������
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vd_nick, Vd_nick);
	//��Ӧ�����κ�
	CC_SYNTHESIZE(string, vd_batch, Vd_batch);
	//��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_code);
	//��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_name);
	//��������
	CC_SYNTHESIZE(long long, quantity_recived, Quantity_recived);
	//�������
	CC_SYNTHESIZE(long long, quantity_check, Quantity_check);
	//���ϸ���
	CC_SYNTHESIZE(long long, quantity_unqualified, Quantity_unqualified);
	//�����
	CC_SYNTHESIZE(string, check_result, Check_result);
	//��������
	CC_SYNTHESIZE(string, recive_date, Recive_date);
	//�������
	CC_SYNTHESIZE(string, inspect_date, Inspect_date);
	//�����Ա
	CC_SYNTHESIZE(string, inspector, Inspector);
	//����״̬
	CC_SYNTHESIZE(string, list_status, List_status);

public:
	InspectDO() {
		line_id = 0;
		code = "";
		name = "";
		template_id = 0;
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		vd_nick = "";
		vd_batch = "";
		item_code = "";
		item_name = "";
		quantity_recived = 0;
		quantity_check = 0;
		quantity_unqualified = 0;
		check_result = "";
		recive_date = "";
		inspect_date = "";
		inspector = "";
		list_status = "";
	}
};


/**
 * ���ϼ����������ݿ�ʵ����
 */
class Inspect_detailDO :public InspectDO
{
	//��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//����ȱ����
	CC_SYNTHESIZE(double, maj_rate, Maj_rate);
	//����ȱ����
	CC_SYNTHESIZE(double, cr_rate, Cr_rate);
	//��΢ȱ����
	CC_SYNTHESIZE(double, min_rate, Min_rate);
	//����ȱ������
	CC_SYNTHESIZE(long long, cr_quantity, Cr_quantity);
	//����ȱ������
	CC_SYNTHESIZE(long long, maj_quantity, Maj_quantity);
	//��΢ȱ������
	CC_SYNTHESIZE(long long, min_quantity, Min_quantity);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	InspectDO() {
		unit_of_measure = "";
		maj_rate = 0;
		cr_rate = 0;
		min_rate = 0;
		cr_quantity = 0;
		maj_quantity = 0;
		min_quantity = 0;
		remark = "";
	}
};

class Inspect_tableDO :public Inspect_detailDO
{

};

#endif // !_INSPECT_DO_
