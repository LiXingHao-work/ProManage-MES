#pragma once
#ifndef _RELATEPRO_SERVICE_
#define _RELATEPRO_SERVICE_
#include <list>

#include "domain/dto/process/relateproDTO.h"


/**
 * ������Ʒ���+�޸ķ���ʵ�֣���ʾ������ʾ������ʵ��
 */
class RelateProService
{
public:
	// ��������
	uint64_t saveData(const AddRelateProDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ModRelateProDTO::Wrapper& dto);
};

#endif // !_RELATEPRO_SERVICE_

