#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _WORKFIXTURETYPENAMELISTVO_H_
#define _WORKFIXTURETYPENAMELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/WorkFixture/WorkFixtureTypeNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WorkFixtureTypeNameListJsonVO : public JsonVO<WorkFixtureTypeNameListDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeNameListJsonVO, JsonVO<WorkFixtureTypeNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKFIXTURETYPENAMELISTVO_H_