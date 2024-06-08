#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/17

*/
#ifndef _WORKFIXTURETYPELISTVO_H_
#define _WORKFIXTURETYPELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/WorkFixture/WorkFixtureTypeListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WorkFixtureTypeListPageJsonVO : public JsonVO<WorkFixtureTypeListPageDTO::Wrapper>
{
	DTO_INIT(WorkFixtureTypeListPageJsonVO, JsonVO<WorkFixtureTypeListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKFIXTURETYPELISTVO_H_