#include "stdafx.h"
#include "MachineryPlanQueryController.h"
#include "../../service/query-ForeverOMC/MachineryPlanService.h"

MachineryListPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryList(const MachineryListQuery::Wrapper& query)
{
	return {};
}

MachineryPlanPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query)
{
	// ����һ��Service
	MachineryPlanService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MachineryPlanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachineryPlanDetailsJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query)
{
	// ����һ��Service
	MachineryPlanService service;
	// ��ѯ����
	auto result = service.getDetails(query);
	// ��Ӧ���
	auto jvo = MachineryPlanDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachinerySubjectPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query)
{
	return {};
}