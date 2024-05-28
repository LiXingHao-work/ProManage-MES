#pragma once
#ifndef _DETECTIONTEMPLATE_MAPPER_
#define _DETECTIONTEMPLATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"

// ��ȡ���ģ���б�
class DetectionTemplateMapper : public Mapper<DetectionTemplateDO> {
public:
	DetectionTemplateDO mapper(ResultSet* resultSet) const override {
		DetectionTemplateDO data;
		int i = 1;
		data.setTemplate_Id(resultSet->getUInt64(i++));
		data.setTemplate_Code(resultSet->getString(i++));
		data.setTemplate_Name(resultSet->getString(i++));
		data.setQc_Types(resultSet->getString(i++));
		data.setEnable_Flag(resultSet->getString(i++));
		return data;
	}
};

#endif // !_DETECTIONTEMPLATE_MAPPER_
