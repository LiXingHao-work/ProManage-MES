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
#ifndef _HUMANRESOURCELISTCONTROLLER_
#define _HUMANRESOURCELISTCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/humanresource/HumanResourceListQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "domain/vo/humanresource/HumanResourceListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ������Դ������
 */
class HumanResourceListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(HumanResourceListController);
	// 3 ����ӿ�
public:


	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryHumanResource) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(HumanResourceListPageVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "postName", ZH_WORDS_GETTER("post.fields.pname"), "ceo", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "quantity", ZH_WORDS_GETTER("post.fields.quantiy"), 0, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/huamnresource/query-humanresource-list", queryHumanResource, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query,HumanResourceListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryHumanResourceList(query));
	}


	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addHumanResource) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/humanresource/add-hunmanresource-list", addHumanResource, BODY_DTO(HumanResourceListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddHumanResourceList(dto));
	}


private:
	// 3.3 ��ʾ��ҳ��ѯ����
	HumanResourceListPageVO::Wrapper execQueryHumanResourceList(const HumanResourceListQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddHumanResourceList(const HumanResourceListDTO::Wrapper& dto);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_