#pragma once

#ifndef _DELETEWORKREPORT_DTO_H
#define _DELETEWORKREPORT_DTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ɾ�����������ݴ���ģ��
 */
class DeleteWorkReportDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWorkReportDTO, DTO);
	// ���ݿ�ı� pro_feedback
	// 
	// �����������
	API_DTO_FIELD_DEFAULT(String, recptCode, ZH_WORDS_GETTER("prodmgmt.delete.fields.recptCode"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // _DELETEWORKREPORT_DTO_H