#pragma once
#ifndef _OASL_DTO_
#define _OASL_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class OaslDTO : public oatpp::DTO
{
	DTO_INIT(OaslDTO, DTO);
	// ��ӵ��ݱ��롢�������ƺͼ�������ֶ�
	DTO_FIELD(String, documentCode);
	DTO_FIELD(String, materialName);
	DTO_FIELD(String, detectionType);
};

//��ҳ�������
class OaslPageDTO : public PageDTO<OaslDTO::Wrapper>
{
	DTO_INIT(OaslPageDTO, PageDTO<OaslDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_OASL_DTO_