#include "stdafx.h"
#include "IncomingController.h"
#include "../../service/incoming/IncomingService.h"
#include "../ApiDeclarativeServicesHelper.h"

IncomingPageJsonVO::Wrapper IncomingController::execQueryIncoming(const IncomingQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	IncomingService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = IncomingPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//Uint64JsonVO::Wrapper SampleController::execAddSample(const SampleDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->age || !dto->name || !dto->sex)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	SampleService service;
//	// ִ����������
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//��Ӧ���
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper SampleController::execModifySample(const SampleDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->id || dto->id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	SampleService service;
//	// ִ�������޸�
//	if (service.updateData(dto)) {
//		jvo->success(dto->id);
//	}
//	else
//	{
//		jvo->fail(dto->id);
//	}
//	// ��Ӧ���
//	return jvo;
//}
