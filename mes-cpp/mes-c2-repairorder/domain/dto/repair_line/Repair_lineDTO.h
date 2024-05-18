#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/5/18 17:12:31

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _REPAIR_LINE_DTO_
#define _REPAIR_LINE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ά�����ݴ������
 */
class Repair_lineDTO : public oatpp::DTO
{
    DTO_INIT(Repair_lineDTO, DTO);

    // ά�޵�ID(Ψһ��ʶ)
    API_DTO_FIELD(UInt64, repairId, ZH_WORDS_GETTER("repair_line.query.fields.repair_id"), true, 0LLU);

    //��Ŀ����
    API_DTO_FIELD(String, projectName, ZH_WORDS_GETTER("repair_line.query.fields.projectName"), true, "");

    //��������
    API_DTO_FIELD(String, errorInstance, ZH_WORDS_GETTER("repair_line.query.fields.errorInstance"), true, "");

    //����������Դ
    API_DTO_FIELD(String, errorSource, ZH_WORDS_GETTER("repair_line.query.fields.errorSource"), true, "");

    //ά�����
    API_DTO_FIELD(String, repairStatus, ZH_WORDS_GETTER("repair_line.query.fields.repairStatus"), true, "");

};

/**
 * ά�����ݷ�ҳ�������
 */
class Repair_linePageDTO : public PageDTO<Repair_lineDTO::Wrapper>
{
    DTO_INIT(Repair_linePageDTO, PageDTO<Repair_lineDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIR_LINE_DTO_