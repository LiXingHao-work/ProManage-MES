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
#include "domain/query/ProduceWork/PworkQery.h"
#include "domain/dto/ProduceWork/PworkDTO.h"
#include "domain/vo/ProduceWork/ProduceVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������������
 */
class ProController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  2 ����������������
	API_ACCESS_DECLARE(ProController);
	//  3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(QueryPworkTable){
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ProduceWork.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ ��Ҫ����ͷ�ļ�
		API_DEF_ADD_RSP_JSON_WRAPPER(ProduceTableJsonVO);
		 // �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
			API_DEF_ADD_QUERY_PARAMS(String, "feedback_type", ZH_WORDS_GETTER("ProduceWork.fields.feedback_type"), "li ming", false);
			API_DEF_ADD_QUERY_PARAMS(String, "workstation_name", ZH_WORDS_GETTER("ProduceWork.fields.workstation_name"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("ProduceWork.fields.workorder_code"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("ProduceWork.fields.item_code"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "ite m_name", ZH_WORDS_GETTER("ProduceWork.fields.item_name"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "user_name", ZH_WORDS_GETTER("ProduceWork.fields.user_nam"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "record_user", ZH_WORDS_GETTER("ProduceWork.fields.record_user"), "N", false);
			API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("ProduceWork.fields.status"), "N", false);
       }
		// 3.2 �����ѯ�ӿڴ���
		ENDPOINT(API_M_GET, "/ProduceWork/query-Pwork-table", QueryPworkTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
		{
			// ������ѯ����ΪQuery����ģ��
			API_HANDLER_QUERY_PARAM(query, PworkQery, queryParams);
			// ����ִ�к�����Ӧ���
			API_HANDLER_RESP_VO(execPworkTable(query));
		}

private:// ����ӿ�ִ�к���
	// 3.3 ��ʾ��ҳ��ѯ����
	ProduceTableJsonVO::Wrapper execPworkTable(const PworkQery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_SAMPLE_CONTROLLER_