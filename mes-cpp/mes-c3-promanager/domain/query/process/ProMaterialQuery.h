#pragma once
#ifndef _PROMATERIAL_QUERY_H_
#define _PROMATERIAL_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��Ʒ�Ƴ�����BOM�б��ҳ��ѯ����
 */
class ProMaterialQuery : public PageQuery
{
	DTO_INIT(ProMaterialQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(UInt64, item_code, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_code"));
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROMATERIALQUERY_H_