#pragma once
#ifndef _GETTEMPLATELIST_H_
#define _GETTEMPLATELIST_H_


#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/DetectionTemplate/DetectionTemplateQuery.h"
#include "domain/dto/DetectionTemplate/DetectionTemplateDTO.h"
#include "domain/vo/DetectionTemplate/DetectionTemplateVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class GetDetectionTemplateController : public oatpp::web::server::api::ApiController {
	// ���������
	API_ACCESS_DECLARE(GetDetectionTemplateController);


public:	// ����ӿ�

	ENDPOINT_INFO(queryDetectionTemplateList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.get.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionTemplatePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("DetectionTemplate.field.template_id"), 18, false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_code", ZH_WORDS_GETTER("DetectionTemplate.field.template_code"), "QCT2022040", false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_name", ZH_WORDS_GETTER("DetectionTemplate.field.template_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enable_flag", ZH_WORDS_GETTER("DetectionTemplate.field.enable_flag"), "Y", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("DetectionTemplate.field.remark"), "", false);
	}

	ENDPOINT(API_M_GET, "/detectiontemplate/getdetectiontemplatelist/page", queryDetectionTemplateList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(templateListQuery, DetectionTemplateQuery, queryParams);
		// ����ִ�к���
		API_HANDLER_RESP_VO(execQueryDetectionTemplateList(templateListQuery, authObject->getPayload()));
	}


private:	// ����ӿ�ִ�к���
	DetectionTemplatePageJsonVO::Wrapper execQueryDetectionTemplateList(const DetectionTemplateQuery::Wrapper& query, const PayloadDTO& payload);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // !_GETTEMPLATELIST_H_
