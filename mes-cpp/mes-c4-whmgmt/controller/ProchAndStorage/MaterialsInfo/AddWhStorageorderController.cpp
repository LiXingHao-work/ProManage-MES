#include "stdafx.h"
#include "AddWhStorageorderController.h"
#include "../../ApiDeclarativeServicesHelper.h"

AddWhStorageorderVO::Wrapper AddWhStorageorderController::execAddWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto)
{
	////���巵�����ݶ���
	//auto jvo = AddWhStorageorderVO::createShared();
	////����У��
	////�ǿ�У��
	//if (!dto->batch_code || !dto->expire_date || !dto->iqc_check || !dto->iqc_code || dto->remark
	//	|| dto->iqc_id || dto->item_code || dto->warehouse_name) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	////��ЧֵУ��
	//if (!dto->batch_code->empty() || !dto->expire_date->empty() || !dto->iqc_check->empty() || !dto->iqc_code->empty() || dto->remark->empty()
	//	|| dto->iqc_id  || dto->item_code->empty() || dto->warehouse_name->empty()) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	////����һ��Service


	return {};
}