#pragma once
#ifndef _APPROVALSTAGEDTO_SERVICE_
#define _APPROVALSTAGEDTO_SERVICE_
#include <list>
#include "domain/vo/ApprovalStage/ApprovalStageVO.h"
#include "domain/dto/ApprovalStage/ApprovalStageDTO.h"

/**
	�޸�����״̬����ʵ��
 */
class ApprovalStageService
{
public:
	// �޸�����
	bool updateData(const ApprovalStageDTO::Wrapper& dto);
};

#endif // !_APPROVALSTAGEDTO_SERVICE_


