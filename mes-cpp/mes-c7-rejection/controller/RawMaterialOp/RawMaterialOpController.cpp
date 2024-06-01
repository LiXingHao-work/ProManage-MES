#include "stdafx.h"
#include "RawMaterialOpController.h"
#include "../../service/RawMaterialOpService/RawMaterialOpService.h"
#include "../ApiDeclarativeServicesHelper.h"



Uint64JsonVO::Wrapper RawMaterialOpController::execRemoveRawMaterialOp(const UInt64& id)
{
	return Uint64JsonVO::Wrapper();
}

Uint64JsonVO::Wrapper RawMaterialOpController::execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}


RawMaterialOpPageJsonVO::Wrapper RawMaterialOpController::execQueryRawMaterialOp(const RawMaterialOpQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	RawMaterialOpService service;
	// ��ѯ����
	auto result = service.listAll(query);
	//// ��Ӧ���
	auto jvo = RawMaterialOpPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
