#include "stdafx.h"
#include "DeletePlanSubjectController.h"
//����ѯ������
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanMachiner(const DeleteMachinerDTO::Wrapper& dto)
{
	return BooleanJsonVO::Wrapper();
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanSubject(const DeleteSubjectDTO::Wrapper& dto)
{
	return BooleanJsonVO::Wrapper();
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlan(const DeletePlanDTO::Wrapper& dto)
{
	return {};
}

DeletePlanQueryJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanQuery(const DeletePlanQuery::Wrapper& query)
{
	int a = 0;
	Dv_check_planService service;
	// ��ѯ����
	DeletePlanQueryDTO::Wrapper result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DeletePlanQueryJsonVO::createShared();
	jvo->success(result);
	return jvo;

	//return DeletePlanQueryJsonVO::Wrapper();
	return {};
}




