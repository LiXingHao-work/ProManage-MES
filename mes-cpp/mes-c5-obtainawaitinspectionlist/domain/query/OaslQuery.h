#pragma once
#ifndef _OASL_QUERY_
#define _OASL_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class OaslQuery : public PageQuery
{
	DTO_INIT(OaslQuery, PageQuery);
	//���ݱ���
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.code");
	}
	//��������
	DTO_FIELD(String, material);
	DTO_FIELD_INFO(material) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.material");
	}
	//�������
	DTO_FIELD(String, detectionType);
	DTO_FIELD_INFO(detectionType) {
		info->description = ZH_WORDS_GETTER("Pending_inspection.fields.detectionType");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_OASL_QUERY_

