/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/18 20:16:53

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

#include "stdafx.h"
#include "EquipmentController.h"
#include"service/equipment/EquipmentService.h"

EquipmentPageJsonVO::Wrapper EquipmentController::execEquipment(const EquipmentQuery::Wrapper& query)
{
	// ����һ��Service
	EquipmentService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EquipmentPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

EquipmentDetailJsonVO::Wrapper EquipmentController::execEquipmentDetail(const EquipmentDetailQuery::Wrapper& query)
{
	// ����һ��Service
	EquipmentService service;
	// ��ѯ����
	auto result = service.getDetail(query);
	// ��Ӧ���
	auto jvo = EquipmentDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper EquipmentController::execAddEquipment(const addEquipmentDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->eCode || !dto->eName || !dto->brand || !dto->tName || !dto->spec || !dto->workshopName|| !dto->note)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->eCode->empty() || dto->eName->empty() || dto->brand->empty() || dto->tName->empty() || dto->spec->empty() || dto->workshopName->empty() || dto->note->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EquipmentService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) 
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper EquipmentController::executeModifyEquipment(const modifyEquipmentDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->eId || !dto->eCode || !dto->eName || !dto->brand || !dto->tName || !dto->spec || !dto->workshopName || !dto->note)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->eId<0 || dto->eCode->empty() || dto->eName->empty() || dto->brand->empty() || dto->tName->empty() || dto->spec->empty() || dto->workshopName->empty() || dto->note->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EquipmentService service;
	// ִ������
	uint64_t id = service.modifyData(dto);
	if (id > 0)
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
