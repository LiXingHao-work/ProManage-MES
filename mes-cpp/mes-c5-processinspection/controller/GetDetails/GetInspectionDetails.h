#pragma once
#ifndef _GETDETAILS_H_
#define _GETDETAILS_H_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ProcessinSpection/ProcessinSpectionQuery.h"
#include "domain/dto/ProcessinSpection/ProcessinSpectionDTO.h"
#include "domain/vo/ProcessinSpection/ProcessinSpectionVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// ��ȡ���̼�������
class GetInspectionController : public oatpp::web::server::api::ApiController {
	// ���������
	API_ACCESS_DECLARE(GetInspectionController);


public:	// ����ӿ�
	// ��ȡ���̼�������
	ENDPOINT_INFO(queryGetInspectionDetails) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("todo"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessinSpectionJsonVO);
		//API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "ipqc_code", ZH_WORDS_GETTER("processinspection.field.ipqc_code"), "test", true);	// ֻ�ܸ��ݼ��鵥��Ų�ѯ
	}
	ENDPOINT(API_M_GET, "/processinspection/inspectiondetails", queryGetInspectionDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(detailsQuery, ProcessinSpectionQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryInspectionDetails(detailsQuery, authObject->getPayload()));
	}

private:
	ProcessinSpectionJsonVO::Wrapper execQueryInspectionDetails(const ProcessinSpectionQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_GETDETAILS_H_
