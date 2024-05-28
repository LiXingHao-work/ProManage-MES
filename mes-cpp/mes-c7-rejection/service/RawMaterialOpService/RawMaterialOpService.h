#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ������
 @Date: 2024/05/19 11:08:56

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
#ifndef _RawMaterialOp_SERVICE_
#define _RawMaterialOp_SERVICE_
#include <list>
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"

#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"

#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"


/**
 * ��������������Ϣ�ķ���ӿ�
 */
class RawMaterialOpService
{
public:

	// ��������
	uint64_t saveData(const RawMaterialOpDTO::Wrapper& dto);

	// ��ҳ��ѯ��������
	RawMaterialOpPageDTO::Wrapper listAll(const RawMaterialOpQuery::Wrapper& query);

};

#endif 

