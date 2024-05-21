#pragma once
#ifndef _MODIFYWHSTORAGEORDERDTO_H_
#define _MODIFYWHSTORAGEORDERDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
����һ���޸���ⵥ�е����ݴ�������
*/
class ModifyWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(ModifyWhStorageorderDTO, DTO);
	//��ⵥid(��ʶ����Ψһ)
	API_DTO_FIELD_DEFAULT(UInt64, recpt_id, ZH_WORDS_GETTER("whstorageorder.field.recpt_id"), true, 0);
	//��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recpt_name, ZH_WORDS_GETTER("whstorageorder.field.recpt_name"), true, ZH_WORDS_GETTER("whstorageorder.defult.recpt_name"));
	//��ⵥ���
	API_DTO_FIELD_DEFAULT(String, recpt_code, ZH_WORDS_GETTER("whstorageorder.field.recpt_code"), true, "R20230905001");
	//��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendor_name, ZH_WORDS_GETTER("whstorageorder.field.vendor_name"), true, "DUOMU");
	//�ɹ�������
	API_DTO_FIELD_DEFAULT(String, po_code, ZH_WORDS_GETTER("whstorageorder.field.po_code"), true);
	//����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("whstorageorder.field.status"), false );
	//�������
	API_DTO_FIELD_DEFAULT(String, recpt_date, ZH_WORDS_GETTER("whstorageorder.field.recpt_date"), true, "2023-09-05");
	//���ֿ�
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("whstorageorder.field.warehouse_name"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("whstorageorder.field.remark"));

};

/*
����һ���޸ĺ������Ϣ�ķ�ҳ�������
*/
class ModifyWhPageStorageorderDTO : public PageDTO<ModifyWhStorageorderDTO::Wrapper>
{
	DTO_INIT(ModifyWhPageStorageorderDTO, PageDTO<ModifyWhStorageorderDTO::Wrapper>);
	//.....
};



#include OATPP_CODEGEN_END(DTO)
#endif // _MODIFYWHSTORAGEORDERDTO_H_
