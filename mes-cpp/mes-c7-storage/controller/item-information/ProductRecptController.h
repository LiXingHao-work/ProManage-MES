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
#ifndef _PRODUCT_RECPT_CONTROLLER_
#define _PRODUCT_RECPT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/item-information/ProductRecptQuery.h"
#include "domain/dto/item-information/ProductRecptDTO.h"
#include "domain/vo/item-information/ProductRecptVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �������������
 */
class ProductRecptController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//����������������
	API_ACCESS_DECLARE(ProductRecptController);
	//����ӿ�
public:
	// 1.1 �����ҳ��ѯ�ӿ�����,�ӿ���ΪqueryProductRecpt
	ENDPOINT_INFO(queryProductRecpt) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product-recpt.query.summary")); //��ҳ��ѯ��Ʒ�������
		//������Ҫ��Ȩ
		API_DEF_ADD_AUTH();
		//���������������
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductRecptPageJsonVO);
		//�����ҳ��ѯ����
		API_DEF_ADD_PAGE_PARAMS();
		//������������
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product_recpt.field.recpt_code"), "recpt_code", false);//��ⵥ���,�������Ϊ��
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_name", ZH_WORDS_GETTER("product_recpt.field.recpt_name"), "recpt_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("product_recpt.field.workorder_code"), "workorder_code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product_recpt.field.warehouse_name"), "warehouse_name", false);
	}
	//1.2�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ProductRecpt/query-ProductRecpt", queryProductRecpt, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪProductRecptQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductRecptQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProductRecpt(query));
	}

private:
	// 1.3 ��ҳ��ѯ��Ʒ���
	ProductRecptPageJsonVO::Wrapper execQueryProductRecpt(const ProductRecptQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_PRODUCT_RECPT_CONTROLLER_