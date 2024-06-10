#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _RETURNCONTROLLER_R_H_
#define _RETURNCONTROLLER_R_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/return-ryan/ReturnQuery_r.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/return-ryan/ReturnVO_r.h"
#include "ApiHelper.h"
#include "domain/dto/return-ryan/ReturnDTO_r.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReturnController_r : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(ReturnController_r);
public:
	//// 3.1 �����ѯ�ӿ�����
	//ENDPOINT_INFO(queryAllReturn) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.query-all.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ReturnPageJsonVO);
	//	// �����ҳ��ѯ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ����������ѯ��������
	//	// �˻�������
	//	API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", false);
	//	// �˻������
	//	API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123456", false);
	//	// �ɹ������
	//	API_DEF_ADD_QUERY_PARAMS(String, "purchaseCode", ZH_WORDS_GETTER("return.fields.pucode"), "null", false);
	//	// ��Ӧ������
	//	API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("return.fields.vename"), "01star", false);
	//}
	//// 3.2 �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/return/query-all", queryAllReturn, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(query, ReturnQuery, queryParams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(executeQueryAll(query, authObject->getPayload()));
	//}

	//// �����ѯ����������ϸ��Ϣ�ӿ�����
	//ENDPOINT_INFO(queryReturnDetail) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.query-detail.summary"));
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ReturnDetailJsonVO);
	//	// ����Ĭ����Ȩ����
	//	API_DEF_ADD_AUTH();
	//	// ����������ѯ��������
	//	// �˻������
	//	API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123456", true);
	//}
	//// �����ѯ������ϸ��Ϣ�ӿڶ˵㴦��
	//ENDPOINT(API_M_GET, "/return/query-detail", queryReturnDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(query, ReturnDetailQuery, queryParams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(executeQueryDetail(query));
	//}

	//// ��������µ�����Ϣ�ӿ�����
	//ENDPOINT_INFO(addReturnDetail) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.add-detail.summary"));
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//	// ����Ĭ����Ȩ����
	//	API_DEF_ADD_AUTH();
	//	// ����������ѯ��������
	//	// �˻������
	//	API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123", true);
	//	// �˻�������
	//	API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", true);
	//	// �ɹ������
	//	API_DEF_ADD_QUERY_PARAMS(String, "purchaseCode", ZH_WORDS_GETTER("return.fields.pucode"), "null", false);
	//	// ��Ӧ������
	//	API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("return.fields.vename"), "01star", true);
	//	// ���κ�
	//	API_DEF_ADD_QUERY_PARAMS(String, "batchCode", ZH_WORDS_GETTER("return.fields.batchcode"), "null", false);
	//	// �˻�����
	//	API_DEF_ADD_QUERY_PARAMS(String, "returndate", ZH_WORDS_GETTER("return.fields.rtdate"), "2024-5-21", true);
	//	// ����״̬
	//	API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("return.fields.status"), "PREPARE", true);
	//	// ��ע
	//	API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("return.fields.remark"), " ", false);
	//}
	//// ��������������ϸ��Ϣ�ӿڶ˵㴦��
	//ENDPOINT(API_M_POST, "/return/add-detail", addReturnDetail, BODY_DTO(ReturnAdd::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execAddDetail(dto));
	//}


	//Ryan
	// �����޸ĵ��ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.modify.summary"), modifyReturn, Uint64JsonVO::Wrapper);
	// �����޸ĵ��ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/return/modify", modifyReturn, BODY_DTO(ReturnDTO_r::Wrapper, dto), execModifyReturn(dto));

	// ����ִ���˻��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.execute.summary"), executeReturn, Uint64JsonVO::Wrapper);
	// ����ִ���˻��ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/return/{rt_id_exec}", executeReturn, PATH(UInt64, rt_id_exec), execExecuteReturn(rt_id_exec));

	// ����ɾ�����ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.remove.summary"), removeReturn, Uint64JsonVO::Wrapper);
	// ����ɾ�����ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/remove", removeReturn, BODY_DTO(List<UInt64>, ids), execRemoveReturn(ids));

	// ���嵼�����ݽӿ�����
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("return.download.summary"), Void);
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("return.field.rt_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rt_name", ZH_WORDS_GETTER("return.field.rt_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "po_code", ZH_WORDS_GETTER("return.field.po_code"), "", false);


	}
	// ���嵼�����ݽӿڴ���
	ENDPOINT(API_M_GET, "/return/export", downloadFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ReturnQuery_r, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDownloadFile(userQuery, authObject->getPayload()));
	}

private:
	//// ��ѯ���е�����Ϣ
	//ReturnPageJsonVO::Wrapper executeQueryAll(const ReturnQuery::Wrapper& returnQuery, const PayloadDTO& payload);
	//// ��ѯ��һ������ϸ��Ϣ
	//ReturnDetailJsonVO::Wrapper executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery);
	//// ����µ�����ϸ��Ϣ
	//Uint64JsonVO::Wrapper execAddDetail(const ReturnAdd::Wrapper& returnAdd);
	// �޸ĵ���
	Uint64JsonVO::Wrapper execModifyReturn(const ReturnDTO_r::Wrapper& dto);
	// ִ�е���
	Uint64JsonVO::Wrapper execExecuteReturn(const UInt64& id);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveReturn(const oatpp::List<UInt64>& ids);
	// ��������
	StringJsonVO::Wrapper execDownloadFile(const ReturnQuery_r::Wrapper& query, const PayloadDTO& payload);
	//
	StringJsonVO::Wrapper execDownloadFile_q(const ReturnQuery_r::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RETURNCONTROLLER_H_