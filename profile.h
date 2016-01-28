#ifndef PROFILE_H
#define PROFILE_H

#include <QCoreApplication>
#include <QString>
#include <QDataStream>

class Profile
{
    Q_DECLARE_TR_FUNCTIONS(Profile)

public:
    Profile();
    Profile(float w, short h, short age, QString g, float a, int calorie);

    ~Profile();

    //ostream, << overloading
    friend QDataStream &operator<<(QDataStream &out, const Profile &p)
    {
        out << p.getWeigth() << p.getHeigth() << p.getAge() << p.getGender()
            << p.getActivity() << p.getCalorie() << p.getBMI()
            << p.getConclusion() << p.getOptimalWeightMin() << p.getOptimalWeightMax()
            << p.getBMR() << p.getWater();
        return out;
    }

    //istream, >> overloading
    friend QDataStream &operator>>(QDataStream &in, Profile &p)
    {
        float weight;
        short height;
        short age;
        QString gender;
        float activity;
        int calorie;

        double bmi;
        QString conclusion;
        double minWeight;
        double maxWeight;
        double bmr;
        double water;

        in >> weight >> height >> age >> gender >> activity >> calorie >> bmi
                >> conclusion >> minWeight >> maxWeight >> bmr >> water;

        p = Profile(weight,height,age,gender,activity, calorie);
        p.setBMI(bmi);
        p.setConclusion(conclusion);
        p.setOptimalWeightMin(minWeight);
        p.setOptimalWeightMax(maxWeight);
        p.setBMR(bmr);
        p.setWater(water);

        return in;
    }

    //Calculate the all profile norms
    void calculateNorms();

    void setWeigth(float w);
    float getWeigth() const;

    void setHeigth(short w);
    short getHeigth() const;

    void setAge(short age);
    short getAge() const;

    void setGender(QString g);
    QString getGender() const;

    void setActivity(float a);
    float getActivity() const;

    void setCalorie(int calorie);
    int getCalorie() const;

    void setBMI(double temp);
    double getBMI() const;

    void setConclusion(QString temp);
    QString getConclusion() const;

    void setOptimalWeightMin(double min);
    double getOptimalWeightMin() const;

    void setOptimalWeightMax(double max);
    double getOptimalWeightMax() const;

    void setBMR(double bmr);
    double getBMR() const;

    void setWater(double water);
    double getWater() const;

private:

    /**
     * @brief Calculating BMI @see https://en.wikipedia.org/wiki/Body_mass_index
     * @return BMI number
     */
    double calculateBMI();

    /**
     * @brief conclusionBMI
     * @param res is the BMI number
     * @return conlclusion
     */
    QString conclusionBMI(double res);

    /**
     * @brief calculateOptimalWeight
     * @param min is the minimum weight
     * @param max is the maximum weight
     */
    void calculateOptimalWeight(double &min, double &max);

    /**
     * @brief calculateBMR @https://en.wikipedia.org/wiki/Basal_metabolic_rate
     * @return BMR number
     */
    double calculateBMR();

    //Calculate norm of water
    double calculateWater();

private:
    float weight;
    short height;
    short age;
    QString gender;
    float activity;
    int calorie;

    double bmi;
    QString conclusion;
    double minWeight;
    double maxWeight;
    double bmr;
    double water;
};

#endif // PROFILE_H
