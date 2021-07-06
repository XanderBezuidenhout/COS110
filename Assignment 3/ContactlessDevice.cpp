#include <iostream>
#include <string>
#include <sstream>
#include "ContactlessDevice.h"
#include "Exception.h"

using namespace std;

ContactlessDevice::ContactlessDevice()
{
    this->currentStudent=0;
    this->tempkey=0;
    this->prevtemp=0;
    this->keyword=0;
    this->rotor=0;
    this->studentDatabase=0;
    this->iteration=0;
}
string ContactlessDevice::registerStudent(const string &codetoenter)
{
   if (currentStudent==maxStudents)
    {
        throw Exception("Student Database is full"); //write to say database full
    }
    else if (findStudent(codetoenter))
    {
        throw Exception("Student already exist");//typo in spec
    }
    else if (codetoenter.length()==0)
    {
        throw Exception("Invalid input");
    }
    else
    {
        string hashedcode;
        hashedcode.clear();
        int charascii;
        
        for (int count=0;count<codetoenter.length();count++)
        {
            charascii=codetoenter[count];
            if (charascii==32)
            {
                throw Exception("Invalid input"); //write in exception class if invalid student num
            }
        }
        //this->setRotor();
        for (int count=0;count<codetoenter.length();count++)
        {
            hashedcode.append(1,hashChar(codetoenter[count]));
        }
        if (studentDatabase==0)
        {
            setStudentDatabase();
        }
        
        studentDatabase[currentStudent][0]=codetoenter;
        studentDatabase[currentStudent][1]=hashedcode;
        currentStudent++;
        iteration=0;
        return hashedcode;
    }    
}

string ContactlessDevice::authenticateStudent(const string& codetofind)
{
    string output;
    output.clear();
    string hashedcode;
    hashedcode.clear(); 
    for (int count=0;count<codetofind.length();count++)
    {
        hashedcode.append(1,hashChar(codetofind[count]));
        //cout<<hashedcode<<endl;
    }
    iteration=0;  
    output.append(hashedcode);
    if (findStudent(codetofind))
    {
        output.append("true");
        return output;
    }
    else
    {
        output.append("false");
        return output;
    }  
    
}
ContactlessDevice::~ContactlessDevice()
{
    this->clearRotor();
    //cout<<"happens here"<<endl;
    if (keyword!=0)
    {
        delete keyword;
    }
    
    if (studentDatabase!=0)
    {
         for (int count=0;count<maxStudents;count++)
         {
            if (studentDatabase[count]!=0)
            {
                
                delete [] studentDatabase[count];
               // cout<<"deleted row"<<count<<endl;
            }
        
        }
        //cout<<"happens last"<<endl;
        delete [] studentDatabase;
    }
}

int* ContactlessDevice::setKeyword(const string& key)
{
    iteration=0;
    keylength=key.length();
    if (keylength<2)
    {
        throw Exception("The keyword provided is not going to generate a safe encryption");
    }
     if (keyword!=0)
    {
        keyword=0;
    }
    this->keyword=new int[keylength];
    stringstream ss;
    string temp;
    int charascii;  
    
    if (prevtemp!=0)
    {
        prevtemp=0;
    }
    if (tempkey!=0)
    {
        tempkey=0;
    } 
    tempkey=new int[keylength];
    prevtemp= new int[keylength];
    for (int index=0;index<keylength;index++)
    {
        charascii=key[index];
        if (charascii==32)
        {
            throw Exception("The keyword provided is not going to generate a safe encryption");
        }
        if ((charascii<48)||(57<charascii))
        {
            throw Exception("Invalid input");    //ADD A SPECIFIC FUNCTION TO EXCEPTION CLASS TO HANDLE THIS
        }
        else
        {
            ss.clear();
            temp.assign(1,key[index]);
            ss.str(temp);
            ss>>keyword[index];
        }
    }
   
    for (int keyindex=0;keyindex<keylength;keyindex++)
    {
        tempkey[keyindex]=keyword[keyindex];
        prevtemp[keyindex]=tempkey[keyindex];
    }
    return keyword;
}
void ContactlessDevice::setRotor()
{
    if (iteration==0)
    {
        tempkey[0]=keyword[0];
        for (int index=0;index<keylength;index++)
        {
            tempkey[index]=(keyword[index]+tempkey[index-1])%10;
        }
    }      
    if (keyword!=0)
    {
        if (rotor!=0)
        {
           clearRotor(); 
        }
        rotor=new int*[10];
        for (int rotorrow=0;rotorrow<10;rotorrow++)
        {
            rotor[rotorrow]=new int[keylength];
            rotorRowSet(rotorrow,rotorrow);  
        }
    }
    else
    {
        throw Exception("Keyword must be set");  //ADD A SPECIFIC FUNCTION TO EXCEPTION CLASS TO HANDLE THIS
    }
    
}

int** ContactlessDevice::getRotor()
{
    return (this->rotor) ;
}



void ContactlessDevice::rotorRowSet(int keyoffset,int rotorrow)
{
   
    for (int index=0;index<keylength;index++)
    {
      
       rotor[rotorrow][index]=tempkey[index];
       tempkey[index]++;
        tempkey[index]=(tempkey[index])%10;
       
    }

}
void ContactlessDevice::clearRotor()
{
    if (rotor!=0)
    {
        for (int row=0;row<10;row++)
        {
            if (rotor[row]!=0)
            {
                delete rotor[row];
                rotor[row]=0;

            }
        }
        delete [] rotor;
        rotor=0;
    }
    else
    {
        return;
    }   
}

void ContactlessDevice::setStudentDatabase()
{
    studentDatabase=new string*[this->maxStudents];
    for (int row=0;row<this->maxStudents;row++)
    {
        studentDatabase[row]=new string[2];  
        studentDatabase[row][0]="z";
        studentDatabase[row][1]="z";
    } 
}

string** ContactlessDevice::getStudentDatabase()
{
    return studentDatabase;
}

bool ContactlessDevice::findStudent(const string& codetofind)
{
    if (studentDatabase!=0)
    {
         for (int studentindex=0;studentindex<maxStudents;studentindex++)
        {
            if (studentDatabase[studentindex]!=0)
            {
               if (studentDatabase[studentindex][0]==codetofind)
                {
                    return true;
                } 
            }
            else
            {
                return false;
            }     
        }   
    } 
    return false;
}



void ContactlessDevice::changeRotorStart()
{
    
}