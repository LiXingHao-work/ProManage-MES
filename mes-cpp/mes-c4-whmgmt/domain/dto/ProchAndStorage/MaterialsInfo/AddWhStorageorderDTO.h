#pragma once
#ifndef _ADDWHSTORAGEORDERDTO_H_
#define _ADDWHSTORAGEORDERDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
����һ�������ⵥ����Ϣ�����ݴ�������
*/
class AddWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(AddWhStorageorderDTO, DTO);
	//��ⵥ���� recpt_name varchar
	API_DTO_FIELD_DEFAULT(String, recpt_name, ZH_WORDS_GETTER("whstorageorder.field.recpt_name"));
	//��ⵥ��� recpt_code varchar
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("whstorageorder.field.recpt_code"));
	//��Ӧ������ vendor_name varchar
	API_DTO_FIELD_DEFAULT(String, vendor_name, ZH_WORDS_GETTER("whstorageorder.field.vendor_name"));
	//�ɹ������� po_code varchar
	API_DTO_FIELD_DEFAULT(String, po_code, ZH_WORDS_GETTER("whstorageorder.field.po_code"));
	//����״̬ status varchar
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("whstorageorder.field.status"));
	//������� recpt_date String
	API_DTO_FIELD_DEFAULT(String, recpt_date, ZH_WORDS_GETTER("whstorageorder.field.recpt_date"));
	//���ֿ� warehouse_name varchar
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("whstorageorder.field.warehouse_name"));
	//��ע remark varchar
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("whstorageorder.field.remark"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // _ADDWHSTORAGEORDERDTO_H_
