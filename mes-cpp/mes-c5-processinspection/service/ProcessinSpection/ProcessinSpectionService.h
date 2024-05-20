#pragma once
#ifndef _PROCESSINSPECTION_SERVICE_
#define _PROCESSINSPECTION_SERVICE_

#include <list>
#include "domain/vo/ProcessinSpection/ProcessinSpectionVO.h"
#include "domain/query/ProcessinSpection/ProcessinSpectionQuery.h"
#include "domain/dto/ProcessinSpection/ProcessinSpectionDTO.h"

class ProcessinSpectionService {
public:
	// ��ȡ���̼�������
	ProcessinSpectionDTO::Wrapper getInspectionDetails(const ProcessinSpectionQuery::Wrapper& query);
	// ȷ�ϼ��鵥
	bool confirmOrders(const ProcessinSpectionDTO::Wrapper& dto);
};


#endif // !_PROCESSINSPECTION_SERVICE_
