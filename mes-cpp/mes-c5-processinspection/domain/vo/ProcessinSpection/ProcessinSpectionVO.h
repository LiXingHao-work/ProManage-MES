#pragma once
#ifndef _PROCESSINSPECTION_VO_
#define _PROCESSINSPECTION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProcessinSpection/ProcessinSpectionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessinSpectionJsonVO : public JsonVO<ProcessinSpectionDTO::Wrapper> {
	DTO_INIT(ProcessinSpectionJsonVO, JsonVO<ProcessinSpectionDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessinSpectionPageJsonVO : public JsonVO<ProcessinSpectionPageDTO::Wrapper> {
	DTO_INIT(ProcessinSpectionPageJsonVO, JsonVO<ProcessinSpectionPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_VO_