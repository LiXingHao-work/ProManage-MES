#pragma once

#ifndef _INCOMING_CONTROLLER_
#define _INCOMING_CONTROLLER_

#include"domain/dto/incoming/IncomingDTO.h"
#include"domain/query/incoming/IncomingQuery.h"
#include"domain/vo/incoming/IncomingVO.h"
#include "domain/vo/BaseJsonVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class IncomingController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(IncomingController);
public:// ����ӿ�
	// �����ѯ�ṹ����
	ENDPOINT_INFO(queryIncoming) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("incoming.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(IncomingPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "incomingCode", ZH_WORDS_GETTER("incoming.fields.incode"), "110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorCode", ZH_WORDS_GETTER("incoming.fields.vcode"), "110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("incoming.fields.vname"), "zebul", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorBatch", ZH_WORDS_GETTER("incoming.fields.vbatch"), "110", false);
		
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/incoming", queryIncoming, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, IncomingQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryIncoming(userQuery, authObject->getPayload()));
	}
private:// ����ӿ�ִ�к���
	// 3.3 ��ʾ��ҳ��ѯ����
	IncomingPageJsonVO::Wrapper execQueryIncoming(const IncomingQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	//Uint64JsonVO::Wrapper execAddSample(const SampleDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INCOMING_CONTROLLER_