//  List.h
//  Project 8

#ifndef __Project_8__List__
#define __Project_8__List__

#include <stdio.h>
#include <iostream>
#include <ostream>
#include <istream>

#endif /* defined(__Project_8__List__) */

using namespace std;

template <class T>
class List {
    
private:
    
    T* data;  //dynamic array which stores list data
    
    int howmany; //number of values in the list
    int size; //capacity of list

public:
    
    //creates list with capacity of 10
    List(){
        size = 10;
        howmany = 0;
        
        data = new T[size];
    }
    
    //creates list with capacity of max
    List(int max){
        
        size = max;
        howmany = 0;
        
        data = new T[size];
    }
    
    //returns true if this list is full
    bool isFull()const{
        if(howmany ==size)
            return true;
        
        else return false;
    }
    
    //returns true if this list is full (i think she meant if empty
    bool isEmpty()const{
        if(howmany==0)
            return true;
        else return false;
        
    }
    //if list is not full, inserts adds this item to the list otherwise a ListExeption is thrown

    void insert(const T& value){
        if (!isFull()){
            data[howmany] = value;
            howmany++;
        }
        else {
            throw 5;
        }
    }
    
    //returns the last item in list, if empty, exception is thrown
    T last()const{
        if(!isEmpty()){
            return data[howmany-1];
        }
        else{
            throw 5;
        }
    }
    
    //returns the number of times 'value' occurs in the list
    int occurs(const T& value) const{
        
        int count = 0;
        
        for(int i = 0; i < howmany; i++){
            if (value == data[i]){
                count++;
            }
        }
        return count;
    }
    
    //deletes ALL occurances of value
    void deleteAll(const T& value){
        for(int i = 0; i < howmany; i++){
            if (value == data[i]){
                for (int j = i+1; j< howmany; j++) {
                    data[j-1] = data[j];
                }
                howmany--;
            }
        }
    }
    
    //returns true if this object equal to operand
    bool operator == (const List<T>& operand) const{
        for(int i = 0; i < howmany; i++){
            if (data[i] != operand[i])
                return false;
        }
        return true;
    }
    
    //not needed in func def
   friend ostream& operator<< <T>(ostream& out, const List<T>& robject){
       for (int i = 0; i < robject.howmany; i++) {
           out << robject.data[i] << endl;
       }
    }
};




