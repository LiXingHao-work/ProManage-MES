#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/5/18/21:38

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
#ifndef _REPAIRCONTENT_CONTROLLER_
#define _REPAIRCONTENT_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repaircontent/RepaircontentQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "domain/vo/repaircontent/RepaircontentVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class RepaircontentController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RepaircontentController);
	// 3 ����ӿ�
public:
	// ά�޵��������� �ӿ�����
	ENDPOINT_INFO(queryRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RepaircontentPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "repairContent", ZH_WORDS_GETTER("repaircontent.get.summary"), "", false);


	}
	// 3.2 ά�޵����� �ӿڴ���
	ENDPOINT(API_M_GET, "/repaircontent", queryRepaircontent, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(repairId, RepaircontentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRepaircontent(repairId));
	}

	// ����豸ά�޵��� �ӿ�����
		ENDPOINT_INFO(addRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.add_repaircontent"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���ά�޵� �ӿڴ���
	ENDPOINT(API_M_POST, "/repaircontent/add-repairorder", addRepaircontent, BODY_DTO(RepaircontentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRepaircontent(dto));
	}

	// �޸�ά�޵� �ӿ�����
	ENDPOINT_INFO(modifyRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.modify_repairorder"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// �޸�ά�޵� �ӿڴ���
	ENDPOINT(API_M_PUT, "/repaircontent/modify-repairorder", modifyRepaircontent, BODY_DTO(RepaircontentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyRepaircontent(dto));
	}

	// ɾ��ά�޵� �ӿ�����
	ENDPOINT_INFO(removeRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.remove_repairorder"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ɾ��ά�޵� �ӿڴ���
	ENDPOINT(API_M_PUT, "/repaircontent/modify-repairorder", removeRepaircontent, BODY_DTO(RepaircontentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execRemoveRepaircontent(dto));
	}

	
private:
	// 3.3 ά�޵�������������
	RepaircontentJsonVO::Wrapper execQueryRepaircontent(const RepaircontentQuery::Wrapper& id);	
	// 3.3 ���ά�޵�����
	Uint64JsonVO::Wrapper execAddRepaircontent(const RepaircontentDTO::Wrapper& dto);
	// 3.3 �޸�ά�޵�����
	Uint64JsonVO::Wrapper execModifyRepaircontent(const RepaircontentDTO::Wrapper& dto);
	// 3.3 ɾ��ά�޵�����
	Uint64JsonVO::Wrapper execRemoveRepaircontent(const RepaircontentDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _REPAIRCONTENT_CONTROLLER_