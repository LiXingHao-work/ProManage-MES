/*

ReturnPageDTO::Wrapper listAll(const ReturnQuery::Wrapper& query)
{

}
// ��ѯ��һ��������
ReturnDetailDTO::Wrapper getDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{

}
// ���������
uint64_t saveData(const ReturnAdd::Wrapper& dto)
{

}
*/
#include "stdafx.h"
#include "ReturnService.h"
#include "../../domain/do/return/ReturnDO.h"
// #include "../../dao/return/ReturnDAO.h"

//ReturnPageDTO::Wrapper ReturnService::listAll(const ReturnQuery::Wrapper& query)
//{
//	// �������ض���
//	auto pages = ReturnPageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// ��ѯ����������
//	// ReturnDAO dao;	//daoδ���� ��ReturnController������������ṩ��ѯ���
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// ��ҳ��ѯ����
//	pages->total = count;
//	pages->calcPages();
//	list<ReturnDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (ReturnDO sub : result)
//	{
//		auto dto = ReturnDTO::createShared();
//		// 		dto->id = sub.getId();
//		// 		dto->name = sub.getName();
//		// 		dto->sex = sub.getSex();
//		// 		dto->age = sub.getAge();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
//			pages->addData(dto);
//
//	}
//	return pages;
//}
//
//uint64_t ReturnService::saveData(const ReturnDTO::Wrapper& dto)
//{
//	// ��װDO����
//	ReturnDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
//		// ִ���������
//		ReturnDAO dao;
//	return dao.insert(data);
//}
//
//bool ReturnService::updateData(const ReturnDTO::Wrapper& dto)
//{
//	// ��װDO����
//	ReturnDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id);
//	// ִ�������޸�
//	// ReturnDAO dao; //ͬ��
//	return dao.update(data) == 1;
//}
//
//bool ReturnService::removeData(uint64_t id)
//{
//	ReturnDAO dao;
//	return dao.deleteById(id) == 1;
//}
