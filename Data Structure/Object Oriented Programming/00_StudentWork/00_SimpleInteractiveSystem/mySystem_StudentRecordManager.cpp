//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER()
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput()
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;

	cout << "Input the numbers of students[2,100]: ";
	while (true) {
		cin >> mNumStudents;

		if (mNumStudents >= 2 && mNumStudents <= 100)
			break;
	}

	int temp = 0;

	cout << "Input the score of each student[0,100]: ";
	for (int i = 0; i < mNumStudents; i++) {
		while (true) {
			cin >> temp;

			if (temp >= 0 && temp <= 100)
				break;
		}
		mScore.push_back(temp);
	}

	computeAverage();

	computeStandardDeviation();

	cout << "Average: " << mAverageScore << endl;
	cout << "Standard Deviation: " << mStandardDeviation << endl;
	sortScores();
	showSortedScores();
}

double STUDENT_RECORD_MANAGER::computeAverage()
{
	//Compute the average
	double totalScore = 0.0;

	for (int i = 0; i < mNumStudents; i++)
		totalScore += mScore[i];

	mAverageScore = totalScore / mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation()
{
	//Compute the standard deviation
	mStandardDeviation = 0.0;
	if (mNumStudents < 2) return 0.0;

	double sum = 0.0;

	for (int i = 0; i < mNumStudents; i++)
		sum += (mScore[i] - mAverageScore) * (mScore[i] - mAverageScore);

	mStandardDeviation = sqrt(sum / (mNumStudents));
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores()
{
	//Sorting in an ascending order

	sort(mScore.begin(), mScore.end());

	for (int i = 0; i < mScore.size(); i++)
		mSortedScore.push_back(mScore[i]);
}

void STUDENT_RECORD_MANAGER::showSortedScores() const
{
	//Show the scores in an ascending order

	cout << "Sorted scores: ";
	for (int i = 0; i < mNumStudents; ++i) {
		cout << mSortedScore[i] << " ";
	}
	cout << "\n";
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0;
	for (int i = 0; i < mNumStudents; ++i) {
		if (mScore[i] >= s0 && mScore[i] <= s1)
			num++;
	}
	return num;
}
// CODE: 2020/07/14. Do not delete this line.