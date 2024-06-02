#include "stdafx.h"
#include "Single_Defect_Controller.h"
#include "../../service/Single_Defect/Single_Defect_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

SinglePageJsonVO::Wrapper Single_Defect_Controller::execQuerySingle(const SingleQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	Single_Defect_Service service;
	// ��ѯ����
	auto result = service.listAll_Index(query);
	// ��Ӧ���
	auto jvo = SinglePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

DefectPageJsonVO::Wrapper Single_Defect_Controller::execQueryDefect(const DefectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	Single_Defect_Service service;
	// ��ѯ����
	auto result = service.listAll_Defect(query);
	// ��Ӧ���
	auto jvo = DefectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper Single_Defect_Controller::execAddDefect(const DefectDTO::Wrapper& dto)
{
	return{};
}

Uint64JsonVO::Wrapper Single_Defect_Controller::execModifyDefect(const DefectDTO::Wrapper& dto)
{
	return{};
}

Uint64JsonVO::Wrapper Single_Defect_Controller::execRemoveDefect(const UInt64& id)
{
	return{};
}



