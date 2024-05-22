#pragma once

#ifndef _EXPORTWORKSTATIONLIST_CONTROLLER_H_
#define _EXPORTWORKSTATIONLIST_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/WorkStation/ExportWorkStationQuery .h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ExportWorkStationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExportWorkStationController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(exportWorkStation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.export.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//����վ����
		API_DEF_ADD_QUERY_PARAMS(String, "workstationCode", ZH_WORDS_GETTER("workstation.fields.workstationCode"), "WS0124", false);
		//����վ����
		API_DEF_ADD_QUERY_PARAMS(String, "workstationName", ZH_WORDS_GETTER("workstation.fields.workstationName"), "zhusu", false);
		//���ڳ�������
		API_DEF_ADD_QUERY_PARAMS(String, "workshopName", ZH_WORDS_GETTER("workstation.fields.workshopName"), "car", false);
		//��������(��������)
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("workstation.fields.processName"), "QCC", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/export-ws", exportWorkStation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ExportWorkStationQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execWorkStation(query));
	}

private:
	// ��������վ
	StringJsonVO::Wrapper execWorkStation(const ExportWorkStationQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_