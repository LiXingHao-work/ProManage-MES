#ifndef _MACHINERY_LIST_QUERY_
#define _MACHINERY_LIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)	

/*
* ���/�����豸�б��ҳ��ѯ����
*/
class MachineryListQuery : public PageQuery
{
	DTO_INIT(MachineryListQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_LIST_QUERY_