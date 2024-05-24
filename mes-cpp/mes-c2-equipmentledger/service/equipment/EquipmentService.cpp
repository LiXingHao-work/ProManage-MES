#include "stdafx.h"
#include "EquipmentService.h"
#include"../../dao/equipment/EquipmentDAO.h"
#include"../../domain/do/dv_machinery/dvMachineryDO.h"
EquipmentPageDTO::Wrapper EquipmentService::listAll(const EquipmentQuery::Wrapper& query)
{
	// �������ض���
	auto pages = EquipmentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	

	// ��ѯ����������
	EquipmentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<dvMachineryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (dvMachineryDO sub : result)
	{
		auto dto = SampleDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
}
