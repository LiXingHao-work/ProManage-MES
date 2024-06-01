#pragma once
#ifndef _RawMaterialOp_SERVICE_
#define _RawMaterialOp_SERVICE_
#include <list>
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"
#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/do/RawMaterialOp/RawMaterialOpDO.h"

/**
 * ��������������Ϣ�ķ���ӿ�
 */
class RawMaterialOpService
{
public:

	// ��������
	uint64_t saveData(const RawMaterialOpDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const RawMaterialOpDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);


	// ��ҳ��ѯ��������
	RawMaterialOpPageDTO::Wrapper listAll(const RawMaterialOpQuery::Wrapper& query);

};

#endif // !_RawMaterialOp_SERVICE_
