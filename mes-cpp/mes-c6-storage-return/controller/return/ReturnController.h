#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _RETURNCONTROLLER_H_
#define _RETURNCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "../../domain/query/return/ReturnQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/return/ReturnVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReturnController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(ReturnController);
public:
	// �����ѯ���е�����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllReturn) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("return.query-all.summary"), ReturnPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", true);
	}
	// �����ѯ���е�����Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/return/query-all", queryAllReturn, ReturnQuery, executeQueryAll(query));

	// �����޸ĵ�����Ϣ�˵�����
	ENDPOINT_INFO(modifyReturn) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("return.modify-return.summary"), StringJsonVO::Wrapper);
		// �����޸Ĳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("return.field.age"), 100, false);
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("return.field.nickname"), "feifei", false);
		// ���������������ʽ������ѡ���ϴ��ļ�
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
	}
	// �����޸ĵ�����Ϣ�˵㴦��ע�⣺�˷�ʽֻ֧�ֵ��ļ��ϴ������Ҹ����ֶβ��Ǻܶ�ĳ���ʹ�ã�
	ENDPOINT(API_M_POST, "/return/modify-return", modifyReturn, BODY_STRING(String, fileBody), QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(dto, ReturnDTO, qps);
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(executeModifyReturn(fileBody, dto));
	}
private:
	// ��ѯ���е�����Ϣ
	ReturnPageJsonVO::Wrapper executeQueryAll(const ReturnQuery::Wrapper& returnQuery);
	// �޸ĵ�����Ϣ
	StringJsonVO::Wrapper executeModifyReturn(const String& fileBody, const ReturnDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RETURNCONTROLLER_H_