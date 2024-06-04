#pragma once

#ifndef _WAREHOUSEMANAGEMENT_SERVICE_
#define _WAREHOUSEMANAGEMENT_SERVICE_
#include <list>
#include "domain/vo/warehousemanagement/WarehouseManagementVO.h"
#include "domain/query/warehousemanagement/WarehouseManagementQuery.h"
#include "domain/dto/warehousemanagement/WarehouseManagementDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class WarehouseManagementService
{
public:
	// ��ҳ��ѯ��������
	WarehouseManagementPageDTO::Wrapper listAll(const WarehouseManagementQuery::Wrapper& query);
	//����ecxcel
	string creatExcel(const WarehouseManagementIdQuery::Wrapper& query);
};

#endif // !_WAREHOUSEMANAGEMENT_SERVICE_

