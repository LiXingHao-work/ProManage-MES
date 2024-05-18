#pragma once
#ifndef _PROCESSINSPECTION_DTO_
#define _PROCESSINSPECTION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���̼���DTO
 */
class ProcessinSpectionDTO : public oatpp::DTO
{
	DTO_INIT(ProcessinSpectionDTO, DTO);
	// ���(Ψһֵ)
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.id");
	}
	// ���鵥���
	DTO_FIELD(String, ipqc_code);
	DTO_FIELD_INFO(ipqc_code) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.ipqc_code");
	}
	// ���鵥����
	DTO_FIELD(String, ipqc_name);
	DTO_FIELD_INFO(ipqc_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.ipqc_name");
	}
	// ��������
	DTO_FIELD(String, ipqc_type);
	DTO_FIELD_INFO(ipqc_type) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.ipqc_type");
	}
	// �������
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.workorder_code");
	}
	// ��������
	DTO_FIELD(String, workorder_name);
	DTO_FIELD_INFO(workorder_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.workorder_name");
	}
	// ����վ���
	DTO_FIELD(String, workstation_id);
	DTO_FIELD_INFO(workstation_id) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.workstation_id");
	}
	// ����վ����
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.workstation_name");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.item_code");
	}
	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.item_name");
	}
	// ����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.specification");
	}
	// �������
	DTO_FIELD(String, process_code);
	DTO_FIELD_INFO(process_code) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.process_code");
	}
	// ��������
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.process_name");
	}
	// ������
	DTO_FIELD(String, task_code);
	DTO_FIELD_INFO(task_code) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.task_code");
	}
	// ��������
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.task_name");
	}
	// ��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.unit_of_measure");
	}
	// �������
	DTO_FIELD(Float64, quantity_check);
	DTO_FIELD_INFO(quantity_check) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.quantity_check");
	}
	// ���ϸ���
	DTO_FIELD(Float64, quantity_unqualified);
	DTO_FIELD_INFO(quantity_unqualified) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.quantity_unqualified");
	}
	// �ϸ���
	DTO_FIELD(Float64, quantity_qualified);
	DTO_FIELD_INFO(quantity_qualified) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.quantity_qualified");
	}
	// ����ȱ������
	DTO_FIELD(Float64, cr_quantity);
	DTO_FIELD_INFO(cr_quantity) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.cr_quantity");
	}
	// ����ȱ������
	DTO_FIELD(Float64, maj_quantity);
	DTO_FIELD_INFO(maj_quantity) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.maj_quantity");
	}
	// ��΢ȱ������
	DTO_FIELD(Float64, min_quantity);
	DTO_FIELD_INFO(min_quantity) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.min_quantity");
	}
	// �������
	DTO_FIELD(String, inspect_date);
	DTO_FIELD_INFO(inspect_date) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.inspect_date");
	}
	// �����Ա
	DTO_FIELD(String, inspector);
	DTO_FIELD_INFO(inspector) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.inspector");
	}
	// �����
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.check_result");
	}
	// ����״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.status");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("ProcessinSpection.field.remark");
	}
};

/**
 * ���̼���ҳ�������
 */
class ProcessinSpectionPageDTO : public PageDTO<ProcessinSpectionDTO::Wrapper>
{
	DTO_INIT(ProcessinSpectionPageDTO, PageDTO<ProcessinSpectionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSINSPECTION_DTO_