#pragma once
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class MaterialProductsDTO : public oatpp::DTO
{
	DTO_INIT(MaterialProductsDTO, DTO);
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
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.unitOfmeasure");
	}
	// �������
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
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
    


class SamplePageDTO : public PageDTO<MaterialProductsDTO::Wrapper>
{
	DTO_INIT(SamplePageDTO, PageDTO<MaterialProductsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_