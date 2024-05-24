#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _PRODORDER_DO_
#define _PRODORDER_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ProdOrderQueryDO
{
	// ������
	CC_SYNTHESIZE(string, task_name, Task_name);
	// ����վ
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	// ����
	CC_SYNTHESIZE(string, process_name, Process_name);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
public:
	//ProdOrderMenuDO() {}
	ProdOrderMenuDO() {
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};

/**
 * ʾ�����ݿ�ʵ����
 */
class ProdOrderQueryTreeDO
{
	// ������
	CC_SYNTHESIZE(string, task_name, Task_name);
	// ����վ
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	// ����
	CC_SYNTHESIZE(string, process_name, Process_name);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
public:
	MenuDO() {}
	MenuDO(string task_name, string workstation_name, string process_name, string start_time, string end_time)
	{
		this->task_name = task_name;
		this->workstation_name = workstation_name;
		this->process_name = process_name;
		this->start_time = start_time;
		this->end_time = end_time;
	}
};

/**
 * ʾ�����ݿ�ʵ����
 */
class ProdOrderAddDO
{
	// ������
	CC_SYNTHESIZE(string, task_name, Task_name);
	// ����վ
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	// ����
	CC_SYNTHESIZE(string, process_name, Process_name);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
public:
	//ProdOrderMenuDO() {}
	ProdOrderMenuDO() {
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};

#endif // !_PRODORDER_DO_
