#pragma once
#ifndef _PRODUCTDTO_H_
#define _PRODUCTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�������ϵ��б�����ģ��
class ProductTableDTO :public oatpp::DTO
{
	DTO_INIT(ProductTableDTO, DTO);
	//Ψһ��ʶ���ϵ�id ����
	API_DTO_FIELD(UInt64, pid, ZH_WORDS_GETTER("product.fields.pid"), true, 200);
	//���ϵ����
	API_DTO_FIELD(String, pnum, ZH_WORDS_GETTER("product.fields.pnum"), true, "ISSUE20221115004");
	//���ϵ�����
	API_DTO_FIELD(String, pname, ZH_WORDS_GETTER("product.fields.pname"), true, "");
	//��������
	API_DTO_FIELD(String, plist, ZH_WORDS_GETTER("product.fields.plist"), true, "MO202211030003");
	//�ͻ����
	API_DTO_FIELD(String, pcnum, ZH_WORDS_GETTER("product.fields.pcnum"), true, "C00197");
	//�ͻ�����
	API_DTO_FIELD(String, pcname, ZH_WORDS_GETTER("product.fields.pcname"), true, "");
	//��������
	API_DTO_FIELD(String, pdate, ZH_WORDS_GETTER("product.fields.pdate"), true, "2022-11-15 00:00:00");
	//����״̬
	API_DTO_FIELD(String, pstatus, ZH_WORDS_GETTER("product.fields.pstatus"), true, "FINISHED");
};
//������������ģ��
class ProductDetailDTO :public ProductTableDTO
{
	DTO_INIT(ProductDetailDTO, ProductTableDTO);
	//���ϲֿ�
	API_DTO_FIELD(String, prname, ZH_WORDS_GETTER("product.fields.prname"), true, "");
	//��ע
	API_DTO_FIELD(String, premark, ZH_WORDS_GETTER("product.fields.premark"), true, "");

};
class ProductPageDTO :public PageDTO<ProductTableDTO::Wrapper> {
	DTO_INIT(ProductPageDTO, PageDTO<ProductTableDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif