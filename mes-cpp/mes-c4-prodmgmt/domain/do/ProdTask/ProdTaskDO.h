#pragma once

#include "../DoInclude.h"
/*
* �޸���������ʵ����
*/
class ProdTaskDO
{
	//����Id , task_id ,Task_id
	CC_SYNTHESIZE(int, task_id, Task_id);
	//������ , task_code ,Task_code
	CC_SYNTHESIZE(string, task_code, Task_code);
	//�������� , task_name ,Task_name
	CC_SYNTHESIZE(string , task_name, Task_name);
	//����id , workorder_id ,Workorder_id
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//������� , workorder_code ,Workorder_code
	CC_SYNTHESIZE(string , workorder_code, Workorder_code);
	//�������� , workorder_name ,Workorder_name
	CC_SYNTHESIZE(string , workorder_name, Workorder_name);
	//����վid, workstation_id, Workstation_id
	CC_SYNTHESIZE(int, workstation_id, Workstation_id);
	//����վ��� workstation_code Workstation_code
	CC_SYNTHESIZE(string, workstation_code, Workstation_code);
	//����վ���� workstation_name Workstation_name
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	//����ID route_id Route_id
	CC_SYNTHESIZE(int, route_id, Route_id);
	//���ձ��
	CC_SYNTHESIZE(string, route_code, Route_code);

	ProdTaskDO()
	{
		this->task_code = ;
    }
};