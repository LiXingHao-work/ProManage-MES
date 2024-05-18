#pragma once
#ifndef _DEPTCONTROLLER_H_
#define _DEPTCONTROLLER_H_


#include "domain/vo/dept/DeptVO.h"
#include "domain/query/dept/DeptQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class DeptController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(DeptController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDeptTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dept.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DeptTableJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "deptName", ZH_WORDS_GETTER("dept.fields.dname"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("dept.fields.dstatus"), 0, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/dept/query-dept-table", queryDeptTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, DeptQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDeptTable(query));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	DeptTableJsonVO::Wrapper execDeptTable(const DeptQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif