#pragma once

#include "../DoInclude.h"
/*
* �޸���������ʵ����
*/
class ProdTaskModifyDO
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
	//ProdTaskModifyDO() {}
	ProdTaskModifyDO() {
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};
/*
* ɾ����������ʵ����
*/

class ProdTaskRemoveDO
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
	//ProdTaskRemoveDO() {}
	ProdTaskRemoveDO() {
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};

