/*
 Copyright Zero One Star. All rights reserved.

 @Author: ������
 @Date: 2024/5/28 10:58:42

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
#include "ProController.h"
#include "../../service/ProduceWork/ProduceWorkService.h"


/*
������Ա��������
*/
ProduceTableJsonVO::Wrapper ProController::execPworkTable(const PworkQery::Wrapper& query)
{	
	// ����һ��Service
	ProduceWorkService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProduceTableJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return ProduceTableJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper ProController::execAddtTable(const PworkTableDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->feedback_type || !dto->feedback_code || !dto->task_code || !dto->product_code
		|| !dto->product_name || !dto->unit_of_measure || !dto->product_spc || !dto->quantity_feedback
		|| !dto->quantity_uncheck || !dto->nick_name || !dto->record_nick || !dto->feedback_time || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->feedback_type->empty() || dto->feedback_code->empty() || dto->task_code->empty() || dto->product_code->empty() ||
		dto->product_name->empty() || dto->unit_of_measure->empty() || dto->product_spc->empty() || dto->quantity_feedback->empty() ||
		dto->quantity_uncheck->empty() || dto->nick_name->empty() || dto->record_nick->empty() || dto->feedback_time->empty() || dto->remark->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ProduceWorkService service;
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
//
Uint64JsonVO::Wrapper ProController::execModifyTable(const treansformProduceDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	
	// ����У��
	if (   !dto->feedback_type || !dto->feedback_code || !dto->task_code || !dto->product_code
		|| !dto->product_name || !dto->unit_of_measure || !dto->product_spc || !dto->quantity_feedback
		|| !dto->quantity_uncheck || !dto->nick_name || !dto->record_nick || !dto->feedback_time || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->feedback_type->empty() || dto->feedback_code->empty() || dto->task_code->empty() || dto->product_code->empty()
		|| dto->product_name->empty() || dto->unit_of_measure->empty() || dto->product_spc->empty() || dto->quantity_feedback->empty()
		|| dto->quantity_uncheck->empty() || dto->nick_name->empty() || dto->record_nick->empty() || dto->feedback_time->empty()
		|| dto->remark->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// ����һ��Service
	ProduceWorkService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}