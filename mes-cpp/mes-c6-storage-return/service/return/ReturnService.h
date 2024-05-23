#pragma once
#ifndef _RETURN_SERVICE_
#define _RETURN_SERVICE_
#include <list>
#include "domain/vo/return/ReturnVO.h"
#include "domain/query/return/ReturnQuery.h"
#include "domain/dto/return/ReturnDTO.h"

/**
 * �˻�������ط���
 */
class ReturnService
{
public:
	// ��ҳ��ѯ��������
	ReturnPageDTO::Wrapper listAll(const ReturnQuery::Wrapper& query);
	// ��ѯ��һ��������
	ReturnDetailDTO::Wrapper getDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery);
	// ���������
	uint64_t saveData(const ReturnAdd::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_
