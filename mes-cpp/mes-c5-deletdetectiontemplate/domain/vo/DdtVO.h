#pragma once
#ifndef _DDT_VO_
#define _DDT_VO_

#include "domain/GlobalInclude.h"
#include "domain/dto/DdtDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DdtJsonVO : public JsonVO<DdtDTO::Wrapper> {
	DTO_INIT(DdtJsonVO, JsonVO<DdtDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DdtPageJsonVO : public JsonVO<DdtPageDTO::Wrapper> {
	DTO_INIT(DdtPageJsonVO, JsonVO<DdtPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DDT_VO_
