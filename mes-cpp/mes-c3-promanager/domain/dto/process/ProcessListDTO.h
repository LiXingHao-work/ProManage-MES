#pragma once
#ifndef _PROCESSLIST_DTO_
#define _PROCESSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б������,���ȡ�������顢��ӹ��չ���
 */
class ProcessDTO : public oatpp::DTO
{
	DTO_INIT(ProcessDTO, DTO);

	// Ψһ��ʶ
	DTO_FIELD(UInt32, routeid);
	DTO_FIELD_INFO(routeid) {
		info->description = ZH_WORDS_GETTER("process.field.id");
	}
	// ·�߱��
	DTO_FIELD(String, routeCode);
	DTO_FIELD_INFO(routeCode) {
		info->description = ZH_WORDS_GETTER("process.field.code");
	}
	// ·������
	DTO_FIELD(String, routeName);
	DTO_FIELD_INFO(routeName) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// ·��˵��
	DTO_FIELD(String, routedesc);
	DTO_FIELD_INFO(routedesc) {
		info->description = ZH_WORDS_GETTER("process.field.desc");
	}
	// �Ƿ�����
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("process.field.remark");
	}
	// ����ʱ��
	DTO_FIELD(String, createtime);
	DTO_FIELD_INFO(createtime) {
		info->description = ZH_WORDS_GETTER("process.field.createtime");
	}
	// ����ʱ��
	DTO_FIELD(String, updatetime);
	DTO_FIELD_INFO(updatetime) {
		info->description = ZH_WORDS_GETTER("process.field.updatetime");
	}
};

/**
 * �����б��ҳ�������
 */
class ProcessListDTO : public PageDTO<ProcessDTO::Wrapper>
{
	DTO_INIT(ProcessListDTO, PageDTO<ProcessDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
