#include "stdafx.h"
#include "ProcessinSpectionController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/processinspection/ProcessInspectionService.h"
#include "../../dao/processinspection/ProcessInspectionDAO.h"

ProcessinSpectionQueryPageJsonVO::Wrapper ProcessinSpectionController::execProcessinSpection(const ProcessinSpectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ProcessInspectionService service;
	//ִ�в�ѯ
	auto result = service.listAll(query);
	auto vo = ProcessinSpectionQueryPageJsonVO::createShared();
	//��QueryPageDTOװ��vo��
	vo->success(result);
	return vo;
}

Uint64JsonVO::Wrapper ProcessinSpectionController::execRemoveProcessinSpection(const List<UInt64>& ids)
{
	ProcessInspectionService service;
	//��ѯ�Ƿ�ÿһ��id������,���ϵĲ�ѯ,
	int flag = 0;
	auto result = Uint64JsonVO::createShared();
	for (auto i = ids->begin(); i != ids->end(); ++i) {
		auto x = (*i).getValue(0);
		//��������
		if (x < 0 || !x) {
			if(!flag)
				result->init(UInt64(-1), RS_PARAMS_INVALID);
			flag = 1;
		}
		else {
			//ɾ��ʧ��
			if (!service.remove(x)) {
				if (!flag)
					result->init(UInt64(-1), RS_FAIL);
				flag = 1;
			}
		}
	}
	if(!flag)
		result->init(UInt64(1), RS_SUCCESS);
	return result;
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

ProcessinSpectionPageJsonVO::Wrapper ProcessinSpectionController::execAddProcessInspection(const ProcessinSpectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}
