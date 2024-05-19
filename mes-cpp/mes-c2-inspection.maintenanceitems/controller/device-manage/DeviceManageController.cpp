/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "DeviceManageController.h"
#include "../../service/device-manage/DeviceManageService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper DeviceManageController::execModifyProj(const DeviceManageDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->subjectId || dto->subjectId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if (dto->enableFlag != "Y" && dto->enableFlag != "N")
	{
		//jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		jvo->init(UInt64(-1), ResultStatus(u8"only support 'Y' or 'N'", 9995));
		return jvo;
	}

	// ����һ��Service
	DeviceManageService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->subjectId);
	}
	else
	{
		jvo->fail(dto->subjectId);
	}
	// ��Ӧ���
	return jvo;
}


Uint64JsonVO::Wrapper DeviceManageController::execRemoveProj(const DeviceManageDelDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->subjectDelId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return  jvo;
	}

	// ����һ��Service
	DeviceManageService service;
	// ִ�������޸�
	if (service.removeData(dto))
	{
		jvo->init(atoi(dto->subjectDelId->c_str()), ResultStatus(u8"remove data successfully"));

	}
	else
	{

		jvo->init(atoi(dto->subjectDelId->c_str()), ResultStatus(u8"fail to remove data",9995));
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper DeviceManageController::execExportProj(const DeviceManageDelDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// ����У��
	if (!dto->subjectDelId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return  jvo;
	}

	// ����һ��Service
	DeviceManageService service;

	//����excel�ļ�
	string url = service.creatExcel(dto);
	if (url.empty())
	{
		jvo->init(atoi(dto->subjectDelId->c_str()), ResultStatus(u8"fail to export data",9995));
	}
	else
	{
		jvo->init(atoi(dto->subjectDelId->c_str()), ResultStatus(u8"export data successfully:" + url));
	}
	return jvo;
}


