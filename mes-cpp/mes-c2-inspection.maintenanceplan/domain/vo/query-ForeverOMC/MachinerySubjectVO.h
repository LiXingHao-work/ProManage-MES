#ifndef _MACHINERY_SUBJECT_VO_
#define _MACHINERY_SUBJECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/machinerySubjectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����豸�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachinerySubjectJsonVO : public JsonVO<MachinerySubjectDTO::Wrapper> {
	DTO_INIT(MachinerySubjectJsonVO, JsonVO<MachinerySubjectDTO::Wrapper>);
};

/**
* ���/�����豸�б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachinerySubjectPageJsonVO : public JsonVO<MachinerySubjectPageDTO::Wrapper> {
	DTO_INIT(MachinerySubjectPageJsonVO, JsonVO<MachinerySubjectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_SUBJECT_VO_