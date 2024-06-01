#pragma once
#ifndef _RELATEPRO_SERVICE_
#define _RELATEPRO_SERVICE_
#include <list>

#include "domain/dto/process/RelateProDTO.h"


/**
 * ������Ʒ���+�޸ķ���ʵ�֣���ʾ������ʾ������ʵ��
 */
class RelateProService
{
public:
	// ��ӹ�����Ʒ
	uint64_t saveData(const AddRelateProDTO::Wrapper& dto);
	// �޸Ĺ�����Ʒ
	bool updateData(const ModRelateProDTO::Wrapper& dto);
	// ɾ��������Ʒ
	bool removeData(uint64_t id);
	// ��ҳ��ѯ��������
	ExportRelateProDTO::Wrapper listAll(const uint64_t& id);
};

#endif // !_RELATEPRO_SERVICE_

