#pragma once
#ifndef _PRODUCTQUERY_H_
#define _PRODUCTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������б��ѯ
 */
class ProductQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ProductQuery, PageQuery);
	//���ϵ����
	API_DTO_FIELD_DEFAULT(String, pnum, ZH_WORDS_GETTER("product.fields.pnum"));
	//���ϵ�����
	API_DTO_FIELD_DEFAULT(String, pname, ZH_WORDS_GETTER("product.fields.pname"));
	//�ֿ�����
	API_DTO_FIELD_DEFAULT(String, prname, ZH_WORDS_GETTER("product.fields.prname"));
	//��������
	API_DTO_FIELD_DEFAULT(String, pdate, ZH_WORDS_GETTER("product.fields.pdate"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, pstatus, ZH_WORDS_GETTER("product.fields.pstatus"));

};
//�����ѯ
class ProductDetailQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ProductQuery, DTO);
	//���ϵ����
	API_DTO_FIELD_DEFAULT(String, pnum, ZH_WORDS_GETTER("product.fields.pnum"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DEPTQUERY_H_