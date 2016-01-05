
//  main.cpp
#include <iostream>
#include <fstream>

#include "List.h"

//Constants
const int HOWMANY = 1;
const int FILE_NAME = 2;
const int ADD_MORE = 3;
const int VIEW_LAST = 4;
const int CHECK_OCCURANCES = 5;
const int REMOVE_OCCURANCES = 6;
const int SECOND_LIST = 7;
const int CHECK_EQUAL = 8;
const int SAVE_TO_FILE = 9;
const int EXIT = 10;
List<int> list();

int getMenuOption();

int menuAction(int choice);

int main() {
    int choice; // = getMenuOption();
    
    bool exitCondition = false;
    
    while (!exitCondition) {
        
        choice = getMenuOption();
        if (choice == EXIT)
            exitCondition = true;
        else {
            menuAction(choice);
        }
    }

    return 0;
}

int getMenuOption() {
    
    int option;
    
    cout << "Option 1: Enter number of values you would like in the list\n";
    cout << "Option 2: Enter file name\n";
    cout << "Option 3: Add more values to the list\n";
    cout << "Option 4: View last value in the list\n";
    cout << "Option 5: Check number of times your value is in the list\n";
    cout << "Option 6: Remove values from the list\n";
    cout << "Option 7: Create a second list\n";
    cout << "Option 8: Check two lists\n";
    cout << "Option 9: Output values from first list to a file\n";
    cout << "Option 10: Exit\n";
    
    cout << "Welcome. Please enter an option number: \n";
    
    string input;
    getline(cin, input);
    option = atoi(input.c_str());
    return option;
}

int menuAction(int choice) {

    int data;
    int numInList;
    string filename;
    int occurances;
    List<int> list;
    List<int> list2;
    
    switch (choice){
            
            //Option 1:
        case HOWMANY: {
            cout << "How many values would you like in the list?" << endl;
            cin >> numInList;
            list = list(numInList*2);
            break;
        }
            
            //Option 2:
        case FILE_NAME: {
            cout << "Enter a filename: " << endl;
            getline(cin, filename);
            ifstream infile(filename);
            
                if (!infile){
                    cout << "list is empty." << endl;
                }
                else {
                    while (infile >> data){
                        list.insert(data);
                            cout << data;
                    }
                }
            break;
        }
    
            //Option 3:
        case ADD_MORE: {
            cout << "Enter int value:" << endl;
            cin >> data;
            list.insert(data);
            break;
        }
            
            //Option 4:
        case VIEW_LAST: {
            cout << list.last();
            break;
        } 
            //Option 5:
        case CHECK_OCCURANCES: {
            cout << "Enter the value you wish to find multiple occurances of: " << endl;
            cin >> data;
            occurances = list.occurs(data);
            cout << "Your value of " << data  << " occurs " << occurances << " times.";
            break;
        } 
            //Option 6:
        case REMOVE_OCCURANCES: {
            cout << "Enter the value you wish to remove multiple occurances of: " << endl;
            list.deleteAll(data);
            break;
       } 
            ////Option 7:
        case SECOND_LIST: {
            for (int i = 0; i < 10; i++) {
                list2.insert(i * 5);
            }
            break;
        } 
            //Option 8:
        case CHECK_EQUAL: {
            //list==list2;
            break;
        }
            //Option 9:
        case SAVE_TO_FILE: {
            
            
            break;
        } 
            //Option 10: EXIT
        case EXIT: {
            //   cout << "Thanks for your time! Good bye." << endl;
            //   return true;
            
            break;
        } 
        default: { 
            break;
       }
    }
    return false;
}


