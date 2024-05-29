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
	//��ҳ��ѯ
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProductTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductTableJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "issue_code", ZH_WORDS_GETTER("product.fields.issue_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "issue_name", ZH_WORDS_GETTER("product.fields.issue_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product.fields.warehouse_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "issue_date", ZH_WORDS_GETTER("product.fields.issue_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("product.fields.status"), "", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/product/query-product-table", queryProductTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProductTable(query, authObject->getPayload()));
	}
	//�����ѯ
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProductDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductDetailJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "issue_code", ZH_WORDS_GETTER("product.fields.issue_code"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/product/query-product-detail", queryProductDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProductDetail(query));
	}

private:
	// ��ѯ����
	ProductTableJsonVO::Wrapper execProductTable(const ProductQuery::Wrapper& query,const PayloadDTO& payload);
	ProductDetailJsonVO::Wrapper execProductDetail(const ProductQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif