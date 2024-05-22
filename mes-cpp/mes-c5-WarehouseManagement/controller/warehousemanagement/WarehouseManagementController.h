#pragma once
#ifndef _WAREHOUSEMANAGEMENT_CONTROLLER_
#define _WAREHOUSEMANAGEMENT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehousemanagement/WarehouseManagementQuery.h"
#include "domain/dto/warehousemanagement/WarehouseManagementDTO.h"
#include "domain/vo/warehousemanagement/WarehouseManagementVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �������������ӿڵ�ʹ��
 */

class WarehouseManagementController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(WarehouseManagementController);
	// 3 ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWarehouseManagement) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehousemanagement.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WarehouseManagementPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("warehousemanagement.field.item_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("warehousemanagement.field.item_name"), "", false);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/warehousemanagement", queryWarehouseManagement, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(warehousemanagementQuery, WarehouseManagementQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryWarehouseManagement(warehousemanagementQuery, authObject->getPayload()));
	}


private:
	// ��ҳ��ѯ����
	WarehouseManagementPageJsonVO::Wrapper execQueryWarehouseManagement(const WarehouseManagementQuery::Wrapper& query, const PayloadDTO& payload);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WAREHOUSEMANAGEMENT_CONTROLLER_
