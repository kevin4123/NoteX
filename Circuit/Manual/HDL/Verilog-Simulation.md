
***Scheduling semantics***
```c
while (there are events) {
    if (no active events) { 
        if (there are inactive events) { 
                activate all inactive events; 
            } else if (there are nonblocking assign update events) {
                activate all nonblocking assign update events; 
            } else if (there are monitor events) {
                activate all monitor events;
            } else { 
                advance T to the next event time; 
                activate all inactive events for time T;
            } 
    }
    E = any active event;
    if (E is an update event) { 
            update the modified object; 
            add evaluation events for sensitive processes to event queue; 
        } else { /* shall be an evaluation event */ 
            evaluate the process; 
            add update events to the event queue; 
    } 
}
```