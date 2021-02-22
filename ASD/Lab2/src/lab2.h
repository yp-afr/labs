#pragma once
#include <iostream>
#include <chrono>
#include <map>
#include <string>

#define container map<string, long double>

using namespace std;

void fillArray(int* arr, int n);
void displayArray(int* arr, int n);
int increment(int* inc, long size);
container methodOfChoice(int* arr, int n);
container methodOfShell(int* arr, int n);
void ConsoleLog(container results);
void selectMethod(int* arr,int n);