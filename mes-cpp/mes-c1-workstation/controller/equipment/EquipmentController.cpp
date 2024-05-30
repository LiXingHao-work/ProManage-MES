#include "stdafx.h"
#include "EquipmentController.h"
#include "../../domain/vo/equipment/EquipmentTypeTreeVO.h"
#include "domain/do/equipment/EquipmentTypeDO.h"
#include "tree/TreeUtil.h"
#include "service/equipment/TreeEquipmentTypeMapper.h"
#include "service/equipment/EquipmentService.h"

EquipmentTypeTreeVO::Wrapper EquipmentController::executeGetEquipmentTypeTree(const PayloadDTO& payload)
{
	// ����һ��JsonVO����
	auto vo = EquipmentTypeTreeVO::createShared();
	// ����ģ���豸�������ݣ�������Ӧ��Դ�����ݿ⣩
	list<EquipmentTypeDO> listData;
	listData.push_back(EquipmentTypeDO("1", "M_TYPE_000", u8"ϵͳ����", '0', "/sm", ""));
	listData.push_back(EquipmentTypeDO("2", "M_TYPE_001", u8"�û�����", '0', "/sm/um", "1"));
	listData.push_back(EquipmentTypeDO("3", "M_TYPE_002", u8"��ɫ����", '0', "/sm/rm", "1"));
	listData.push_back(EquipmentTypeDO("4", "M_TYPE_003", u8"�˵�����", '0', "/sm/mm", "1"));
	listData.push_back(EquipmentTypeDO("5", "M_TYPE_004", u8"��������", '1', "/om", ""));
	listData.push_back(EquipmentTypeDO("6", "M_TYPE_005", u8"��ⶩ��", '1', "/om/em", "5"));
	listData.push_back(EquipmentTypeDO("7", "M_TYPE_006", u8"���ⶩ��", '1', "/om/om", "5"));
	listData.push_back(EquipmentTypeDO("8", "M_TYPE_007", u8"���۶���", '1', "/om/sm", "5"));
	listData.push_back(EquipmentTypeDO("9", "M_TYPE_008", u8"����ͳ��", '1', "/om/sm/t1", "8"));
	listData.push_back(EquipmentTypeDO("10", "M_TYPE_009", u8"��������", '1', "/om/sm/t2", "8"));
	// ת��Ϊ���νṹ
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<EquipmentTypeDO>(listData, TreeEquipmentMapper());
	// �����ڵ�洢���б���
	for (auto one : res)
	{
		vo->data->push_back(EquipmentTypeDTO::Wrapper(dynamic_pointer_cast<EquipmentTypeDTO>(one), EquipmentTypeDTO::Wrapper::Class::getType()));
	}
	return vo;
}

EquipmentPageVO::Wrapper EquipmentController::execGetEquipmentList(const EquipmentQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	EquipmentService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EquipmentPageVO::createShared();
	jvo->success(result);
	return jvo;
}


