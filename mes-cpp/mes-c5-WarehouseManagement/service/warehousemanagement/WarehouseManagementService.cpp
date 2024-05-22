#include "stdafx.h"
#include "WarehouseManagementService.h"
#include "../../dao/warehousemanagement/WarehouseManagementDAO.h"
//ֻд�˻�ȡ��û��д����
WarehouseManagementPageDTO::Wrapper WarehouseManagementService::listAll(const WarehouseManagementQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WarehouseManagementPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	WarehouseManagementDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WarehouseManagementDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (WarehouseManagementDO sub : result)
	{
		auto dto = WarehouseManagementDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, item_code, Item_Code, item_name, Item_Name, batch_code, Batch_Code, warehouse_name, Warehouse_Name, vendor_code, Vendor_Code, vendor_name, Vendor_Name)
			pages->addData(dto);
	}
	return pages;
	return {};
}