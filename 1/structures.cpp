#include <iostream>
using namespace std;

struct agents{
    string agentName;
    int agentCode;
    string agentDepart;
   };

int main(){
    /*
    Structures also called structs, Unlike an array a structure can contain many different data types (int, string, bool, etc..)
    To create a structure, use the struct keyword
    */
   struct{
    string myName;
    int rollNo;
    double percentage;
   }myStructure;  //Structure variable

   //Assign values to members of myStructure
   myStructure.myName = "Khalid Ashraf";
   myStructure.rollNo = 12;
   myStructure.percentage = 68.12;
   
   //To access members of a structure, use the dot syntax(.);
   cout <<"Student Name: "<< myStructure.myName << endl;
   cout <<"Roll No: "<< myStructure.rollNo << endl;
   cout << "Percentage%: "<< myStructure.percentage << endl<<endl;

   //One structure in Multiple Variables
   struct{
    string name;
    int empNo;
   }emp_1,emp_2,emp_3;


   //emp_1
   emp_1.name = "Khalid Ashraf";
   emp_1.empNo = 121;

   //emp_2
   emp_2.name = "Patrik Wyne";
   emp_2.empNo = 141;

   //emp_3
   emp_3.name = "Jackob Alfred";
   emp_3.empNo = 454;

   cout<< emp_1.name << " :=> " << emp_1.empNo << endl;
   cout<< emp_2.name << " :=> " << emp_2.empNo << endl;
   cout<< emp_3.name << " :=> " << emp_3.empNo << endl;

/*By giving a name of the structure, you can treat it as a data type. This means that you can create variables with this structure anywhere in the program in the program at any time.*/
   agents agent_1;
   agent_1.agentName = "Khalid Ashraf ";
   agent_1.agentCode = 141;
   agent_1.agentDepart = " Shadow Company";

   agents agent_2;
   agent_2.agentName = " Price MacTavish ";
   agent_2.agentCode = 211;
   agent_2.agentDepart = "SIS Sniper";

   cout << agent_1.agentName << agent_1.agentCode << agent_1.agentDepart << endl;
   cout << agent_2.agentName << agent_2.agentCode << agent_2.agentDepart << endl;



}