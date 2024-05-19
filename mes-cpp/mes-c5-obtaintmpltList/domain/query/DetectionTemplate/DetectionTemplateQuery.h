#pragma once
#ifndef _DETECTIONTEMPLATE_QUERY_
#define _DETECTIONTEMPLATE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ģ���б� ��ҳ��ѯ����
 */
class DetectionTemplateQuery : public PageQuery {
	DTO_INIT(DetectionTemplateQuery, PageQuery);
	// ģ��ID
	DTO_FIELD(UInt64, template_id);
	DTO_FIELD_INFO(template_id) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_id");
	}
	// ģ����
	DTO_FIELD(String, template_code);
	DTO_FIELD_INFO(template_code) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_code");
	}
	// ģ������
	DTO_FIELD(String, template_name);
	DTO_FIELD_INFO(template_name) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_name");
	}
	// ģ������
	DTO_FIELD(String, qc_types);
	DTO_FIELD_INFO(qc_types) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.qc_types");
	}
	// �Ƿ�����ģ��
	DTO_FIELD(String, enable_flag);
	DTO_FIELD_INFO(enable_flag) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.enable_flag");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.remark");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETECTIONTEMPLATE_QUERY_
