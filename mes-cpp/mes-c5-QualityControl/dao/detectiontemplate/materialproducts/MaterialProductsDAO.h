#pragma once
#ifndef _MATERIALPRODUCTS_DAO_
#define _MATERIALPRODUCTS_DAO_

#include "BaseDAO.h"
#include "../../../domain/do/DetectionTemplate/MaterialProductsDO.h"
#include "../../../domain/query/detectiontemplate/materialproductsQuery.h"

class MaterialProductsDAO :public BaseDAO
{
public:

	// �޸�����
	int updateMaterialProducts(const MaterialProductsDO& uObj);
	// ��������
	uint64_t insertMaterialProducts(const MaterialProductsDO& iObj);
	// ɾ������
	int deleteByRecordId(uint64_t templateId);
};

#endif // !_MATERIALPRODUCTS_DAO_