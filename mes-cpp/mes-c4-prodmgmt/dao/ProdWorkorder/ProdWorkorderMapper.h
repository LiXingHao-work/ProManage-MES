#pragma once
#ifndef _PRODWORKORDER_MAPPER_
#define _PRODWORKORDER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../../domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderBomListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderInfoDO.h"

/**
 * ��ȡ������������
 */
class ProdWorkorderInfoMapper : public Mapper<ProdWorkorderInfoDO>
{
public:
	ProdWorkorderInfoDO mapper(ResultSet* resultSet) const override
	{
		ProdWorkorderInfoDO data;
		//����ID;workorder_id;bigint
		data.setWorkorder_id(resultSet->getUInt64(1));
		//��������;workorder_code;varchar
		data.setWorkorder_code(resultSet->getString(2));
		//��������;workorder_name;varchar
		data.setWorkorder_name(resultSet->getString(3));
		//��Դ����;order_source;varchar
		data.setOrder_source(resultSet->getString(4));
		//�������;source_code;varchar
		data.setSource_code(resultSet->getString(5));
		//����״̬;status;varchar
		data.setStatus(resultSet->getString(6));
		//��������;workorder_type;varchar
		data.setWorkorder_type(resultSet->getString(7));
		//��Ʒ���;product_code;varchar
		data.setProduct_code(resultSet->getString(8));
		//��Ʒ����;product_name;varchar
		data.setProduct_name(resultSet->getString(9));
		//����ͺ�;product_spc;varchar
		data.setProduct_spc(resultSet->getString(10));
		//��λ;unit_of_measure;varchar
		data.setUnit_of_measure(resultSet->getString(11));
		//��������������������;quantity;double
		data.setQuantity(resultSet->getDouble(12));
		//��������;request_date;datetime
		data.setRequest_date(resultSet->getString(13));
		//���κ�;batch_code;varchar
		data.setBatch_code(resultSet->getString(14));
		//�ͻ�����;client_code;varchar
		data.setClient_code(resultSet->getString(15));
		//�ͻ�����;client_name;varchar
		data.setClient_name(resultSet->getString(16));
		//��Ӧ�̱���;vendor_code;varchar
		data.setVendor_code(resultSet->getString(17));
		//��Ӧ������;vendor_name;varchar
		data.setVendor_name(resultSet->getString(18));
		//��ע;remark;varchar
		data.setRemark(resultSet->getString(19));
		return data;
	}
};


#endif // !_PRODWORKORDER_MAPPER_