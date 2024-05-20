#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTCONTROLLER_H_
#define _PLANSUBJECTCONTROLLER_H_

//#include "../../domin/vo/dept/DeptVO.h"
#include "../../domain/vo/planSubject/PlanSubjectVO.h"
#include "../../domain/query/planSubject/PlanSubjectQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ���Ź��� ������
 */
class PlanSubjectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PlanSubjectController);
	// 3 ����ӿ�
public:
	//������Զ���ܶ���Ľӿ�
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPlanSubjectTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryTable"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectTableJsonVO);//ABF ��Ӧ��ʽ�����Ƕ�����Ǹ�VO
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();//û�з�ҳ���������

		// ����������ѯ��������������ABF ע�⣬����Ҫ����query������д
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), 1, false);

	}
	// 3.2 �����ѯ�ӿڴ���                                  ��ѯ����                          ������Ȩ������
	ENDPOINT(API_M_GET, "/planSubject/query-panSubject-table", queryPlanSubjectTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, PlanSubjectQuery, queryParams);//������Deptquery
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPlanSubjectTable(query));//�ĳ�DeptTable��������һ������
	}

	ENDPOINT_INFO(queryPlanSubjectDetailPage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryDetailPage"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectTableJsonVO);//ABF ��Ӧ��ʽ�����Ƕ�����Ǹ�VO
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();//û�з�ҳ���������

		// ����������ѯ��������������ABF ע�⣬����Ҫ����query������д
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), 1, false);

	}
	// 3.2 �����ѯ�ӿڴ�����ҳ��                                  ��ѯ����                          ������Ȩ������
	ENDPOINT(API_M_GET, "/planSubject/query-panSubject-DetailPage", queryPlanSubjectDetailPage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, PlanSubjectQuery, queryParams);//������Deptquery
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPlanSubjectDetailPage(query));//�ĳ�DeptTable��������һ������
	}
	

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	PlanSubjectTableJsonVO::Wrapper execPlanSubjectTable(const PlanSubjectQuery::Wrapper& query);//����Ǹ������Ȳ�Ҫ
	//������Ҫдһ��cpp�ļ�����execDeptTable
	//PlanSubjectDetailPageJsonVO::Wrapper execQuerySample(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);

	PlanSubjectDetailPageJsonVO::Wrapper execPlanSubjectDetailPage(const PlanSubjectQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
