#pragma once
#ifndef _PROCESSPRO_SERVICE_
#define _PROCESSPRO_SERVICE_
#include <list>
#include "domain/vo/process/ComProVO.h"
#include "domain/query/process/ComProQuery.h"
#include "domain/dto/process/ComProDTO.h"

/**
 * ɾ����ɹ����service
 */
class ComProService
{
public:

	// ͨ��IDɾ������
	bool removeData(list<uint64_t> id);
};

#endif // !_SAMPLE_SERVICE_