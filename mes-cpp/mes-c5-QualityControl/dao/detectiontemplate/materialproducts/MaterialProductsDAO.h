#pragma once
#ifndef _MATERIALPRODUCTS_DAO_
#define _MATERIALPRODUCTS_DAO_

#include "BaseDAO.h"
#include "../../../domain/do/DetectionTemplate/MaterialProductsDO.h"
#include "../../../domain/query/detectiontemplate/materialproductsQuery.h"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/web/client/ApiClient.hpp>


class MaterialProductsDAO :public BaseDAO
{
public:

	// �޸�����
	int updateMaterialProducts(const MaterialProductsDO& uObj);
	// ��������
	uint64_t insertMaterialProducts(const MaterialProductsDO& iObj);
	// ɾ������
	int deleteByRecordId(const oatpp::List<oatpp::UInt64>& record_ids);

	
};

#endif // !_MATERIALPRODUCTS_DAO_