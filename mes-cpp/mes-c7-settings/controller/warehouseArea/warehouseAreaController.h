#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehouseArea/warehouseAreaQuery.h"
#include "domain/dto/warehouseArea/warehouseAreaDTO.h"
#include "domain/vo/warehouseArea/warehouseAreaVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �������������
 */
class warehouseAreaController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(warehouseAreaController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����:�ӿ���ΪqueryWarehouseArea
	ENDPOINT_INFO(queryWarehouseArea) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse-area.query.summary"));//"��ҳ��ѯ��������"
		// ����Ĭ����Ȩ���������ʽӿ���Ҫ�����֤,����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(warehouseAreaPageJsonVO);
		// �����ҳ��ѯ��������:�˵�֧�ַ�ҳ��ѯ-�ṩ��ҳ��������ı�׼����
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ�������� ע�⣡��query�ﶨ���������ͬ,����Ϊ�Ǳ������,�����չʾ��ȫ������
		API_DEF_ADD_QUERY_PARAMS(String, "warehouseAreaName", ZH_WORDS_GETTER("warehouse-area.field.name"),"default name",false);
	}
	// 3.2 �����ѯ�ӿڴ���:·�ɵ�URL/warehouseArea�ҵ�queryWarehouseArea�˵�,������ѯ����queryParams
	ENDPOINT(API_M_GET, "/warehouseArea", queryWarehouseArea, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪWarehouseAreaQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, WarehouseAreaQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryWarehouseArea(query, authObject->getPayload()));
	}

private:
	// 3.3 ��ҳ��ѯ����
	warehouseAreaPageJsonVO::Wrapper execQueryWarehouseArea(const WarehouseAreaQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_