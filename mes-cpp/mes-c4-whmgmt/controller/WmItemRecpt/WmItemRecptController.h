#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xinye
 @Date: 2024/5/22 23:00:00

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

#ifndef _WM_ITEM_RECPT_CONTROLLER_
#define _WM_ITEM_RECPT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/WmItemRecpt/WmItemRecptDO.h"   
#include "domain/dto/WmItemRecpt/WmItemRecptDTO.h"
#include "domain/vo/WmItemRecpt/WmItemRecptVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ������ⵥ����������ʾ�����ӿڵ�ʹ��
 */
class WmItemRecptController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
    // 2 ����������������
    API_ACCESS_DECLARE(WmItemRecptController);
    // 3 ����ӿ�
public:
    // 3.1 �����޸Ľӿ�����
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("wm_item_recpt.put.summary"), modifyWmItemRecpt, Uint64JsonVO::Wrapper);
    // 3.2 �����޸Ľӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/WmItemRecpt", modifyWmItemRecpt, BODY_DTO(WmItemRecptDTO::Wrapper, dto), execModifyWmItemRecpt(dto));


private:
    // 3.3 ��ʾ�޸�����
    Uint64JsonVO::Wrapper execModifyWmItemRecpt(const WmItemRecptDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WM_ITEM_RECPT_CONTROLLER_
