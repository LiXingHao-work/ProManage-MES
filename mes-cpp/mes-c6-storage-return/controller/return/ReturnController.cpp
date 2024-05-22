#include "stdafx.h"
#include "ReturnController.h"
#include "service/return/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query, const PayloadDTO& payload)
{
	/*
	// ����һ��Service
	ReturnService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReturnPageJsonVO::createShared();
	jvo->success(result);*/
	return {};
}

ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{
	/*
	// ����һ��Service
	ReturnService service;
	// ��ѯ����
	auto result = service.getDetail(returnDetailQuery);
	// ��Ӧ���
	auto jvo = ReturnPageJsonVO::createShared();
	jvo->success(result);
	*/
	return {};
}

Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
{
	/*
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->returnId || !dto->returnName || !dto->vendorName || !dto->returndate || !dto->status)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->returnId->empty() || dto->returnName->empty() || dto->vendorName->empty() || dto->returndate->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ReturnService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	*/
	return {};
}