#pragma once
#ifndef _GETPRODUCTIONREPORTLIST_DO_
#define _GETPRODUCTIONREPORTLIST_DO_
#include "../DoInclude.h"

/**
 * ��ȡ���������б����ݿ�ʵ����
 */
class GetProductionReportListDO
{
	//��������;feedback_type;varchar
	CC_SYNTHESIZE(string, feedback_type, feedback_type);
public:
	GetProductionReportListDO() {
		//0�ݸ壬1��������2����ͨ����3������ͨ��
		feedback_type = "0";
	}
};


#endif // !_GETPRODUCTIONREPORTLIST_DO_