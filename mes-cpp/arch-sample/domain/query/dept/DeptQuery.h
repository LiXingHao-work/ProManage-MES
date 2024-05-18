#pragma once
#ifndef _DEPTQUERY_H_
#define _DEPTQUERY_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Ź����ѯ��������
 */
class DeptQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(DeptQuery, DTO);
	//��������
	API_DTO_FIELD_DEFAULT(String, deptName, ZH_WORDS_GETTER("dept.fields.dname"));
	//״̬
	API_DTO_FIELD_DEFAULT(Int32, status, ZH_WORDS_GETTER("dept.fields.dstatus"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DEPTQUERY_H_