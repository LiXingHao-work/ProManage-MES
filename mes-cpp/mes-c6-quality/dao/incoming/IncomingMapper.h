#pragma once
#ifndef _INCOMING_MAPPER_
#define _INCOMING_MAPPER_

#include "Mapper.h"
#include "../../domain/do/incoming/IncomingDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class IncomingMapper : public Mapper<IncomingDO>
{
public:
	IncomingDO mapper(ResultSet* resultSet) const override
	{
		IncomingDO data;
		data.setIncomingCode(resultSet->getString(1));
		data.setVendorCode(resultSet->getString(2));
		data.setVendorName(resultSet->getString(3));
		data.setVendorBatch(resultSet->getString(4));
		return data;
	}
};

#endif // !_INCOMING_MAPPER_