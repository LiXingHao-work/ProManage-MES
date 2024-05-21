#pragma once
#ifndef _INSPECTDTO_H
#define _INSPECTDTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ϼ��鵥���ݴ������
 */
class InspectDTO:public oatpp::DTO
{
	DTO_INIT(InspectDTO, DTO);
	//// ����id
	//API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("inspect.id"));
	// ���ϼ��鵥���
	API_DTO_FIELD_DEFAULT(String, dode, ZH_WORDS_GETTER("inspect.code"));
	// ���ϼ��鵥����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("inspect.name"));
	// ��Ӧ�̼��
	API_DTO_FIELD_DEFAULT(String, vd_nick, ZH_WORDS_GETTER("inspect.vd_nick"));
	//��Ӧ�����κ�
	API_DTO_FIELD_DEFAULT(String, vd_batch, ZH_WORDS_GETTER("inspect.vd_batch"));
	//��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("inspect.item_code"));
	//��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("inspect.item_name"));
	//��������
	API_DTO_FIELD_DEFAULT(UInt64, quantity_recived, ZH_WORDS_GETTER("inspect.quantity_recived"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt64, quantity_check, ZH_WORDS_GETTER("inspect.quantity_check"));
	//���ϸ���
	API_DTO_FIELD_DEFAULT(UInt64, quantity_unqualified, ZH_WORDS_GETTER("inspect.quantity_unqualified"));
	//�����
	API_DTO_FIELD_DEFAULT(String, check_result, ZH_WORDS_GETTER("inspect.check_result"));
	//��������
	API_DTO_FIELD_DEFAULT(String, recive_date, ZH_WORDS_GETTER("inspect.recive_date"));
	//�������
	API_DTO_FIELD_DEFAULT(String, inspect_date, ZH_WORDS_GETTER("inspect.inspect_date"));
	//�����Ա
	API_DTO_FIELD_DEFAULT(String, inspector, ZH_WORDS_GETTER("inspect.inspector"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("inspect.status"));
};

class InspectPageDTO : public PageDTO<InspectDTO::Wrapper>
{
	DTO_INIT(InspectPageDTO, PageDTO<InspectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INSPECTDTO_H_