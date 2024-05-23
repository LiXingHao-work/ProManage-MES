#pragma once

#ifndef _REMOVEWORKREPORT_CONTROLLER_H
#define _REMOVEWORKREPORT_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/prodmgmt/DeleteWorkReportDTO.h"
#include "../../domain/vo/prodmgmt/DeleteWorkReportVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class RemoveWorkReportController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RemoveWorkReportController);

public: // ����ӿ�
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeWorkReport) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prodmgmt.delete.describe.name"), DeleteWorkReportVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "recptCode", ZH_WORDS_GETTER("prodmgmt.delete.fields.recptCode"), "MO202211030003", false);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/prodmgmt/remove-work-report/{recptCode}", removeWorkReport, PATH(String, recptCode), execRemoveWorkReport(recptCode));




private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execRemoveWorkReport(const String& recptCode);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _REMOVEWORKREPORT_CONTROLLER_H