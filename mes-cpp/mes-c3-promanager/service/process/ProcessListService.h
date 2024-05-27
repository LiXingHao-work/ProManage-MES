#pragma once
#ifndef _PROCESSLIST_SERVICE_
#define _PROCESSLIST_SERVICE_
#include <list>
#include "domain/vo/process/ProcessListVO.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProcessListService
{
public:
	// ��ҳ��ѯ�����б�����
	ProcessListDTO::Wrapper listAll(const ProcessListQuery::Wrapper& query);
	// ͨ��id��ѯ��������
	ProcessDTO::Wrapper getById(const ProcessDetailQuery::Wrapper& query);
	// ��ӹ��� ��������
	uint64_t saveProcessAdd(const ProcessAddDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_
