#ifndef PROFILE_H
#define PROFILE_H

#include <QString>

class Profile
{
private:
    float weight;
    short height;
    short age;
    QString gender;
    float activity;

    double bmi;
    QString conclusion;
    double minWeight;
    double maxWeight;
    double bmr;
    double water;

private:
    //Calculate BMI
    double calculateBMI();

    //Conclision of BMI
    QString conclusionBMI(double res);

    //Calculate optimal weight
    void calculateOptimalWeight(double &min, double &max);

    //Calculate optimal calorie
    double calculateBMR();

    //Calculate norm of water
    double calculateWater();

public:
    Profile(float w, short h, short age, QString g, float a);

    //Calculate all profile norms
    void calculateNorms();

    void setWeigth(float w);
    float getWeigth();

    void setHeigth(short w);
    short getHeigth();

    void setAge(short age);
    short getAge();

    void setGender(QString g);
    QString getGender();

    void setActivity(float a);
    float getActivity();

    void setBMI(double temp);
    double getBMI();

    void setConclusion(QString temp);
    QString getConclusion();

    void setOptimalWeightMin(double min);
    double getOptimalWeightMin();

    void setOptimalWeightMax(double max);
    double getOptimalWeightMax();

    void setBMR(double bmr);
    double getBMR();

    void setWater(double water);
    double getWater();
};

#endif // PROFILE_H
