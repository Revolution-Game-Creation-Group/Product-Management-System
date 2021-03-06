//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : CMaterialPart.h
//  @ Date : 2007-04-10
//  @ Author : 
//
//


#if !defined(_CMATERIALPART_H)
#define _CMATERIALPART_H
#include <vector>

#include "CData.h"

using namespace std;

class CMaterialPart {
public:
	vector<COrder> m_orderList;
	vector<CShip> m_shipList;
	vector<CMaterial> m_materialList;

	bool LoadData();				/* 파일을 로드한다. */
	bool SaveData();				/* 파일을 저장한다. */
	bool AddOrder();				/* 자재주문서를 작성 */
	bool CheckOrder();				/* 자재주문서 승인 */
	void ShowOrderAll();			/* 자재 주문서 전체보기 */
	bool AddMaterial();				/* 자재정보 추가 */
	bool ModifyMaterial();			/* 자재정보 수정하기 */
	bool ShowMaterial();			/* 자재정보 개별보기 */
	void ShowMaterialAll();			/* 자재정보 전체보기 */
	void ShowShipAll();				/* 자재출하지시서 전체보기 */
	bool CheckShip();				/* 자재출하지시서 승인 */
private:
	bool LoadMaterialData();		/* 자재 정보를 로드 */
	bool LoadOrderData();			/* 자재주문지시서 및 입고지시서를 로드 */
	bool LoadShipData();			/* 자재출하지시서를 로드 */

	bool SaveMaterialData();		/* 자재 정보를 저장 */
	bool SaveOrderData();			/* 자재주문지시서 및 입고지시서를 저장 */
	bool SaveShipData();			/* 자재출하지시서를 저장 */

	bool ShowOrder(int _orderID);	/* 자재주문서 개별보기 */
	bool ShowShip(int _shipID);		/* 자재출하지시서 개별보기 */

	bool Summit();					/* 승인확인 */
};

#endif  //_CMATERIALPART_H
