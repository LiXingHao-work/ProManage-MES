#include "stdafx.h"
#include "ComProService.h"
#include "../../mes-c3-promanager/dao/process/ProcessDAO.h"

/**
 * ɾ����ɹ����service
 */
bool ComProService::removeData(list<uint64_t> id)
{
	ProcessDAO dao;
	if (dao.deleteById(id)) {
		return true;
	}
	else {
		return false;
	}
}