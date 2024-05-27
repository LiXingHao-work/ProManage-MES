///*
//* 
//*/
//#include "stdafx.h"
////#include "SampleService.h"
////#include "../../dao/sample/SampleDAO.h"
//#include "Dv_check_planService.h"
//#include "../../dao/dv_check_plan/Dv_check_planDAO.h"
//#include "../../../mes-c2-inspection.maintenanceplan/Macros.h"
//#include <cstdint>//debug
//MachineryPlanPageDTO::Wrapper Dv_check_planService::listAll(const MachineryPlanQuery::Wrapper& query)
//{
//	// �������ض���
//	auto pages = MachineryPlanPageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// ��ѯ����������
//	Dv_check_planDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// ��ҳ��ѯ����
//	pages->total = count;
//	pages->calcPages();
//	list<Dv_check_planDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (Dv_check_planDO sub : result)
//	{
//		auto dto = MachineryPlanDTO::createShared();
//		// 		dto->id = sub.getId();
//		// 		dto->name = sub.getName();
//		// 		dto->sex = sub.getSex();
//		// 		dto->age = sub.getAge();
//		// abf������Ҫ�ı�DTO���͵ı���dto��ʹ��DO��get����ȡֵ����ֵ
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, plan_id, Plan_id, plan_code, Plan_code,
//			plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date,
//			end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count,
//			status, Status)
//
//		//ע�͵�����չ�������
//		//dto->plan_id = sub.getPlan_id(); dto->plan_code = sub.getPlan_code(); dto->plan_name = sub.getPlan_name(); dto->plan_type = sub.getPlan_type(); dto->start_date = sub.getStart_date(); dto->end_date = sub.getEnd_date(); dto->cycle_type = sub.getCycle_type(); 
//		//dto->cycle_count = sub.getCycle_count(); dto->status = sub.getStatus();
//
//			pages->addData(dto);
//
//	}
//	return pages;
//}
//
//
///*
//MachineryPlanDetailsDTO::Wrapper Dv_check_planService::listAll(const MachineryPlanDetailsQuery::Wrapper& query)
//{
//	// �������ض���
//	auto pages = MachineryPlanDetailsDTO::createShared();
//
//
//	// ��ѯ����������
//	Dv_check_planDAO dao;
//	//uint64_t count = dao.count(query);
//	//if (count <= 0)
//	//{
//	//	return pages;
//	//}
//	// ��ҳ��ѯ����
//
//	list<Dv_check_planDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (Dv_check_planDO sub : result)
//	{
//		auto dto = MachineryPlanDTO::createShared();
//		//չ��ת����
//		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, plan_id, Plan_id, plan_code, Plan_code,
//		//	plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date,
//		//	end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count,
//		//	status, Status)
//		dto->plan_id = sub.getPlan_id();
//		dto->plan_code = sub.getPlan_code();
//		dto->plan_name = sub.getPlan_name(); 
//		dto->plan_type = sub.getPlan_type();
//		dto->start_date = sub.getStart_date();
//		dto->end_date = sub.getEnd_date();
//		dto->cycle_type = sub.getCycle_type();
//		dto->cycle_count = sub.getCycle_count();
//		dto->status = sub.getStatus();
//		pages->addData(dto);
//	}
//	return pages;
//}
//*/
////--------
//
///*
//DeletePlanQueryDTO::Wrapper Dv_check_planService::listAll(const DeletePlanQuery::Wrapper& query)
//{
//	// �������ض���
//	auto pages = MachineryPlanDetailsDTO::createShared();
//
//
//	// ��ѯ����������
//	Dv_check_planDAO dao;
//	//uint64_t count = dao.count(query);
//	//if (count <= 0)
//	//{
//	//	return pages;
//	//}
//	// ��ҳ��ѯ����
//
//	list<Dv_check_planDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (Dv_check_planDO sub : result)
//	{
//		auto dto = MachineryPlanDTO::createShared();
//		//չ��ת����
//		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, plan_id, Plan_id, plan_code, Plan_code,
//		//	plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date,
//		//	end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count,
//		//	status, Status)
//		dto->plan_id = sub.getPlan_id();
//		dto->plan_code = sub.getPlan_code();
//		dto->plan_name = sub.getPlan_name();
//		dto->plan_type = sub.getPlan_type();
//		dto->start_date = sub.getStart_date();
//		dto->end_date = sub.getEnd_date();
//		dto->cycle_type = sub.getCycle_type();
//		dto->cycle_count = sub.getCycle_count();
//		dto->status = sub.getStatus();
//		pages->addData(dto);
//	}
//	return pages;
//}
//*/
//
////----
///*
//uint64_t SampleService::saveData(const MachineryPlanDTO::Wrapper& dto)
//{
//	// ��װDO����
//	Dv_check_planDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
//		// ִ���������
//		Dv_check_planDAO dao;
//	return dao.insert(data);
//}
//
//bool SampleService::updateData(const MachineryPlanDTO::Wrapper& dto)
//{
//	// ��װDO����
//	Dv_check_planDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id);
//	//data.setName(dto->name.getValue({})); data.setSex(dto->sex.getValue({})); data.setAge(dto->age.getValue({})); data.setId(dto->id.getValue({}));;
//
//	// ִ�������޸�
//	Dv_check_planDAO dao;
//	return dao.update(data) == 1;
//}
//*/
//bool Dv_check_planService::removeData(uint64_t id)
//{
//	Dv_check_planDAO dao;
//	return dao.deleteById(id) == 1;
//}
