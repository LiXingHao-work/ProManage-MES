#pragma once
#ifndef _WAREHOUSEMANAGEMENT_DAO_
#define _WAREHOUSEMANAGEMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/warehousemanagement/WarehouseManagementDO.h"
#include "../../domain/query/warehousemanagement/WarehouseManagementQuery.h"

/**
 * �����ݿ����ʵ��
 */
class WarehouseManagementDAO : public BaseDAO
{
public:

	// ͳ����������
	uint64_t count(const WarehouseManagementQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<WarehouseManagementDO> selectWithPage(const WarehouseManagementQuery::Wrapper& query);


};
#endif // !_WAREHOUSEMANAGEMENT_DAO_
