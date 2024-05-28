﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 11:52:32

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
#ifndef _ProProcess_DO_
#define _ProProcess_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ProProcessDO
{
	CC_SYNTHESIZE(string,process_name, processName);
	CC_SYNTHESIZE(int, process_id, processId);
public:
	ProProcessDO() {
		process_id = 0;
		process_name = "";
	}
};

#endif // !_ProProcess_DO_
