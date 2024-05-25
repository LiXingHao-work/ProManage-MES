#include "stdafx.h"
#include "EquipmentService.h"
#include"../../dao/equipment/EquipmentDAO.h"
#include"../../domain/do/dv_machinery/dvMachineryDO.h"
#include"../../domain/dto/equipment/EquipmentDTO.h"
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
		auto dto = EquipmentDTO::createShared();
		dto->eId = sub.getMachineryId();
		dto->eCode = sub.getMachineryCode();
		dto->eName = sub.getMachineryName();
		dto->brand = sub.getMachineryBrand();
		dto->spec = sub.getMachinerySpec();
		dto->workshopId = sub.getWorkshopId();
		dto->workshopCode = sub.getWorkshopCode();
		dto->workshopName = sub.getWorkshopName();
		dto->status = sub.getStatus();
		dto->createtime = sub.getCreateTime();
			pages->addData(dto);

	}
	return pages;
}

EquipmentDetailDTO::Wrapper EquipmentService::getDetail(const EquipmentDetailQuery::Wrapper& query)
{
	auto one = EquipmentDetailDTO::createShared();
	EquipmentDAO dao;
	//��ѯ����
	list<dvMachineryDO> result = dao.selectWithId(query);
	
	// ��DOת����DTO
	for (dvMachineryDO sub : result)
	{
		auto dto = EquipmentDetailDTO::createShared();
		dto->eId = sub.getMachineryId();
		dto->eCode = sub.getMachineryCode();
		dto->eName = sub.getMachineryName();
		dto->brand = sub.getMachineryBrand();
		dto->tId = sub.getMachineryTypeId();
		dto->tCode = sub.getMachineryTypeCode();
		dto->tName = sub.getMachineryTypeName();
		dto->spec = sub.getMachinerySpec();
		dto->workshopId = sub.getWorkshopId();
		dto->workshopCode = sub.getWorkshopCode();
		dto->workshopName = sub.getWorkshopName();
		dto->note = sub.getRemark();
		
		return dto;
	}
	return {};
}

uint64_t EquipmentService::saveData(const addEquipmentDTO::Wrapper& dto)
{
	// ��װDO����
	dvMachineryDO  data;
	data.setMachineryCode(dto->eCode.getValue(""));
	data.setMachineryName(dto->eName.getValue(""));
	data.setMachineryBrand(dto->brand.getValue(""));
	data.setMachineryTypeName(dto->tName.getValue(""));
	data.setMachinerySpec(dto->spec.getValue(""));
	data.setWorkshopName(dto->workshopName.getValue(""));
	data.setRemark(dto->note.getValue(""));
	
	EquipmentDAO dao;
	return dao.insert(data);
}

bool EquipmentService::modifyData(const modifyEquipmentDTO::Wrapper& dto)
{
	// ��װDO����
	dvMachineryDO  data;
	data.setMachineryId(dto->eId.getValue(0));
	data.setMachineryCode(dto->eCode.getValue(""));
	data.setMachineryName(dto->eName.getValue(""));
	data.setMachineryBrand(dto->brand.getValue(""));
	data.setMachineryTypeName(dto->tName.getValue(""));
	data.setMachinerySpec(dto->spec.getValue(""));
	data.setWorkshopName(dto->workshopName.getValue(""));
	data.setRemark(dto->note.getValue(""));

	EquipmentDAO dao;
	return dao.modify(data);
}

