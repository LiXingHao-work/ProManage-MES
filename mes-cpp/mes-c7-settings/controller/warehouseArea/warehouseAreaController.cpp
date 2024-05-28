/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "warehouseAreaController.h"
#include "service/warehouseArea/warehouseAreaService.h"

//controller����service�������ҳ��ѯ����(�����ڼ�ҳ��ÿҳ��С)
warehouseAreaPageJsonVO::Wrapper warehouseAreaController::execQueryWarehouseArea(const WarehouseAreaQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��service
	warehouseAreaService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = warehouseAreaPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//��ӿ���--��������dtoֻ����area_id area_code area_name area remark,û�вֿ�ID(������һ���ֿ����ĵ��ÿ��ṩ)
Uint64JsonVO::Wrapper warehouseAreaController::execAddWarehouseArea(const warehouseAreaListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��:���������
	if (!dto->area_code || !dto->area_name||!dto->area_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->area_code->empty() || dto->area_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	warehouseAreaService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper warehouseAreaController::execModifyWarehouseArea(const warehouseAreaListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->area_id || dto->area_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	warehouseAreaService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->area_id);
	}
	else
	{
		jvo->fail(dto->area_id);
	}
	// ��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper warehouseAreaController::execRemoveWarehouseArea(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	warehouseAreaService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}