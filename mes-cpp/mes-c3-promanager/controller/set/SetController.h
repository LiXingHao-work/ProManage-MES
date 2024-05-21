#pragma once
#ifndef _SET_CONTROLLER_
#define _SET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/set/ProcessExportQuery.h"
#include "domain/query/set/SetProListQuery.h"

#include "domain/dto/set/SetProAddDTO.h"
#include "domain/dto/set/SetProListDTO.h"
#include "domain/vo/set/SetProListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * �������̿�����
 */
class SetController : public oatpp::web::server::api::ApiController 
{

	API_ACCESS_DECLARE(SetController);

public:

// 1 �����ļ�
	ENDPOINT_INFO(queryProcessExport) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.export.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "processCode", ZH_WORDS_GETTER("set.field.code"), "R1126", false);
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("set.field.name"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("set.field.flag"), "Y", false);
	}
	ENDPOINT(API_M_POST, "/set/export", queryProcessExport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(Query, ProcessExportQuery, queryParams);
		API_HANDLER_RESP_VO(execProcessExport(Query));
	}

// 2 ��ӹ���ӿ�����
	ENDPOINT_INFO(addSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/set/add-set", addSet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddSet(dto));
	}

// 3 �޸Ĺ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("set.modify.summary"), modifySet, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/set/modify-set", modifySet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), execModifySet(dto));

// 4 ��ȡ�������б�ӿ�
	ENDPOINT_INFO(querySet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SetProListPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("set.fields.processid"), 1, false);
	}
	ENDPOINT(API_M_GET, "/set/query-list-set", querySet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, SetProListQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySet(query, authObject->getPayload()));
	}

// 5 ��ӹ�����ӿ�����
	ENDPOINT_INFO(addstepSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.addstep.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/set/addstep-set", addstepSet, BODY_DTO(SetProListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddStepSet(dto));
	}
private:
	// 1 �����ļ�
	StringJsonVO::Wrapper execProcessExport(const ProcessExportQuery::Wrapper& query);
	// 2 ��ӹ���
	Uint64JsonVO::Wrapper execAddSet(const SetProAddTableDTO::Wrapper& dto);
	// 3 �޸Ĺ���
	Uint64JsonVO::Wrapper execModifySet(const SetProAddTableDTO::Wrapper& dto);
	// 4 ��ȡ�������б�
	SetProListPageJsonVO::Wrapper execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload);
	// 5 ��ӹ�����
	Uint64JsonVO::Wrapper execAddStepSet(const SetProListDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) 
#endif 