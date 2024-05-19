#ifndef _MACHINERY_LIST_DTO_
#define _MACHINERY_LIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����豸�б������
*/
class MachineryListDTO : public oatpp::DTO
{
	DTO_INIT(MachineryListDTO, DTO);

	// ��ˮ��
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.record-id");
	}

	//�豸����
	DTO_FIELD(String, machinery_code);
	DTO_FIELD_INFO(machinery_code) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.machinery-code");
	}

	//�豸����
	DTO_FIELD(String, machinery_name);
	DTO_FIELD_INFO(machinery_name) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.machinery-name");
	}

	//Ʒ��
	DTO_FIELD(String, machinery_brand);
	DTO_FIELD_INFO(machinery_brand) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.machinery-brand");
	}

	//����ͺ�
	DTO_FIELD(String, machinery_spec);
	DTO_FIELD_INFO(machinery_spec) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.machinery-spec");
	}

	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.remark");
	}
};

/**
* ���/�����豸�б��ҳ�������
*/
class MachineryListPageDTO : public PageDTO<MachineryListDTO::Wrapper>
{
	DTO_INIT(MachineryListPageDTO, PageDTO<MachineryListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_LIST_DTO_