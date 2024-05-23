#pragma once
#ifndef _PROINSPECT_CONTROLLER_
#define _PROINSPECT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/do/proinspect/ProinspectDO.h"
#include "../../../domain/dto/processinspection/proinspect/ProinspectDTO.h"
#include "../../../domain/vo/processinspection/proinspect/ProinspectVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class ProinspectController : public oatpp::web::server::api::ApiController {
	// 2 ����������������
	API_ACCESS_DECLARE(ProinspectController);
	// 3 ����ӿ�
public:
	ENDPOINT_INFO(addrecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qualitycontrol.defect.addre"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/proinspect", addrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddrecord(dto));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.setre"), execModifyrecord, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/proinspect", execModifyrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), execModifyrecord(dto));


	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removerecord) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.delre"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("qualitycontrol.defect.record_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/proinspect/{record_id}", removerecord, PATH(UInt64, record_id), execRemoverecord(record_id));

	////  �����ȡ���̼��鵥���б�ӿ�����
	//ENDPOINT_INFO(queryProcessInspectionList) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("processinspection.queryProcessInspectionList.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInspectionPageJsonVO);
	//	// ����������ѯ��������
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("processinspection.field.template_id"), 1, true);
	//}
	////  �����ȡ���̼��鵥���б�ӿڴ���
	//ENDPOINT(API_M_GET, "/inspectionitems1", queryProcessInspectionList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(userQuery, ProcessInspectionQuery, queryParams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execQueryProcessInspectionList(userQuery, authObject->getPayload()));
	//}
	////  �����ȡ���̼��鵥��ȱ���б�ӿ�����
	//ENDPOINT_INFO(queryProcessInspectionDefectList) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("processinspection.queryProcessInspectionDefectList.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ProinspectPageJsonVO);
	//	// ����������ѯ��������
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("processinspection.field.template_id"), 2, true);
	//}
	////  �����ȡ���̼��鵥��ȱ���б�ӿڴ���
	//ENDPOINT(API_M_GET, "/inspectionitems2", queryProcessInspectionDefectList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(userQuery, ProinspectQuery, queryParams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execQueryProcessInspectionDefectList(userQuery, authObject->getPayload()));
	//}

private:
	//��ʾ�������
	Uint64JsonVO::Wrapper execAddrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 �޸�����                           
	Uint64JsonVO::Wrapper execModifyrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoverecord(const UInt64& record_id);

	//  ��ȡ���̼��鵥���б�
	//ProinspectPageJsonVO::Wrapper execQueryProcessInspectionList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload);
	//  ��ȡ���̼��鵥��ȱ���б�
	//ProinspectPageJsonVO::Wrapper execQueryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload);
};







// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_