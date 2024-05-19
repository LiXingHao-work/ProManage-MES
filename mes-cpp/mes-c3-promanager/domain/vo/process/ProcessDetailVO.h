#pragma once
#ifndef _PROCESSDETAIL_VO_
#define _PROCESSDETAIL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProcessListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessDetailJsonVO : public JsonVO<ProcessDTO::Wrapper> {
	DTO_INIT(ProcessDetailJsonVO, JsonVO<ProcessDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
