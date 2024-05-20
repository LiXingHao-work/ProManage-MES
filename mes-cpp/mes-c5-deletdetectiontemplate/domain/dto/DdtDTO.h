#pragma once
#ifndef _DDT_DTO_
#define _DDT_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class DdtDTO : public oatpp::DTO
{
	DTO_INIT(DdtDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}

};

/**
 * ʾ����ҳ�������
 */
class DdtPageDTO : public PageDTO<DdtDTO::Wrapper>
{
	DTO_INIT(DdtPageDTO, PageDTO<DdtDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
