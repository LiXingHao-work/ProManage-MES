#pragma once

#ifndef _OASL_VO_
#define _OASL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/AwaitInspection/OaslDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ӧ���ͻ��˵�Json����
 */
class OaslJsonVO : public JsonVO<OaslDTO::Wrapper> {
public:
    DTO_INIT(OaslJsonVO, JsonVO<OaslDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OaslPageJsonVO : public JsonVO<OaslPageDTO::Wrapper> {
public:
    DTO_INIT(OaslPageJsonVO, JsonVO<OaslPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
