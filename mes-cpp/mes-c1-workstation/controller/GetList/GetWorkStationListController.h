#pragma once

#ifndef _GETWORKSTATIONLIST_CONTROLLER_H_
#define _GETWORKSTATIONLIST_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/GetList/GetWorkStationListQuery.h"
#include "domain/dto/GetList/GetWorkStationListDTO.h"
#include "domain/dto/GetList/RemoveWorkStationDTO.h"
#include "domain/vo/GetList/GetWorkStationListVO.h"
#include "domain/vo/GetList/RemoveWorkStationVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetWorkStationListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetWorkStationListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkStationList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getlist.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetWorkStationListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//����վ����
		API_DEF_ADD_QUERY_PARAMS(String, "workstationCode", ZH_WORDS_GETTER("getlist.fields.workstationCode"), "WS0124", false);
		//����վ����
		API_DEF_ADD_QUERY_PARAMS(String, "workstationName", ZH_WORDS_GETTER("getlist.fields.workstationName"), "zhusu", false);
		//���ڳ�������
		API_DEF_ADD_QUERY_PARAMS(String, "workshopName", ZH_WORDS_GETTER("getlist.fields.workshopName"), "car", false);
		//��������(��������)
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("getlist.fields.processName"), "QCC", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/query-ws-list", queryWorkStationList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, GetWorkStationListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execWorkStationList(query));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeWorkStation) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("getlist.delete.summary"), oatpp::List<UInt64>);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(List<UInt64>, "workstationId", ZH_WORDS_GETTER("getlist.fields.workstationId"), {1}, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/remove-ws", removeWorkStation, BODY_DTO(oatpp::List<UInt64>, workstationId), execRemoveWorkStation(workstationId));

private:
	// 3.3 ��ҳ��ѯ����
	GetWorkStationListPageJsonVO::Wrapper execWorkStationList(const GetWorkStationListQuery::Wrapper& query);
	// 3.3 ��ʾɾ������
	oatpp::List<UInt64> execRemoveWorkStation(const List<UInt64>& workstationId);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_