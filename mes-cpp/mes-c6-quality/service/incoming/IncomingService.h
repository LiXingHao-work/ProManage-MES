#pragma once

#ifndef _INCOMING_SERVICE_
#define _INCOMING_SERVICE_
#include <list>
#include"domain/dto/incoming/IncomingDTO.h"
#include"domain/query/incoming/IncomingQuery.h"
#include"domain/vo/incoming/IncomingVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class IncomingService
{
public:
	// ��ҳ��ѯ��������
	IncomingPageDTO::Wrapper listAll(const IncomingQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const IncomingDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const IncomingDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_INCOMING_SERVICE_

