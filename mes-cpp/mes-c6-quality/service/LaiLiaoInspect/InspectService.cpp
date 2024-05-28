#include "stdafx.h"
#include "InspectService.h"
#include "../../dao/LaiLiaoInspect/InspectDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"

InspectPageDTO::Wrapper InspectService::listAll(const InspectQuery::Wrapper& query)
{
	// �������ض���
	auto pages = InspectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	InspectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<InspectDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (InspectDO sub : result)
	{
		auto dto = InspectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, line_id, Line_id, code, Code, name, Name, template_id, Template_id, vendor_id, Vendor_id, vendor_code, Vendor_code, vendor_name, Vendor_name, vd_nick, Vd_nick, vd_batch, Vd_batch, item_code, Item_code, item_name, Item_name, quantity_recived, Quantity_recived, quantity_check, Quantity_check, quantity_unqualified, Quantity_unqualified, check_result, Check_result, recive_date,Recive_date, inspect_date, Inspect_date, inspector, Inspector, list_status, List_status)
			pages->addData(dto);
	}
	return pages;
}

uint64_t InspectService::saveData(const InspectDTO::Wrapper& dto)
{
	// ��װDO����
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name, Template_id, template_id, Vendor_id, vendor_id, Vendor_code, vendor_code, Vendor_name, vendor_name, Vd_nick, vd_nick, Vd_batch, vd_batch, Item_code, item_code, Item_name, item_name, Quantity_recived, quantity_recived, Quantity_check, quantity_check, Quantity_unqualified, quantity_unqualified, Check_result, check_result, Recive_date, recive_date, Inspect_date, inspect_date, Inspector, inspector, List_status, list_status)
		// ִ���������
		InspectDAO dao;
	return dao.insert(data);
}

bool InspectService::updateData(const InspectDTO::Wrapper& dto)
{
	// ��װDO����
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name, Template_id, template_id, Vendor_id, vendor_id, Vendor_code, vendor_code, Vendor_name, vendor_name, Vd_nick, vd_nick, Vd_batch, vd_batch, Item_code, item_code, Item_name, item_name, Quantity_recived, quantity_recived, Quantity_check, quantity_check, Quantity_unqualified, quantity_unqualified, Check_result, check_result, Recive_date, recive_date, Inspect_date, inspect_date, Inspector, inspector, List_status, list_status, Line_id, line_id)
		// ִ�������޸�
		InspectDAO dao;
	return dao.update(data) == 1;
}

bool InspectService::removeData(uint64_t id)
{
	InspectDAO dao;
	return dao.deleteById(id) == 1;
}