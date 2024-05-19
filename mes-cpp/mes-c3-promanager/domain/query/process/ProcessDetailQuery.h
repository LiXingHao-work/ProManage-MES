#pragma once
#ifndef _PROCESSDETAIL_QUERY_
#define _PROCESSDETAIL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������ѯ����
 */
class ProcessDetailQuery : public PageQuery
{
	DTO_INIT(ProcessDetailQuery, PageQuery);

	// Ψһ��ʶ
	DTO_FIELD(UInt32, routeId);
	DTO_FIELD_INFO(routeId) {
		info->description = ZH_WORDS_GETTER("process.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_