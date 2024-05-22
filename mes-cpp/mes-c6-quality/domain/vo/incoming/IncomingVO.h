#pragma once

#ifndef _INCOMING_VO_
#define _INCOMING_VO_

#include "../../GlobalInclude.h"
#include"../../dto/incoming/IncomingDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�����ϼ��鵥�б���ʾVO
 */
//class IncomingTableJsonVO : public oatpp::DTO
//{
//	DTO_INIT(, DTO);
//
//};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class IncomingJsonVO : public JsonVO<IncomingDTO::Wrapper> {
	DTO_INIT(IncomingJsonVO, JsonVO<IncomingDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class IncomingPageJsonVO : public JsonVO<IncomingPageDTO::Wrapper> {
	DTO_INIT(IncomingPageJsonVO, JsonVO<IncomingPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INCOMING_VO_