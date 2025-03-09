#include"lab2_p1.h"
#include<iostream>
#include<vector>
#include<fstream>

void PrimeFactorization::Get_Prime_Factorization()
{
	int n1 = num1,n2 = num2;

	for (int i = 2; i < n1+1; i++)
	{
		if (n1 % i == 0)
		{
			num1_factor.push_back(i);
			n1 = n1 / i;
			i = 1;
			continue;
		}
	}

	for (int i = 2; i < n2 + 1; i++)
	{
		if (n2 % i == 0)
		{
			num2_factor.push_back(i);
			n2 = n2 / i;
			i = 1;
			continue;
		}
	}
}
void PrimeFactorization::Print_Prime_Factorization()
{
	//輸出num1_Prime_factor
	cout<< "num1_Prime_factor : \"" ;
	for (int i = 0; i < num1_factor.size(); i++)
		cout << num1_factor[i] << " ";
	cout << "\"" << endl;

	//輸出num2_Prime_factor
	cout << "num2_Prime_factor : \"";
	for (int i = 0; i < num2_factor.size(); i++)
		cout << num2_factor[i] << " ";
	cout << "\"" << endl;

}
void PrimeFactorization::Print_GCD()
{
	int GCD = 1;
	int j=0, n2 = 0;
	
	for (int i = 0; i < num1_factor.size(); i++) //用num1[i]為標準,如果num2[j]比num1[i]大的話num1往下一位置尋找公因數,反之則num2往下一位置尋找
	{

		if (j == num2_factor.size())  //防止num2超出範圍
			break;

		if (num1_factor[i] == num2_factor[j])  //若兩數相等則num2一起往下一位置,並將num1[i]和GCD相乘
		{
			j++;
			GCD *= num1_factor[i];
		}
		else if (num1_factor[i] < num2_factor[j])  //num2[j]比num1[i]大,num1往下一位置尋找公因數
			continue;
		else if (num1_factor[i] > num2_factor[j])  //num1[j]比num2[i]大,num2往下一位置尋找公因數,但num1不變
		{
			j++;
			i--;  //防止for迴圈將num1移至下一位置
		}

	}

	cout << "GCD : " << GCD << endl;
}