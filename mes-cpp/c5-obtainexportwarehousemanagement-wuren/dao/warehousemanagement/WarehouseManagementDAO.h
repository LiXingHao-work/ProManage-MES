#pragma once
#ifndef _WAREHOUSEMANAGEMENT_DAO_
#define _WAREHOUSEMANAGEMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/warehousemanagement/WarehouseManagementDO.h"
#include "../../domain/query/warehousemanagement/WarehouseManagementQuery.h"

/**
 * 表数据库操作实现
 */
class WarehouseManagementDAO : public BaseDAO
{
public:

	// 统计数据条数
	uint64_t count(const WarehouseManagementQuery::Wrapper& query);
	// 分页查询数据
	list<WarehouseManagementDO> selectWithPage(const WarehouseManagementQuery::Wrapper& query);


};
#endif // !_WAREHOUSEMANAGEMENT_DAO_
