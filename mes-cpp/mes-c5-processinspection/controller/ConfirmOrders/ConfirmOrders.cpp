#include "stdafx.h"
#include "ConfirmOrders.h"
//#include "../../service/ProcessinSpection/ProcessinSpectionService.h"
#include "../ApiDeclarativeServicesHelper.h"


// TODO: ��ɼ��鵥�����������ݿ�����
Uint64JsonVO::Wrapper ConfirmOrdersController::execConfirmOrders(const ProcessinSpectionDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	//jvo->success(UInt64(1));
	return jvo;

}
