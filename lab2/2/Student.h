#pragma once
class Student
{
    float mathGrade, englishGrade, historyGrade;
    float avarageGrade;
    char* name;

public:
    void setName(const char* name, int size);
    const char* getName();

    void setMathGrade(float mathGrade);
    float getMathGrade();

    void setEnglishGrade(float englishGrade);
    float getEnglishGrade();

    void setHistoryGrade(float historyGrade);
    float getHistoryGrade();

    void setAvarageGrade();
    float getAvarageGrade();
};
