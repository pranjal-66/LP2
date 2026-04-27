#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fever, cough, headache, fatigue, stomachPain;

    cout << "====== HOSPITAL EXPERT SYSTEM ======\n";
    cout << "Answer in yes / no\n\n";

    cout << "Do you have fever? ";
    cin >> fever;

    cout << "Do you have cough? ";
    cin >> cough;

    cout << "Do you have headache? ";
    cin >> headache;

    cout << "Do you feel fatigue? ";
    cin >> fatigue;

    cout << "Do you have stomach pain? ";
    cin >> stomachPain;

    cout << "\n------ DIAGNOSIS RESULT ------\n";

    if (fever == "yes" && cough == "yes" && fatigue == "yes")
    {
        cout << "Possible Disease: Flu\n";
        cout << "Advice: Take rest and drink warm fluids.\n";
    }
    else if (fever == "yes" && headache == "yes")
    {
        cout << "Possible Disease: Viral Fever\n";
        cout << "Advice: Take medicine and consult doctor.\n";
    }
    else if (cough == "yes" && fever == "no")
    {
        cout << "Possible Disease: Common Cold\n";
        cout << "Advice: Take steam and rest properly.\n";
    }
    else if (stomachPain == "yes")
    {
        cout << "Possible Disease: Food Poisoning\n";
        cout << "Advice: Drink ORS and eat light food.\n";
    }
    else if (fatigue == "yes")
    {
        cout << "Possible Condition: Weakness / Stress\n";
        cout << "Advice: Take proper rest and healthy diet.\n";
    }
    else
    {
        cout << "No clear diagnosis.\n";
        cout << "Advice: Please consult a doctor.\n";
    }

    cout << "\nThank you for using Expert System!\n";

    return 0;
}