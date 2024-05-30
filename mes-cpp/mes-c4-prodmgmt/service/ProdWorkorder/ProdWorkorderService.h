#pragma once

#ifndef _PRODWORKORDER_SERVICE_
#define _PRODWORKORDER_SERVICE_
#include <list>
#include "../../domain/vo/ProdWorkorder/ConfirmProWorkorderVO.h"
#include "../../domain/dto/ProdWorkorder/ConfirmProWorkorderDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProdWorkorderService
{
public:
	//// ��ҳ��ѯ��������
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	//// ��������
	//uint64_t saveData(const SampleDTO::Wrapper& dto);
	//// �޸�����
	//bool updateData(const SampleDTO::Wrapper& dto);
	// ͨ��ID�����������
	bool completeData(uint64_t id);
	// ͨ��IDɾ����������
	bool removeData(uint64_t id);

	// ͨ��IDɾ����������
	bool confirmData(uint64_t id);
};

#endif // !_PROWORKORDER_SERVICE_

