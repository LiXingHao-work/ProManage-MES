#pragma once

#ifndef _SET_SERVICE_
#define _SET_SERVICE_
#include <list>
#include "domain/vo/set/SetProListVO.h"
#include "domain/query/set/SetProListQuery.h"
#include "domain/query/set/ProListQuery.h"
#include "domain/dto/set/SetProAddDTO.h"
#include "domain/dto/set/SetProListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SetService
{
public:
	// ��ҳ��ѯ��������
	SetProListPageDTO::Wrapper listAll(const SetProListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const SetProAddTableDTO::Wrapper& dto);
	uint64_t saveStepData(const SetProListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const SetProAddTableDTO::Wrapper& dto);


#endif // !_SET_SERVICE_

};