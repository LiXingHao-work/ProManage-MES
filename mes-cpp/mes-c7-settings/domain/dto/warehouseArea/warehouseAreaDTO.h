#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _WAREHOUSE_AREA_DTO_
#define _WAREHOUSE_AREA_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б������,ÿ�������Ӧһ���б���
 */
class warehouseAreaListDTO : public oatpp::DTO
{
	DTO_INIT(warehouseAreaListDTO, DTO);
	////Ψһ��ʶ
	//API_DTO_FIELD(UInt64,area_id, ZH_WORDS_GETTER("warehouse-area.field.id"),true,1)
	////����,������
	//API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("warehouse-area.field.code"), true, "000");//�ɴ�Ĭ��ֵ31:03
	////����
	//API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("warehouse-area.field.name"), true,"default name");
	////���
	//API_DTO_FIELD_DEFAULT(Int32, area, ZH_WORDS_GETTER("warehouse-area.field.area"));
	////��ע
	//API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("warehouse-area.field.remark"));
	//ʹ��demo/sample��Ķ��巽ʽ
	//�������
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id){ info->description = ZH_WORDS_GETTER("warehouse.field.id"); }
	//����
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) { info->description = ZH_WORDS_GETTER("warehouse.field.code"); }
	//����
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) { info->description = ZH_WORDS_GETTER("warehouse.field.name"); }
	//���
	DTO_FIELD(Int32, area);
	DTO_FIELD_INFO(area) { info->description = ZH_WORDS_GETTER("warehouse.field.area"); }
	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) { info->description = ZH_WORDS_GETTER("warehouse.field.remark"); }
};
/**
 * ������ҳ�������
 */
class warehousePageDTO : public PageDTO<warehouseAreaListDTO::Wrapper>
{
	DTO_INIT(warehousePageDTO, PageDTO<warehouseAreaListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // 