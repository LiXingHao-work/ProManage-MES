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
#ifndef _FEEDBACKCONTROLLER_
#define _FEEDBACKCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/FeedBack/FeedBackQuery.h"
#include "domain/dto/FeedBack/FeedBackDTO.h"
#include "domain/vo/FeedBack/FeedBackVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*
* ����������
* 
*/

class FeedBackController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(FeedBackController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryFeedBackTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeedBackPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������Q
		API_DEF_ADD_QUERY_PARAMS(String, "feedbackType", ZH_WORDS_GETTER("prod.field.feedback_type"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workstationName", ZH_WORDS_GETTER("prod.field.workstation_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorderCode", ZH_WORDS_GETTER("prod.field.workorder_code"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "itemCode", ZH_WORDS_GETTER("prod.field.item_code"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "itemName", ZH_WORDS_GETTER("prod.field.item_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "specification", ZH_WORDS_GETTER("prod.field.specification"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "feedbackQuantity", ZH_WORDS_GETTER("prod.field.quantity_feedback"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "userName", ZH_WORDS_GETTER("prod.field.user_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feedbackTime", ZH_WORDS_GETTER("prod.field.feedback_time"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recordUser", ZH_WORDS_GETTER("prod.field.record_user"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("prod.field.status"), "N", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query-feedback-table", queryFeedBackTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, FeedBackQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFeedBack(query));
	}
	/*
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addSample) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/sample", addSample, BODY_DTO(SampleDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddSample(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifySample, BODY_DTO(SampleDTO::Wrapper, dto), execModifySample(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", removeSample, PATH(UInt64, id), execRemoveSample(id));

	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryOne) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-one.summary"), SampleJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sample/query-one", queryOne, QUERY(UInt64, id), execQueryOne(id, authObject->getPayload()));

	// 3.1 �����������ʽ������õĽӿ�2����
	ENDPOINT_INFO(queryAll) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-all.summary"), SamplePageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sample/query-all", queryAll, SampleQuery, execQueryAll(query, authObject->getPayload()));
	*/
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	FeedBackPageJsonVO::Wrapper execQueryFeedBack(const FeedBackQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _FEEDBACKCONTROLLER_