#ifndef _MACHINERY_SUBJECT_DTO_
#define _MACHINERY_SUBJECT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����豸�б������
*/
class MachinerySubjectDTO : public oatpp::DTO
{
	DTO_INIT(MachinerySubjectDTO, DTO);

	// ��ˮ��
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.record-id");
	}

	//��Ŀ����
	DTO_FIELD(String, subject_code);
	DTO_FIELD_INFO(subject_code) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-code");
	}

	//��Ŀ����
	DTO_FIELD(String, subject_name);
	DTO_FIELD_INFO(subject_name) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-name");
	}

	//��Ŀ����
	DTO_FIELD(String, subject_type);
	DTO_FIELD_INFO(subject_type) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-type");
	}

	//��Ŀ����
	DTO_FIELD(String, subject_content);
	DTO_FIELD_INFO(subject_content) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-content");
	}

	//��׼
	DTO_FIELD(String, subject_standard);
	DTO_FIELD_INFO(subject_standard) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-standard");
	}
};

/**
* ���/�����豸�б��ҳ�������
*/
class MachinerySubjectPageDTO : public PageDTO<MachinerySubjectDTO::Wrapper>
{
	DTO_INIT(MachinerySubjectPageDTO, PageDTO<MachinerySubjectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_SUBJECT_DTO_