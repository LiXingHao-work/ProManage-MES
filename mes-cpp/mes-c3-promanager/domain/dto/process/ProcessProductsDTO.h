#pragma once
#ifndef _PROCESSPRODUCTS_DTO_
#define _PROCESSPRODUCTS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ProcessProductsDTO : public oatpp::DTO
{
	DTO_INIT(ProcessProductsDTO, DTO);

	// Ψһ��ʶ
	DTO_FIELD(UInt32, routeid);
	DTO_FIELD_INFO(routeid) {
		info->description = ZH_WORDS_GETTER("product.field.routeid");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("product.field.id");
	}
	// ��Ʒ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("product.field.name");
	}
	// ����ͺ�
	DTO_FIELD(String, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("product.field.size");
	}
	// ��λ
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("product.field.unit");
	}

};
/**
 * ���չ�����Ʒ�б��ҳ�������
 */
class ProductsPageDTO : public PageDTO<ProcessProductsDTO::Wrapper>
{
	DTO_INIT(ProductsPageDTO, PageDTO<ProcessProductsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
