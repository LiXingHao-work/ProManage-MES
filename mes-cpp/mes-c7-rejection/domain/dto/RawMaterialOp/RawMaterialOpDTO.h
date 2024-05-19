#pragma once
#ifndef _RawMaterialOp_DTO_
#define _RawMaterialOp_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������������Ϣ�������
 */
class RawMaterialOpDTO : public oatpp::DTO
{
	DTO_INIT(RawMaterialOpDTO, DTO);
	// ���ϵ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.id");
	}
	// ���ϵ�����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.name");
	}
	// ��������
	DTO_FIELD(String, order);
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.order");
	}
	// ���ղֿ�
	DTO_FIELD(String, warehouse);
	DTO_FIELD_INFO(warehouse) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.warehouse");
	}
	//��������
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.date");
	}
	//��ע
	DTO_FIELD(String, common);
	DTO_FIELD_INFO(common) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.common");
	}

};

/**
 * ʾ����ҳ�������
 */
class RawMaterialOpPageDTO : public PageDTO<RawMaterialOpDTO::Wrapper>
{
	DTO_INIT(RawMaterialOpPageDTO, PageDTO<RawMaterialOpDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MaterialInformation_DTO_