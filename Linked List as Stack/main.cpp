//
//  main.cpp
//  Dynamic Array as Stack
//
//  Created by Vichet Meng on 4/13/16.
//  Copyright © 2016 ViMApps. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

int main() {
    
    Stack<Vehicle *> stack1, stack2;
    
    stack1.push(new Car(2013, "Scion", "FR-S", DriveTrainRearWheelDrive, TransmissionManual));
    stack1.push(new Motorcycle(2010, "BMW", "Z12DQ", MotorcycleTypeCruiser));
    stack1.push(new Car(2006, "Honda", "CR-V", DriveTrainRearWheelDrive, TransmissionAutomatics));
    
    
    cout << "The stack is" << endl;
    while(!stack1.isEmpty())
    {
        cout << *stack1.peek() << endl;
        stack1.popPointer();
    }
    
    
    cout << endl;
    return 0;
}