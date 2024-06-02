#include "stdafx.h"
#include "InspectService.h"
#include "../../dao/LaiLiaoInspect/InspectDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"

//��ѯ���ϼ����б�
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
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, iqc_id, Iqc_id, iqc_code, Iqc_code, iqc_name, Iqc_name, template_id, Template_id, vendor_id, Vendor_id, vendor_code, Vendor_code, vendor_name, Vendor_name, vendor_nick, Vendor_nick, vendor_batch, Vendor_batch, item_code, Item_code, item_name, Item_name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, quantity_recived, Quantity_recived, quantity_check, Quantity_check, quantity_unqualified, Quantity_unqualified, check_result, Check_result, recive_date, Recive_date, inspect_date, Inspect_date, inspector, Inspector, list_status, List_status);
		pages->addData(dto);
	}
	return pages;
}

//��ѯ���ϼ�������
Inspect_detailDTO::Wrapper InspectService::list_detailone(const uint64_t iqc_id)
{
	// �������ض���

	// ��ѯ����������
	InspectDAO dao;
	Inspect_detailDO result = dao.selectWithID(iqc_id);
	// ��DOת����DTO
		auto dto = Inspect_detailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, iqc_id, Iqc_id, iqc_code, Iqc_code, iqc_name, Iqc_name, vendor_id, Vendor_id, vendor_code, Vendor_code, vendor_name, Vendor_name, vendor_nick, Vendor_nick, vendor_batch, Vendor_batch, item_code, Item_code);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, item_name, Item_name, quantity_recived, Quantity_recived, quantity_check, Quantity_check, quantity_unqualified, Quantity_unqualified, check_result, Check_result, recive_date, Recive_date, inspect_date, Inspect_date, inspector, Inspector, list_status, List_status)
		return dto;
}

//��������
uint64_t InspectService::saveData(const InspectDTO::Wrapper& dto)
{
	 //��װDO����
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Iqc_id,iqc_id, Iqc_code, iqc_code, Iqc_name, iqc_name,  Template_id, template_id,  Vendor_id, vendor_id,  Vendor_code, vendor_code,  Vendor_name, vendor_name,  Vendor_nick, vendor_nick,  Vendor_batch, vendor_batch, Item_id,item_id, Item_code, item_code,  Item_name, item_name, Unit_of_measure, unit_of_measure, Quantity_recived, quantity_recived,  Quantity_check, quantity_check,  Quantity_unqualified, quantity_unqualified,  Check_result, check_result,  Recive_date, recive_date,  Inspect_date, inspect_date,  Inspector, inspector, List_status, list_status);
		 //ִ���������
		InspectDAO dao;
	return dao.insert(data);
}

//�޸�����
bool InspectService::updateData(const InspectDTO::Wrapper& dto)
{
	// ��װDO����
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Iqc_code, iqc_code, Iqc_name, iqc_name,  Vendor_code, vendor_code, Vendor_nick, vendor_nick, Vendor_batch, vendor_batch,Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Quantity_recived, quantity_recived, Quantity_check, quantity_check, Quantity_unqualified, quantity_unqualified, Check_result, check_result, Recive_date, recive_date, Inspect_date, inspect_date, List_status, list_status, Remark, remark ,Iqc_id, iqc_id );
		// ִ�������޸�
		InspectDAO dao;
	return dao.update(data) == 1;
}

//ɾ��
bool InspectService::removeData(uint64_t id)
{
	InspectDAO dao;
	return dao.deleteById(id) == 1;
}

//ȷ�ϼ��鵥
bool InspectService::Is_Ok(const Item_idDTO::Wrapper& dto)
{
	// ��װDO����
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Check_result, check_result,Iqc_id, iqc_id);
	// ִ�������޸�
	InspectDAO dao;
	return dao.Is_Ok(data) == 1;
}