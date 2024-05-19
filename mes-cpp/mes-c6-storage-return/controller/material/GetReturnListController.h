#pragma once
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
#ifndef _GETRETURNLISTCONTROLLER_H_
#define _GETRETURNLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/material/GetReturnListQuery.h"
#include "domain/dto/material/GetReturnListDTO.h"
#include "domain/vo/material/GetReturnListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ��Ӧ���˻����б��������
 */
class GetReturnListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetReturnListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(returnlist) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("material.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetReturnListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "rtcode", ZH_WORDS_GETTER("material.rtcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rtname", ZH_WORDS_GETTER("material.rtname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pocode", ZH_WORDS_GETTER("material.pocode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorname", ZH_WORDS_GETTER("material.vendorname"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/get/returnlist", returnlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, GetReturnListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryList(Query));
	}

	
private:
	GetReturnListPageJsonVO::Wrapper execQueryList(const GetReturnListQuery::Wrapper& query);
	// 3.3 ��ʾ��ҳ��ѯ����
	//SamplePageJsonVO::Wrapper execQuerySample(const SampleQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	//Uint64JsonVO::Wrapper execAddSample(const SampleDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	//Uint64JsonVO::Wrapper execRemoveSample(const UInt64& id);
	// 3.3 ��������ʽ�������1
	//SampleJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 ��������ʽ�������2
	//SamplePageJsonVO::Wrapper execQueryAll(const SampleQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GETRETURNLISTCONTROLLER_H_