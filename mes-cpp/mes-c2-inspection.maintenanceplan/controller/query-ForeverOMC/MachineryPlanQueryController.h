#ifndef _MACHINERY_LIST_CONTROLLER_
#define _MACHINERY_LIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/query-ForeverOMC/MachineryListQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryListDTO.h"
#include "domain/vo/query-ForeverOMC/MachineryListVO.h"

#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"
#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"

#include "domain/query/query-ForeverOMC/MachinerySubjectQuery.h"
#include "domain/dto/query-ForeverOMC/MachinerySubjectDTO.h"
#include "domain/vo/query-ForeverOMC/MachinerySubjectVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
* �豸�嵥������
*/
class MachineryPlanQueryController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(MachineryPlanQueryController);

public:
	// �����ѯ�豸�嵥�б�ӿ�����
	ENDPOINT_INFO(queryMachineryList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-list.query.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// �����ѯ�豸�嵥�б�ӿڴ���
	ENDPOINT(API_M_GET, "/inspection-maintenanceplan/machinery-list", queryMachineryList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ��������ģ��
		API_HANDLER_QUERY_PARAM(querymachinerylist, MachineryListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMachineryList(querymachinerylist));
	}

	// ������/�����豸�ƻ��б�ӿ�����
	ENDPOINT_INFO(queryMachineryPlan) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryPlanPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "plan_code", ZH_WORDS_GETTER("machinery-plan.field.plan-code"), "PLAN2022048", false);
		API_DEF_ADD_QUERY_PARAMS(String, "plan_name", ZH_WORDS_GETTER("machinery-plan.field.plan-name"), "NAME", false);
		API_DEF_ADD_QUERY_PARAMS(String, "plan_type", ZH_WORDS_GETTER("machinery-plan.field.plan-type"), "CHECK / MAINTEN", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("machinery-plan.field.status"), "PREPARE / FINISHED", false);
	}

	// �����ѯ�豸�嵥�б�ӿڴ���
	ENDPOINT(API_M_GET, "/inspection-maintenanceplan/machinery-plan", queryMachineryPlan, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ��������ģ��
		API_HANDLER_QUERY_PARAM(querymachineryplan, MachineryPlanQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMachineryPlan(querymachineryplan));
	}

	// ������/�����豸�ƻ��б�ӿ�����
	ENDPOINT_INFO(queryMachineryPlanDetails) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query-details.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryPlanDetailsJsonVO);
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), "207", true);
	}
	// �����ѯ�豸�嵥�б�ӿڴ���
	ENDPOINT(API_M_GET, "/inspection-maintenanceplan/machinery-plan-details", queryMachineryPlanDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ��������ģ��
		API_HANDLER_QUERY_PARAM(querymachineryplandetails, MachineryPlanDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMachineryPlanDetails(querymachineryplandetails));
	}

	// �����ѯ���/������Ŀ�б�ӿ�����
	ENDPOINT_INFO(queryMachinerySubject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-subject.query.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MachinerySubjectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// �����ѯ���/������Ŀ�б�ӿڴ���
	ENDPOINT(API_M_GET, "/inspection-maintenanceplan/machinery-subject", queryMachinerySubject, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ��������ģ��
		API_HANDLER_QUERY_PARAM(querymachinerysubject, MachinerySubjectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMachinerySubject(querymachinerysubject));
	}

private:
	// ��ҳ��ѯ�豸�嵥�б�����
	MachineryListPageJsonVO::Wrapper execQueryMachineryList(const MachineryListQuery::Wrapper& query);

	// ��ҳ��ѯ���/�����ƻ��б����� 
	MachineryPlanPageJsonVO::Wrapper execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query);

	// ��ѯ���/�����ƻ���ϸ��Ϣ
	MachineryPlanDetailsJsonVO::Wrapper execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query);

	// ��ҳ��ѯ���/������Ŀ�б�����
	MachinerySubjectPageJsonVO::Wrapper execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MACHINERY_LIST_CONTROLLER_
