#pragma once
#ifndef _SINGLE_VO_
#define _SINGLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Single/SingleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SingleJsonVO : public JsonVO<SingleDTO::Wrapper> {
	DTO_INIT(SingleJsonVO, JsonVO<SingleDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SinglePageJsonVO : public JsonVO<SinglePageDTO::Wrapper> {
	DTO_INIT(SinglePageJsonVO, JsonVO<SinglePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SINGLE_VO_
