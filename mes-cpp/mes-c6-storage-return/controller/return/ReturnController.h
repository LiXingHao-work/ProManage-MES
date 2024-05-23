#pragma once

#ifndef _RCONTROLLER_H_
#define _RCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "../../domain/query/return/ReturnQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/return/ReturnVO.h"
#include "ApiHelper.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReturnController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(ReturnController);
public:
	// �����ѯ���е�����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllReturn) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("return.query-all.summary"), ReturnPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", true);
	}
	// �����ѯ���е�����Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/return/query-all", queryAllReturn, ReturnQuery, executeQueryAll(query));


	// �����޸ĵ��ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.modify-return.summary"), modifyReturn, Uint64JsonVO::Wrapper);
	// �����޸ĵ��ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/return/modify-return", modifyReturn, BODY_DTO(ReturnDTO::Wrapper, dto), executeModifyReturn(dto));

	// ����ִ���˻��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.execute-return.summary"), executeReturn, Uint64JsonVO::Wrapper);
	// ����ִ���˻��ӿڴ��� "/return/{returnId}"�����Ӧ
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/{returnIdexec}", executeReturn, PATH(UInt64, returnIdexec), executeExecuteReturn(returnIdexec));

	// ����ɾ�����ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.remove-return.summary"), removeReturn, Uint64JsonVO::Wrapper);
	// ����ɾ�����ݽӿڴ��� "/return/{returnId}"�����Ӧ
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/{returnIdremo}", removeReturn, PATH(UInt64, returnIdremo), executeRemoveReturn(returnIdremo));

	// ���嵼�����ݽӿ�����
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("return.download-return.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("return.fields.filename"), "file/C6RyanTest.jpg", true);
	}
	// ���嵼�����ݽӿڴ���
	ENDPOINT(API_M_GET, "/return/download", downloadFile, QUERY(String, filename)) {
		return executeDownloadFile(filename);
	}
private:
	// ��ѯ���е�����Ϣ
	ReturnPageJsonVO::Wrapper executeQueryAll(const ReturnQuery::Wrapper& returnQuery);
	// �޸ĵ���
	Uint64JsonVO::Wrapper executeModifyReturn(const ReturnDTO::Wrapper& dto);
	// ִ�е���
	Uint64JsonVO::Wrapper executeExecuteReturn(const UInt64& id);
	// ɾ������
	Uint64JsonVO::Wrapper executeRemoveReturn(const UInt64& id);
	// ��������
	std::shared_ptr<OutgoingResponse> executeDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RCONTROLLER_H_