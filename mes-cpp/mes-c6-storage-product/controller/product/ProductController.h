#pragma once
#ifndef _PRODUCTCONTROLLER_H_
#define _PRODUCTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/product/ProductVO.h"
#include "domain/dto/product/ProductDTO.h"
#include "domain/query/product/ProductQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ProductController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ProductController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProductTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductTableJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "pnum", ZH_WORDS_GETTER("product.fields.pnum"), "ISSUE20221115004", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pname", ZH_WORDS_GETTER("product.fields.pname"), "�ֽ��������", false);
		API_DEF_ADD_QUERY_PARAMS(String, "prname", ZH_WORDS_GETTER("product.fields.prname"), "ԭ�ϲ�", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pdate", ZH_WORDS_GETTER("product.fields.pdate"), "2022-11-15 00:00:00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pstatus", ZH_WORDS_GETTER("product.fields.pstatus"), "FINISHED", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/product/query-product-table", queryProductTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProductTable(query));
	}

private:
	// ��ѯ����
	ProductTableJsonVO::Wrapper execProductTable(const ProductQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif