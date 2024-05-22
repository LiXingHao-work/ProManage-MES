#include "stdafx.h"
#include "ProcessinSpectionController.h"
//#include "../../service/sample/SampleService.h"
//#include "../ApiDeclarativeServicesHelper.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/processinspection/ProcessInspectionService.h"

ProcessinSpectionPageJsonVO::Wrapper ProcessinSpectionController::execProcessinSpection(const ProcessinSpectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}

Uint64JsonVO::Wrapper ProcessinSpectionController::execRemoveProcessinSpection(const List<UInt64>& ids)
{
	return Uint64JsonVO::Wrapper();
}

StringJsonVO::Wrapper ProcessinSpectionController::execExportProcessinSpection(const oatpp::List<UInt64>& ids)
{
	return StringJsonVO::Wrapper();
}

ProcessinSpectionJsonVO::Wrapper ProcessinSpectionController::execQueryInspectionDetails(const ProcessinSpectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	//ProcessinSpectionService service;
	//auto result = service.getInspectionDetails(query);
	auto jvo = ProcessinSpectionJsonVO::createShared();
	//jvo->success(result);
	//jvo->success(String("test 1"));
	//jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ProcessinSpectionController::execModifyTheProcessInspection(const ProcessinSpectionDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	//auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ����һ��Service
	//ProcessInspectionService service;
	//// ִ�������޸�
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// ��Ӧ���
	//return jvo;
	return {};
}
