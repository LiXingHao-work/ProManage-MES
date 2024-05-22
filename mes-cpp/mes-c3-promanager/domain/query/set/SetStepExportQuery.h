#pragma once

#ifndef _SETSTEPEXPORT_QUERY_
#define _SETSTEPEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����赼����ѯ����
 */
class SetStepExportQuery : public PageQuery
{
	DTO_INIT(SetStepExportQuery, PageQuery);
	// ������ID
	DTO_FIELD(String, SetStepCode);
	DTO_FIELD_INFO(SetStepCode) {
		info->description = ZH_WORDS_GETTER("setstep.field.code");
	}
	// ����������
	DTO_FIELD(String, SetStepName);
	DTO_FIELD_INFO(SetStepName) {
		info->description = ZH_WORDS_GETTER("setstep.field.name");
	}
	// �Ƿ�����
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("setstep.field.flag");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
