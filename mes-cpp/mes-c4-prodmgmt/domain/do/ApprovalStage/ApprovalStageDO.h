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
	CC_SYNTHESIZE(int, record_id, record_id);
	//��������;feedback_type;varchar
	CC_SYNTHESIZE(string, feedback_type, feedback_type);
public:
	ApprovalStageDO() {
		workorder_id = 0;
		feedback_type = "";
	}
};


#endif // !_GETPRODUCTIONREPORTLIST_DO_