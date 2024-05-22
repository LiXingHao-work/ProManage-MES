#pragma once
#ifndef _PROCESS_CONTROLLER_
#define _PROCESS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/process/ProcessListVO.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"

#include "domain/query/process/ProcessProductsQuery.h"
#include "domain/dto/process/ProcessProductsDTO.h"
#include "domain/vo/process/ProcessProductsVO.h"
#include "domain/query/process/ProcessQuery.h"

#include "domain/vo/process/ComProVo.h"
#include "domain/dto/process/ComProDTO.h"
#include "domain/query/process/ComProQuery.h"

#include "domain/vo/process/RelateProVO.h"
#include "domain/dto/process/RelateProDTO.h"
#include "domain/dto/process/ProMaterialDTO.h"
#include "domain/vo/process/ProMaterialVO.h"
#include "domain/query/process/ProMaterialQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������-�������̿�����
 */
class ProcessController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(ProcessController);

public:
	// 1 ��ȡ�����б�
	ENDPOINT_INFO(queryProcessList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "routeCode", ZH_WORDS_GETTER("process.field.routecode"), "R1126", false);
		API_DEF_ADD_QUERY_PARAMS(String, "routeName", ZH_WORDS_GETTER("process.field.name"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("process.field.flag"), "Y", false);
	}
	ENDPOINT(API_M_GET, "/pro/get-list", queryProcessList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProcessListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessList(Query));//, authObject->getPayload()
	}

	// 2 ��ȡ��������
	ENDPOINT_INFO(queryProcessDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessDetailJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "routeId", ZH_WORDS_GETTER("process.field.id"), 239, true);
	}
	ENDPOINT(API_M_GET, "/pro/get-detail", queryProcessDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProcessDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessDetail(Query));
	}

	// 3 ��ӹ�������
	ENDPOINT_INFO(addProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.post.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-process", addProcess, BODY_DTO(ProcessAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProcess(dto));
	}

	// 4 �޸Ĺ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("process.put.summary1"), modifyProcess, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-process", modifyProcess, BODY_DTO(ProcessAddDTO::Wrapper, dto), execModifyBasicProcess(dto));

	// 5 ��ȡ���չ�����Ʒ�б�
	ENDPOINT_INFO(queryCorrProduct) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary3"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("product.field.id"), "249", false);

	}
	ENDPOINT(API_M_GET, "/pro/get-corrprocess", queryCorrProduct, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProcessProductsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProducts(userQuery));
	}

	// 6 ɾ����ɹ���
	ENDPOINT_INFO(removeProcess) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("process.del.summary1"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-process/{id}", removeProcess, QUERY(List<UInt64>, id), execRemoveProcess(id));

	// 7 ���յ���
	ENDPOINT_INFO(queryProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get_field.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "route_code", ZH_WORDS_GETTER("process.field.route_code"), "R1121", false);
		API_DEF_ADD_QUERY_PARAMS(String, "route_name", ZH_WORDS_GETTER("process.field.route_name"), ZH_WORDS_GETTER("process.field.example"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "enable_flag", ZH_WORDS_GETTER("process.field.enable_flag"), "Y", false);
	}
	ENDPOINT(API_M_POST, "/set/export-process", queryProcess, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProcessQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcess(userQuery));
	}

	// 8 ��ȡ��ɹ����б�
	ENDPOINT_INFO(QueryProTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pro.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "process_name", ZH_WORDS_GETTER("pro.fields.proName"), "01 star", false);
		API_DEF_ADD_QUERY_PARAMS(String, "process_code", ZH_WORDS_GETTER("pro.fields.proCode"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "key_flag", ZH_WORDS_GETTER("pro.fields.key_flag"), "No", false);
	}
	ENDPOINT(API_M_GET, "/pro/query-pro-table", QueryProTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProTable(Query));
	}

	// 9 �����ɹ���
	ENDPOINT_INFO(addComProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pro.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-comprocess", addComProcess, BODY_DTO(NewProcessDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execaddComProcess(dto));
	}

	// 10 �޸���ɹ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("pro.modify.summary"), ModifyProcess, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-comprocess", ModifyProcess, BODY_DTO(ModifyProDTO::Wrapper, dto), execModifyProcess(dto));

	//11 ��ӹ��չ�����Ʒ
	ENDPOINT_INFO(addRelatePro) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RelatePro.summary.AddRelatePro"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-relatepro", addRelatePro, BODY_DTO(AddRelateProDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRelatePro(dto));
	}

	// 12 �޸Ĺ��չ�����Ʒ
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RelatePro.summary.ModRelatePro"), modifyRelatePro, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-relatepro", modifyRelatePro, BODY_DTO(ModRelateProDTO::Wrapper, dto), execModifyRelatePro(dto));

	// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
	ENDPOINT_INFO(queryProMaterial) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RelatePro.summary.ProMaterial"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProMaterialPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "item_code", ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_code"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_name"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/pro/query-promaterial-table", queryProMaterial, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProMaterialQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProMaterial(query, authObject->getPayload()));
	}

private:
	// 1 ��ȡ�����б�����
	ProcessListJsonVO::Wrapper execQueryProcessList(const ProcessListQuery::Wrapper& query);
	// 2 ��ѯ��������
	ProcessDetailJsonVO::Wrapper execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query);
	// 3 ��ӹ�������
	Uint64JsonVO::Wrapper execAddProcess(const ProcessAddDTO::Wrapper& dto);
	// 4 �޸Ĺ��ջ�������
	Uint64JsonVO::Wrapper execModifyBasicProcess(const ProcessAddDTO::Wrapper& dto);
	// 5 ��ȡ���չ�����Ʒ�б�
	ProductsPageJsonVO::Wrapper execQueryProducts(const ProcessProductsQuery::Wrapper& query);
	// 6 ɾ����ɹ���֧������ɾ����
	Uint64JsonVO::Wrapper execRemoveProcess(const List<UInt64>& id);
	// 7 ���յ���
	StringJsonVO::Wrapper execQueryProcess(const ProcessQuery::Wrapper& query);
	// 8 ��ȡ��ɹ����б�
	ProJsonVO::Wrapper execProTable(const ProQuery::Wrapper& query);
	// 9 �����ɹ���
	Uint64JsonVO::Wrapper execaddComProcess(const NewProcessDTO::Wrapper& dto);
	// 10 �޸���ɹ���
	Uint64JsonVO::Wrapper execModifyProcess(const ModifyProDTO::Wrapper& dto);
	// 11 ��ӹ��չ�����Ʒ
	Uint64JsonVO::Wrapper execAddRelatePro(const AddRelateProDTO::Wrapper& dto);
	// 12 �޸Ĺ��չ�����Ʒ
	Uint64JsonVO::Wrapper execModifyRelatePro(const ModRelateProDTO::Wrapper& dto);
	// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
	ProMaterialPageJsonVO::Wrapper execQueryProMaterial(const ProMaterialQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


