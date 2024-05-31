#include "stdafx.h"
#include "SetController.h"
#include "../../service/set/ProcessExportService.h"
#include "../../service/set/ContentService.h"
#include "../../service/set/SetService.h"
#include "Macros.h"
#include "ExcelComponent.h"

// ע�⣺�õ�FastDfs�ĵط���Ҫ������ڵ���DFS��ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 1 ��������
StringJsonVO::Wrapper SetController::execProcessExport(const ProcessExportQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessExportService service;
	// ��ѯ����
	list<SetProAddTableDTO::Wrapper> result = service.listAll(query);
	std::vector<std::vector<std::string>> data;

	// DTO����ת��Ϊvector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(sub->processCode);
		tmp.emplace_back(sub->processName);
		tmp.emplace_back(sub->attention);
		tmp.emplace_back(sub->enableFlag);
		data.emplace_back(tmp);
	}

	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1"),
		ZH_WORDS_GETTER("excel.header.h2"),
		ZH_WORDS_GETTER("excel.header.h3"),
		ZH_WORDS_GETTER("excel.header.h4"),
		});

	// ���浽�ļ�
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// �ļ��ϴ�---����û���ú궨��ȥд
	//// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	//NacosClient ns("192.168.186.137:8848", "4833404f-4b82-462e-889a-3c508160c6b4");
	//// DFS�ͻ������Ӷ���
	//FastDfsClient* client = nullptr;
	//// �ļ����ص�ַǰ׺
	//std::string urlPrefix = "";
	//// ����һ���ϴ��ļ����ļ���
	//std::string filename = "";
	//// ����һ����ʱ�������ڴ洢�ϴ��ϴ��ɹ�����ļ�field����
	//std::string tmpField = "";
	//// ��ȡ�������ݽڵ�
	//auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//// +FastDFS�ͻ�����������
	//std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//std::string ip = ipPort.substr(0, ipPort.find(":"));
	//int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//// ���ÿͻ��˶���
	//client = new FastDfsClient(ip, port);
	//// ����һ���ļ��ϴ���ַ
	//filename = "./public/excel/process.xlsx";
	//// ����urlǰ׺
	//urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	//tmpField = client->uploadFile(filename);
	//// ����ļ����ص�ַ
	//std::string downloadUrl = urlPrefix + tmpField;
	//std::cout << "download url: " << downloadUrl << std::endl;

	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// ����һ��fastdfs����ǰ׺
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// ��ȡ�ļ���׺��
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// �ϴ��ļ�
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}
// 2 ��ӹ���
Uint64JsonVO::Wrapper SetController::execAddSet(const SetProAddTableDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->processCode || !dto->processName || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->processCode->empty() || dto->processName->empty() || dto->enableFlag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SetService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;

}
// 3 �޸Ĺ���
Uint64JsonVO::Wrapper SetController::execModifySet(const SetProAddTableDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->processId || dto->processId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SetService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->processId);
	}
	else
	{
		jvo->fail(dto->processId);
	}
	// ��Ӧ���
	return jvo;
}
// 4 ��ȡ�������б�
SetProListPageJsonVO::Wrapper SetController::execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload) {
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = SetProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 5 ��ӹ�����
Uint64JsonVO::Wrapper SetController::execAddStepSet(const SetProListDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->contentId || !dto->processId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->contentId < 0 || dto->processId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SetService service;
	// ִ����������
	uint64_t id = service.saveStepData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
// 6 ��ȡ�����б�
ProListPageJsonVO::Wrapper SetController::execQueryProList(const ProListQuery::Wrapper& query)
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.listAllForProcess(query);
	// ��Ӧ���
	auto jvo = ProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProListPageJsonVO::Wrapper();
}
// 7 ��ȡ���������б�
ProNameListJsonVO::Wrapper SetController::execQueryProNameList()
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.getProcessNameList();
	// ��Ӧ���
	return result;
}
// 8 ��ȡ��������
ProDetailJsonVO::Wrapper SetController::execQueryProDetail(const ProDetailQuery::Wrapper& query)
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.getProcessDetail(query);
	// ��Ӧ���
	auto jvo = ProDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProDetailJsonVO::Wrapper();
}
//9 �޸Ĺ�����
Uint64JsonVO::Wrapper SetController::execModifyStepSet(const SetProListDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->contentId || dto->contentId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
	if (service.updateData(dto)) {
		jvo->success(dto->contentId);
	}
	else
	{
		jvo->fail(dto->contentId);
	}
	return jvo;
}
//10 ɾ��������
Uint64JsonVO::Wrapper SetController::execDeleteStepSet(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ContentService service;
	// ִ������ɾ��
	if (service.removeStep(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
// 11 ����������
StringJsonVO::Wrapper SetController::execExportStepSet(const SetStepExportQuery::Wrapper& query)
{
	//// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//// ����һ��Service
	//ContentService service;
	//// ��ѯ����
	//auto result = service.listAll(query);
	//if (!result) {
	//	jvo->init(String(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//ExcelComponent excelComponent;

	//excelComponent.setColWidth(20.0); 
	//excelComponent.setRowHeight(15.0); 

	//std::vector<std::vector<std::string>> data;
	//data.push_back({ "ContentId", "OrderNum", "ContentText", "Device", "Material", "DocUrl", "Remark" });
	////��data���������
	//// 
	//// д�����ݵ� Excel �ļ�
	//excelComponent.writeVectorToFile(filePath, "Steps", data);

	//// ���سɹ����
	//jvo->success(result->contentText);
	return jvo;
}

// 12 ɾ������
Uint64JsonVO::Wrapper SetController::execDeleteSet(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}