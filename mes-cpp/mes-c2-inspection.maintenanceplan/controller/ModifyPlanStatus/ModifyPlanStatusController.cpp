#include "ModifyPlanStatusController.h"
#include "stdafx.h"
#include "service/MaintenancePlanStatus/ModifyPlanStatusServer.h"

ModifyPlanStatusJsonVo::Wrapper ModifyPlanStatusController::execModifyPlanStatus(const ModifyPlanStatusDto::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = ModifyPlanStatusJsonVo::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0 )
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->status)
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ModifyPlanStatusService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}
	//��Ӧ���
	return jvo;
}
