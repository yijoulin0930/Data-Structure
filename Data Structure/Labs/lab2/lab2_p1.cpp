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
	//��Xnum1_Prime_factor
	cout<< "num1_Prime_factor : \"" ;
	for (int i = 0; i < num1_factor.size(); i++)
		cout << num1_factor[i] << " ";
	cout << "\"" << endl;

	//��Xnum2_Prime_factor
	cout << "num2_Prime_factor : \"";
	for (int i = 0; i < num2_factor.size(); i++)
		cout << num2_factor[i] << " ";
	cout << "\"" << endl;

}
void PrimeFactorization::Print_GCD()
{
	int GCD = 1;
	int j=0, n2 = 0;
	
	for (int i = 0; i < num1_factor.size(); i++) //��num1[i]���з�,�p�Gnum2[j]��num1[i]�j����num1���U�@��m�M�䤽�]��,�Ϥ��hnum2���U�@��m�M��
	{

		if (j == num2_factor.size())  //����num2�W�X�d��
			break;

		if (num1_factor[i] == num2_factor[j])  //�Y��Ƭ۵��hnum2�@�_���U�@��m,�ñNnum1[i]�MGCD�ۭ�
		{
			j++;
			GCD *= num1_factor[i];
		}
		else if (num1_factor[i] < num2_factor[j])  //num2[j]��num1[i]�j,num1���U�@��m�M�䤽�]��
			continue;
		else if (num1_factor[i] > num2_factor[j])  //num1[j]��num2[i]�j,num2���U�@��m�M�䤽�]��,��num1����
		{
			j++;
			i--;  //����for�j��Nnum1���ܤU�@��m
		}

	}

	cout << "GCD : " << GCD << endl;
}