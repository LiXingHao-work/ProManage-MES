#pragma once
#ifndef _RawMaterialOp_QUERY_
#define _RawMaterialOp_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class RawMaterialOpQuery : public PageQuery
{
	DTO_INIT(RawMaterialOpQuery, PageQuery);
	// ���ϵ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.id");
	}
	// ��������
	DTO_FIELD(String, order);
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.order");
	}
	// �ֿ�����
	DTO_FIELD(UInt32, warehouse);
	DTO_FIELD_INFO(warehouse) {
		info->description = ZH_WORDS_GETTER("RawMaterialOp.field.warehouse");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MATERIALINFORMATION_QUERY_