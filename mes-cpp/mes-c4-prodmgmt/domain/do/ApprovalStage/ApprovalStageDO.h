#pragma once
#ifndef _APPROVALSTAGEDTO_DO_
#define _APPROVALSTAGEDTO_DO_
#include "../DoInclude.h"

/**
 * ��ȡ���������б����ݿ�ʵ����
 */
class ApprovalStageDO
{
	//��¼id/�����������;record_id;bigint
	CC_SYNTHESIZE(uint64_t, record_id, record_id);
	//����״̬;status;varchar
	CC_SYNTHESIZE(string, status, status);
public:
	ApprovalStageDO() {
		record_id = 0;
		status = "";
	}
};


#endif // !_GETPRODUCTIONREPORTLIST_DO_