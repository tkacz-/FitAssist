#include "profile.h"

Profile::Profile()
{

}

Profile::Profile(float w, short h, short age, QString g, float a)
{
    setWeigth(w);
    setHeigth(h);
    setAge(age);
    setGender(g);
    setActivity(a);
}

double Profile::calculateBMI()
{
    double h =  static_cast<double>(height) / 100;
    return static_cast<double>(weight) / (h * h);
}

QString Profile::conclusionBMI(double res)
{
    QString Conclusion[7] = { "Выраженный дефицит массы тела",
                                  "Недостаточная масса тела",
                                  "Норма",
                                  "Избыточная масса тела",
                                  "Ожирение первой степени",
                                  "Ожирение второй степени",
                                  "Ожирение третьей степени" };
    QString temp;
    if (res < 16)
        temp = Conclusion[0];
    if (res >= 16 && res < 18.5)
        temp = Conclusion[1];
    if (res >= 18.5 && res < 24.99)
        temp = Conclusion[2];
    if (res >= 25 && res < 30)
        temp = Conclusion[3];
    if (res >= 30 && res < 35)
        temp = Conclusion[4];
    if (res >= 35 && res < 40)
        temp = Conclusion[5];
    if (res >= 40)
        temp = Conclusion[6];
    return temp;
}

void Profile::calculateOptimalWeight(double &min, double &max)
{
    float h = (float) height / 100;
    min = (double) 18.5 * h * h;
    max = (double) 25 * h * h;
}

double Profile::calculateBMR()
{
    double res;
    if (gender == "male")
        res = 9.99 * weight + 6.25 * height - 4.92 * age + 5;
    if (gender == "female")
        res = 9.99 * weight + 6.25 * height - 4.92 * age - 161;
    return res * activity;
}

double Profile::calculateWater()
{
    double res;
    if (gender == "male")
        res = 35 * weight;
    if (gender == "female")
        res = 31 * weight;
    return res / 1000;
}

void Profile::calculateNorms()
{
    double bmi = Profile::calculateBMI();
    Profile::setBMI(bmi);
    QString conclusion = Profile::conclusionBMI(bmi);
    Profile::setConclusion(conclusion);

    double minw, maxw;
    Profile::calculateOptimalWeight(minw, maxw);
    Profile::setOptimalWeightMin(minw);
    Profile::setOptimalWeightMax(maxw);

    double calorie = Profile::calculateBMR();
    Profile::setBMR(calorie);

    double water = Profile::calculateWater();
    Profile::setWater(water);
}

void Profile::setWeigth(float w)
{
    weight = w;
}

float Profile::getWeigth() const
{
    return weight;
}

void Profile::setHeigth(short h)
{
    height = h;
}

short Profile::getHeigth() const
{
    return height;
}

void Profile::setAge(short age)
{
    this->age = age;
}

short Profile::getAge() const
{
    return age;
}

void Profile::setGender(QString g)
{
    gender = g;
}

QString Profile::getGender() const
{
    return gender;
}

void Profile::setActivity(float w)
{
    activity = w;
}

float Profile::getActivity() const
{
    return activity;
}

void Profile::setBMI(double temp)
{
    bmi = temp;
}

double Profile::getBMI() const
{
    return bmi;
}

void Profile::setConclusion(QString temp)
{
    conclusion = temp;
}

QString Profile::getConclusion() const
{
    return conclusion;
}

void Profile::setOptimalWeightMin(double temp)
{
    minWeight = temp;
}

double Profile::getOptimalWeightMin() const
{
    return minWeight;
}

void Profile::setOptimalWeightMax(double temp)
{
    maxWeight = temp;
}

double Profile::getOptimalWeightMax() const
{
    return maxWeight;
}

void Profile::setBMR(double temp)
{
    bmr = temp;
}

double Profile::getBMR() const
{
    return bmr;
}

void Profile::setWater(double temp)
{
    water = temp;
}

double Profile::getWater() const
{
    return water;
}
