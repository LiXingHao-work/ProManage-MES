#pragma once
#ifndef _ADD_QUERY_
#define _ADD_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  ��Ŀ�ƻ���Ӷ���
 */
class AddQuery : public oatpp::DTO
{
	DTO_INIT(AddQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, subjectCode, ZH_WORDS_GETTER("add-mj.fields.scode"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectName, ZH_WORDS_GETTER("add-mj.fields.sname"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectType, ZH_WORDS_GETTER("add-mj.fields.stype"));
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, attr3, ZH_WORDS_GETTER("add-mj.fields.attr3"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectContent, ZH_WORDS_GETTER("add-mj.fields.scontent"));
	//��׼
	API_DTO_FIELD_DEFAULT(String, subjectStandard, ZH_WORDS_GETTER("add-mj.fields.sstandard"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_