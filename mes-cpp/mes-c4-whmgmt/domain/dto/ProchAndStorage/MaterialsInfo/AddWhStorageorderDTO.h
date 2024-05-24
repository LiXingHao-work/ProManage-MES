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
	//���ϱ��� item_code varchar
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("whstorageorder.field.item_code"));
	//�������� item_name varchar
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("whstorageorder.field.item_name"));
	//��λ unit_of_measure varchar
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("whstorageorder.field.unit_of_measure"));
	//������� quantity_recived double
	API_DTO_FIELD_DEFAULT(Float64, quantity_recived, ZH_WORDS_GETTER("whstorageorder.field.quantity_recived"));
	//������κ� batch_code varchar
	API_DTO_FIELD_DEFAULT(String, batch_code, ZH_WORDS_GETTER("whstorageorder.field.batch_code"));
	//��Ч�� expire_date String
	API_DTO_FIELD_DEFAULT(String, expire_date, ZH_WORDS_GETTER("whstorageorder.field.expire_date"));
	//���ֿ� warehouse_name varchar
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("whstorageorder.field.warehouse_name"));
	//�Ƿ���� iqc_check char
	API_DTO_FIELD_DEFAULT(String, iqc_check, ZH_WORDS_GETTER("whstorageorder.field.iqc_check"));
	//���ϼ��鵥���� iqc_code varchar
	API_DTO_FIELD_DEFAULT(String, iqc_code, ZH_WORDS_GETTER("whstorageorder.field.iqc_code"));
	//���ϼ��鵥ID iqc_id bigint
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("whstorageorder.field.iqc_id"));
	//��ע remark varchar
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("whstorageorder.field.remark"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // _ADDWHSTORAGEORDERDTO_H_
