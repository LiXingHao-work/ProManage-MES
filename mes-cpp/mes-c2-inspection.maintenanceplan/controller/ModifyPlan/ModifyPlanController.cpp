#include "ModifyPlanController.h"
#include "stdafx.h"
#include "service/MaintenancePlan/ModifyPlanServer.h"

MaintenancePlanJsonVo::Wrapper ModifyPlanController::execModifyPlan(const MaintenancePlanDto::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = MaintenancePlanJsonVo::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0 )
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->code || !dto->name || !dto->type || !dto->cyclecount || !dto->cycletype )
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ����һ��Service
	ModifyPlanService service;
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
