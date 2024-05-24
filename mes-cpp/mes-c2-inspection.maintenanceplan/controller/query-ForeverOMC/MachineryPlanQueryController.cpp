#include "stdafx.h"
#include "MachineryPlanQueryController.h"
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"

MachineryListPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryList(const MachineryListQuery::Wrapper& query)
{
	MachineryListPageDTO::Wrapper a;
	auto jvo = MachineryListPageJsonVO::createShared();
	jvo -> success(a);
	return jvo;
}

MachineryPlanPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query)
{
	//return {};
	//������ԭ�����ݣ���ʱע�ͣ�������abf�Ĳ���
	// ����һ��Service
	int a = 0;
	Dv_check_planService service;
	// ��ѯ����
	MachineryPlanPageDTO::Wrapper result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MachineryPlanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return {};
}

MachineryPlanDetailsJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query)
{
	return {};
}

MachinerySubjectPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query)
{
	return {};
}