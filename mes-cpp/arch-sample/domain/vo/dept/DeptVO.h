#pragma once
#ifndef _DEPTVO_H_
#define _DEPTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/dept/DeptDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//����һ�������б���ʾVO
class DeptTableJsonVO : public JsonVO<DeptTableDTO::Wrapper>
{
	// �����ʼ��
	DTO_INIT(DeptTableJsonVO, JsonVO<DeptTableDTO::Wrapper>);
	
public:
	DeptTableJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
