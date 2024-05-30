#include "stdafx.h"
#include "ProductController.h"
#include "../../service/product/ProductService.h"
#include "../ApiDeclarativeServicesHelper.h"
ProductTableJsonVO::Wrapper ProductController::execProductTable(const ProductQuery::Wrapper& query,const PayloadDTO& payload)
{
	// ����һ��Service
	ProductTableService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProductTableJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
ProductDetailJsonVO::Wrapper ProductController::execProductDetail(const string& issue_code)
{
	// ����һ��Service
	ProductDetailService service;
	// ��ѯ����
	auto result = service.listONE(issue_code);
	// ��Ӧ���
	auto jvo = ProductDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
