#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/ProduceWork/ProduceVO.h"
#include "domain/query/ProduceWork/PworkQery.h"
#include "domain/dto/ProduceWork/AddPworkDTO.h"
#include "domain/dto/ProduceWork/treansformProduceDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProduceWorkService
{
public:
	// ��ҳ��ѯ��������
	PworkPageDTO::Wrapper listAll(const PworkQery::Wrapper& query);
	// ��������
	uint64_t execAddtTable(const AddPworkTableDTO::Wrapper& dto);
	// �޸�����
	bool execModifyTable(const treansformProduceDTO::Wrapper& dto);
	
};

#endif // !_SAMPLE_SERVICE_

