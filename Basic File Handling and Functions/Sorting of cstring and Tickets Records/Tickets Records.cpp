#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void maximum(int a)
{
    ifstream fin;
    fin.open("MidsData.txt");
    
    const int size = 50;
    
    char category[size] = {'\0'}, finalArray[size] = {'\0'};
    char firstLine[1000] = {'\0'};
    
    int ticket = 0, price = 0, large = 0;
    
    fin.getline(firstLine, 1000);
    
    while(!fin.eof())
    {
        fin >> category;
        fin >> price;
        fin >> ticket;
        
        if(ticket > large)
        {
            large = ticket;
            strcpy(finalArray, category);
        }
    }
    
    cout << "The category with maximum tickets sold is " << finalArray << endl; 
    
    fin.close();
}

void sales(int b)
{
    ifstream fin;
    fin.open("MidsData.txt");
    
    const int size = 50;
    
    char category[size] = {'\0'}, finalArray[size] = {'\0'};
    char firstLine[1000] = {'\0'};
    
    int ticket = 0, price = 0, sales = 0;
    
    fin.getline(firstLine, 1000);
    
    while(!fin.eof())
    {
        fin >> category;
        fin >> price;
        fin >> ticket;
        
        sales = price * ticket;
        
        if(sales >= 10000)
        {
            cout << "The category whose sale exceeds 10,000 is " << category << endl;
        }
        
    }
    
    fin.close();
}

void total(int c)
{
    ifstream fin;
    fin.open("MidsData.txt");
    
    const int size = 50;
    
    char category[size] = {'\0'}, finalArray[size] = {'\0'};
    char firstLine[1000] = {'\0'};
    
    int ticket = 0, price = 0, total = 0;
    
    fin.getline(firstLine, 1000);
    
    while(!fin.eof())
    {
        fin >> category;
        fin >> price;
        fin >> ticket;
        
        total += ticket;
    }
    
    cout << "The total number of tickets sold are " << total << endl; 
    
    fin.close();
}

int main()
{
    int choice = 0;
    
    cout << "Choose from the following options.\n";
    cout << "1. Display the category with maximum tickets sold\n";
    cout << "2. Display the categories whose sales exceeds 10,000\n";
    cout << "3. Diplay the total number of tickets sold\n";
    cin >> choice;
    
    while(choice < 1 || choice > 3)
    {
        cout << "WRONG INPUT!\n";
        cout << "Enter again : ";
        cin >> choice;
    }
    
    if(choice == 1)
    {
        maximum(choice);
    }
    
    else if(choice == 2)
    {
        sales(choice);
    }
    
    else if(choice == 3)
    {
        total(choice);
    }
    
    return 0;
}
