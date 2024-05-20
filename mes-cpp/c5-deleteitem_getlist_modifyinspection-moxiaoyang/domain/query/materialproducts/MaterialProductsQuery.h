#pragma once
#ifndef _MATERIALPRODUCTSDTO_QUERY_
#define _MATERIALPRODUCTSDTO_QUERY_

#include "../../GlobalInclude.h"
#include "../../dto/materialproducts/materialproductsDTO.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class MaterialProductsQuery : public PageQuery
{
	DTO_INIT(MaterialProductsQuery, PageQuery);
	// ���ϱ��
	DTO_FIELD(UInt64, templateId);
	DTO_FIELD_INFO(templateId) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.templateId");
	}
	// ģ�����
	DTO_FIELD(Int32, itemCode);
	DTO_FIELD_INFO(itemCode) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.itemCode");
	}
	// ģ������
	DTO_FIELD(String, itemName);
	DTO_FIELD_INFO(itemName) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.itemName");
	}
	// ģ����
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.specification");
	}
	// ��λ
	DTO_FIELD(String, unitOfmeasure);
	DTO_FIELD_INFO(unitOfmeasure) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.unitOfmeasure");
	}
	// �������
	DTO_FIELD(String, quantityCheck);
	DTO_FIELD_INFO(quantityCheck) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.quantityCheck");
	}
	// ����ȱ������
	DTO_FIELD(String, crRate);
	DTO_FIELD_INFO(crRate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.crRate");
	}
	// ����ȱ������
	DTO_FIELD(String, majRate);
	DTO_FIELD_INFO(majRate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.majRate");
	}
	// ��΢ȱ������
	DTO_FIELD(String, minRate);
	DTO_FIELD_INFO(minRate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.minRate");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.remark");
	}
	// ����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.createTime");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_