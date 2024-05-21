#pragma once
#ifndef _DEFECT_CONTROLLER_
#define _DEFECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/defect/DefectQuery.h"
#include "domain/dto/defect/DefectDTO.h"
#include "domain/vo/defect/DefectVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DefectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DefectController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DefectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "defect_name", ZH_WORDS_GETTER("defect.field.defect_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "index_type", ZH_WORDS_GETTER("defect.field.index_type"), "APPEARANCE", false);
		API_DEF_ADD_QUERY_PARAMS(String, "defect_level", ZH_WORDS_GETTER("defect.field.defect_level"), "MIN", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/defect", queryDefect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DefectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDefect(userQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/defect", addDefect, BODY_DTO(DefectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDefect(dto));
	}

private:
	// 3.3 ��ҳ��ѯ����
	DefectPageJsonVO::Wrapper execQueryDefect(const DefectQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddDefect(const DefectDTO::Wrapper& dto);
		
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_