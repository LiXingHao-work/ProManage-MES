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
#ifndef _PRODORDER_CONTROLLER_
#define _PRODORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ProdOrder/ProdOrderQuery.h"
#include "domain/dto/ProdOrder/ProdOrderDTO.h"
#include "domain/vo/ProdOrder/ProdOrderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���������ѯ�������������ӿڵ�ʹ��
 */
class ProdOrderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProdOrderController);

	// 3 ����ӿ�

public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProdOrder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdOrderPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "task_name", ZH_WORDS_GETTER("prod.field.taskName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workstation_name", ZH_WORDS_GETTER("prod.field.workstationName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "process_name", ZH_WORDS_GETTER("prod.field.processName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("prod.field.startTime"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("prod.field.endTime"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/prodOrder/query", queryProdOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProdOrderQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProdOrder(userQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addProdOrder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ProdOrder/add", addProdOrder, BODY_DTO(ProdOrderDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProdOrder(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("prod.put.summary"), modifyProdOrder, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ProdOrder/put", modifyProdOrder, BODY_DTO(ProdOrderDTO::Wrapper, dto), execModifyProdOrder(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeProdOrder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.task_name"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ProdOrder/del", removeProdOrder, PATH(UInt64, id), execRemoveProdOrder(id));

	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryOne) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod.query-one.summary"), ProdOrderJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.task_name"), 1, true);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/ProdOrder/query-one", queryOne, QUERY(UInt64, id), execQueryOne(id, authObject->getPayload()));

	// 3.1 �����������ʽ������õĽӿ�2����
	ENDPOINT_INFO(queryAll) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod.query-all.summary"), ProdOrderPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("prod.field.task_name"), "li ming", false);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/ProdOrder/query-all", queryAll, ProdOrderQuery, execQueryAll(query, authObject->getPayload()));

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ProdOrderPageJsonVO::Wrapper execQueryProdOrder(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddProdOrder(const ProdOrderDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProdOrder(const ProdOrderDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveProdOrder(const UInt64& id);
	// 3.3 ��������ʽ�������1
	ProdOrderJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 ��������ʽ�������2
	ProdOrderPageJsonVO::Wrapper execQueryAll(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRODORDER_CONTROLLER_