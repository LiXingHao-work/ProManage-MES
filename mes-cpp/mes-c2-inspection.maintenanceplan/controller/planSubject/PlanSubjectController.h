#pragma once
/*
* 
*/
#ifndef _DEPTCONTROLLER_H_
#define _DEPTCONTROLLER_H_

//#include "../../domin/vo/dept/DeptVO.h"
#include "../../domain/vo/dept/DeptVO.h"
#include "../../domain/query/dept/DeptQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ���Ź��� ������
 */
class DeptController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeptController);
	// 3 ����ӿ�
public:
	//������Զ���ܶ���Ľӿ�
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDeptTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dept.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DeptTableJsonVO);//ABF ��Ӧ��ʽ�����Ƕ�����Ǹ�VO
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();//û�з�ҳ���������

		// ����������ѯ��������������ABF ע�⣬����Ҫ����query������д
		API_DEF_ADD_QUERY_PARAMS(String, "deptName", ZH_WORDS_GETTER("dept.fields.dname"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("dept.fields.status"), 1, false);
	}
	// 3.2 �����ѯ�ӿڴ���                                  ��ѯ����                          ������Ȩ������
	ENDPOINT(API_M_GET, "/dept/query-dept-table", queryDeptTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, DeptQuery, queryParams);//������Deptquery
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDeptTable(query));//�ĳ�DeptTable��������һ������
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	DeptTableJsonVO::Wrapper execDeptTable(const DeptQuery::Wrapper& query);//����Ǹ������Ȳ�Ҫ
	//������Ҫдһ��cpp�ļ�����execDeptTable

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
