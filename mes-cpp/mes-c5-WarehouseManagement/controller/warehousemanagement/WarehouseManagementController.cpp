#include "stdafx.h"
#include "WarehouseManagementController.h"
//#include "../../service/warehousemanagement/WarehouseManagementService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/warehousemanagement/WarehouseManagementService.h"
#include "../../domain/vo/warehousemanagement/WarehouseManagementVO.h"
WarehouseManagementPageJsonVO::Wrapper WarehouseManagementController::execQueryWarehouseManagement(const WarehouseManagementQuery::Wrapper& query, const PayloadDTO& payloa)
{
	// ����һ��service
	WarehouseManagementService service;
	// ��ѯ����

	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = WarehouseManagementPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
	return {};
}

