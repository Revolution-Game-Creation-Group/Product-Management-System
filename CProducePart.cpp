//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : CProducePart.cpp
//  @ Date : 2007-04-10
//  @ Author : 
//
//


#include "CProducePart.h"
#include "CData.h"

bool CProducePart::LoadData() 
{
	if(!LoadMaterialData())
		return false;
	if(!LoadShipData())
		return false;
	return true;
}

bool CProducePart::SaveData() 
{
	if(!SaveShipData())
		return false;
	return true;
}

void CProducePart::ShowMaterialAll() 
{
	printf("<< 자재정보 전체보기 >>\n");
	printf("자재ID\t자재종류\t재고량\n");
	for(int i = 0; i < (int)m_materialList.size(); i++)
	{
		printf("%3d\t",m_materialList[i].m_iMaterialID);
		printf("%s\t\t",m_materialList[i].m_strMaterialType.data());
		printf("%.2f\n",m_materialList[i].m_fStockAmount);
	}
}

bool CProducePart::AddShip()
{
	CShip ship;

	printf("<< 자재출하지시서 입력 >>\n");
	ship.m_iShipID = (int)m_shipList.size();
	printf("자재출하지시서ID : %d\n",ship.m_iShipID);
	printf("자재ID : ");								
	scanf("%d",&(ship.m_iMaterialID));

	printf("자재출하량(KG) : ");
	scanf("%f",&(ship.m_fShipAmount));
	printf("출하예정일(YYYYMMDD) : ");
	char shipDay[20];
	scanf("%d",shipDay);
	ship.m_dateShipDay = shipDay;
	printf("입력일(YYYYMMDD) : ");
	char inputDay[20];
	scanf("%d",inputDay);
	ship.m_dateInputDay = inputDay;

	ship.m_bChecked = false;
	ship.m_dateInputDay = "";
	m_shipList.push_back(ship);

	return true;
}

bool CProducePart::LoadMaterialData()
{
	FILE* file = NULL;

	if(fopen_s( &file, "Material.txt", "r" ) != 0)
		return false;

	int size;
	fscanf( file, "%d\n", &size );

	for(int i = 0; i <size; i++)
	{
		int materialID = 0;
		char materialType[20];
		float materialAmount = 0.0f;
		fscanf(file,"%d\t%s\t%f\n",&materialID,materialType,&materialAmount);

		CMaterial temp;
		temp.SetData(materialID,materialType, materialAmount);

		m_materialList.push_back(temp);
	}

	fclose(file);

	return true;
}

bool CProducePart::LoadShipData()
{
	FILE* file;
	if( fopen_s( &file, "Ship.txt", "r" ) != 0 )
		return false;

	int size;
	fscanf(file,"%d\n",&size);

	for(int i = 0; i <size; i++)
	{
		int shipID, materialID;
		float shipAmount;
		char shipDay[9], inputDay[9];
		int checked;
		CShip temp;

		fscanf(file,"%d\t%d\t%f\t%s\t%d",&shipID,&materialID,&shipAmount,
			shipDay,&checked);

		if(checked == 1)
		{
			fscanf(file,"\t%s\n",inputDay);
			temp.SetData(shipID,materialID,shipAmount,shipDay,true,inputDay);
		}
		else
		{
			fscanf(file,"\n");
			temp.SetData(shipID,materialID,shipAmount,shipDay,false);
		}

		m_shipList.push_back(temp);
	}

	fclose(file);

	return true;
}

bool CProducePart::SaveShipData()
{
	FILE* file = NULL;
	if( fopen_s( &file, "Ship.txt", "w" ) != 0 )
		return false;

	int size = (int)m_shipList.size();
	fprintf(file,"%d\n",size);

	vector<CShip>::iterator itr;

	for(itr = m_shipList.begin(); itr != m_shipList.end(); itr++)
	{
		CShip s = (CShip)*itr;

		fprintf(file,"%d\t%d\t%.2f\t%s\t%d\t%s\n",s.m_iShipID,s.m_iShipID,s.m_fShipAmount,
			s.m_dateShipDay.data(),s.m_bChecked,s.m_dateInputDay.data());
	}

	fclose(file);

	return true;
}
