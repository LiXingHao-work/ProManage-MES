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
#include "domain/dto/set/SetProListDTO.h"
#include "domain/query/set/SetStepExportQuery.h"
#include "domain/vo/set/SetProListVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ContentService
{
public:
	// 分页查询所有数据
	SetProListPageDTO::Wrapper listAll(const SetStepExportQuery::Wrapper& query);
	// 保存数据
	bool saveData(const SetProListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const SetProListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	// 通过ID删除数据
	bool removeStep(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

