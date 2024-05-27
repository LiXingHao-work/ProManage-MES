#include "stdafx.h"
#include "WhStorageorderService.h"
#include "dao/ProchAndStorage/MaterialsInfo/WhStorageorderDAO.h"

uint64_t WhStorageorderService::addWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto)
{
	//��װDO����(��DTOת��ΪDO)
	AddWhStorageorderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Quantity_recived, quantity_recived, Batch_code, batch_code, Expire_date,expire_date);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_name, warehouse_name, Iqc_check, iqc_check, Iqc_code, iqc_code, Iqc_id, iqc_id, Remark, remark);
	//ִ���������
	WhStorageorderDAO dao;
	return dao.insert(data); //��������ID
}

bool WhStorageorderService::modifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto)
{
	//��װDO����(��DTOת��ΪDO)
	ModifyWhStorageorderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Line_id, line_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Quantity_recived, quantity_recived, Batch_code, batch_code, Expire_date, expire_date);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_name, warehouse_name, Iqc_check, iqc_check, Iqc_code, iqc_code, Iqc_id, iqc_id, Remark, remark);
	//ִ�������޸�
	WhStorageorderDAO dao;
	return dao.update(data) == 1; //�����Ƿ��޸���ȷ�����޸�Ӱ����һ�����ݣ����޸ĳɹ���
}
bool WhStorageorderService::deleteWhStorageorder(const oatpp::List<UInt64>& ids)
{
	//����б�Ϊ�գ�����Ϊɾ���ɹ�
	if (ids->empty()) {
		return true;
	}
	//ִ������ɾ��
	WhStorageorderDAO dao;
	return dao.deleteById(ids) == ids->size(); //�����Ƿ�ɾ����ȷ������Ӱ����������ids�б��С����ɾ���ɹ���
}