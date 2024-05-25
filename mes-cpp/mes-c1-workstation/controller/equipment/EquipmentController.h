#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _EQUIPMENTCONTROLLER_
#define _EQUIPMENTCONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/vo/EquipmentTypeTreeVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class EquipmentController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(EquipmentController);
	// 3 ����ӿ�
public:
	//��ѯ����(Path����)
	// 	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(getEquipmentById) {
		auto udef =
			//����ӿڱ���
			API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.getEquipmentById.summary"));
		//����ӿڲ���
		API_DEF_ADD_PATH_PARAMS(
			Int64,
			"equipmentId", ZH_WORDS_GETTER("equipment.params.equipmentId.desc"),
			1,
			true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT("GET", "/equipment/{equipmentId}", getEquipmentById,PATH(Int64, equipmentId))
	{
		OATPP_LOGD("���Դ�ӡ", "equipmentId=%d", equipmentId.getValue(0));
		return createResponse(Status::CODE_200, "OK");
	}

	//��ѯ����(Query����)
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(getEquipment) {
		auto udef =
			//����ӿڱ���
			API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.getEquipment.summary"));
		//����ӿڲ���
		API_DEF_ADD_QUERY_PARAMS(
			Int32,
			"equipmentId", ZH_WORDS_GETTER("equipment.params.equipmentId.desc"),
			1,
			true);
	}
	ENDPOINT("GET", "/equipment/getEquipment", getEquipment, QUERY(Int32, equipmentId))
	{
		OATPP_LOGD("���Դ�ӡ", "equipmentId=%d", equipmentId.getValue(0));
		return createResponse(Status::CODE_200, "OK");
	}
	
	// �����ѯ�豸���������б�ӿڶ˵�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipment.getEquipmentTypeTree.summary"), getEquipmentTypeTree, EquipmentTypeTreeVO::Wrapper);
	// �����ѯ�豸���������б�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/equipment/getEquipmentTypeTree", getEquipmentTypeTree, executeGetEquipmentTypeTree(authObject->getPayload()))

private:
	//StringJsonVO::Wrapper execteGetEquipmentPage(const PageQuery::Wrapper& query)
	//��ȡ�豸����������
	EquipmentTypeTreeVO::Wrapper executeGetEquipmentTypeTree(const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // EquipmentController