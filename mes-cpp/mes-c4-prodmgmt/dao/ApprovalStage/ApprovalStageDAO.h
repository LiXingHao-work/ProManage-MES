#pragma once
#ifndef _APPROVALSTAGEDTO_DAO_
#define _APPROVALSTAGEDTO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ApprovalStage/ApprovalStageDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ApprovalStageDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const ApprovalStageDO& uObj);
};
#endif // !_APPROVALSTAGEDTO_DAO_

