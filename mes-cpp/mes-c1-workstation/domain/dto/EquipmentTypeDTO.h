#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/04/11 15:00:21

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
#ifndef _EQUIPMENTTYPEDTO_H_
#define _EQUIPMENTTYPEDTO_H_

#include "../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���˵����ݴ������
 */
class EquipmentTypeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(EquipmentTypeDTO, DTO);
	// �豸���ͱ���
	API_DTO_FIELD_DEFAULT(String, equipmentTypeCode, ZH_WORDS_GETTER("equipment.equipmentDto.equipmentTypeCode"));
	// �豸��������
	API_DTO_FIELD_DEFAULT(String, equipmentTypeName, ZH_WORDS_GETTER("equipment.equipmentDto.equipmentTypeName"));
	// �Ƿ�����
	API_DTO_FIELD(Int32, isUse, ZH_WORDS_GETTER("equipment.equipmentDto.isUse"),  false, 0);
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("equipment.equipmentDto.remark"));
	// ���豸�б�
	API_DTO_FIELD(List<EquipmentTypeDTO::Wrapper>, children, ZH_WORDS_GETTER("equipment.equipmentDto.child"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<EquipmentTypeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUDTO_H_