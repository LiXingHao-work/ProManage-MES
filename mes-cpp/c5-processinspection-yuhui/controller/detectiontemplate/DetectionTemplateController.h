#pragma once
#ifndef _DETECTIONTEMPLATE_CONTROLLER_
#define _DETECTIONTEMPLATE_CONTROLLER_

#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/detectiontemplate/DetectionTemplateDTO.h"
#include "../../domain/query/detectiontemplate/DetectionTemplateQuery.h"
#include "../../domain/vo/detectiontemplate/DetectionTemplateVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �޸ļ��ģ�� ����
 */
class DetectionTemplateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DetectionTemplateController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("DetectionTemplate.put.summary"), modifyDetectionTemplate, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/DetectionTemplate/modify", modifyDetectionTemplate, BODY_DTO(DetectionTemplateDTO::Wrapper, dto), execModifyDetectionTemplate(dto));

private:
	Uint64JsonVO::Wrapper execModifyDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DETECTIONTEMPLATE_CONTROLLER_