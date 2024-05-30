#include "stdafx.h"
#include "DeviceResourceController.h"
#include "domain/do/deviceResource/DeviceResourceDO.h"
#include "service/deviceResource/DeviceResourceService.h"



DeviceResourcePageVO::Wrapper DeviceResourceController::execGetDeviceResourceList( const PayloadDTO& payload)
{
	// ����һ��Service
	DeviceResourceService service;
	// ��ѯ����
	auto result = service.listAll();
	// ��Ӧ���
	auto jvo = DeviceResourcePageVO::createShared();
	jvo->success(result);
	return jvo;
}


