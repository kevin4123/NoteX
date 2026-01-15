## SystemVerilog
***简介***
- IEEE Std 1800™-2017(encompass the IEEE 1364-2005 reference model for simulation)
- used to **Hardware Design** and **Verification** 
- [Scheduling semantics](https://vlsiverify.com/system-verilog/systemverilog-scheduling-semantics/)
- [SystemVerilog](https://www.youtube.com/playlist?list=PL40xmtPvboRs6Ng_1Q_V-1MdJH50A6Ulz)
---

### Design and Verification Constructs


***Scheduling semantics***
```c
execute_simulation {
    T = 0;
    initialize the values of all nets and variables;
    schedule all initialization events into time zero slot;
    while (some time slot is nonempty) {
        move to the first nonempty time slot and set T;
        execute_time_slot (T);
    }
    execute_time_slot {
        execute_region (Preponed);
        execute_region (Pre-Active); 
        while (any region in [Active ... Pre-Postponed] is nonempty) {
            while (any region in [Active ... Post-Observed] is nonempty) {
                execute_region (Active);
                R = first nonempty region in [Active ... Post-Observed];
                if (R is nonempty)
                move events in R to the Active region;
            }
            while (any region in [Reactive ... Post-Re-NBA] is nonempty) {
                execute_region (Reactive);
                R = first nonempty region in [Reactive ... Post-Re-NBA];
                if (R is nonempty)
                move events in R to the Reactive region;
            }
            if (all regions in [Active ... Post-Re-NBA] are empty)
            execute_region (Pre-Postponed);
        }
        execute_region (Postponed);
    }
    execute_region {
        while (region is nonempty) {
            E = any event from region;
            remove E from the region;
            if (E is an update event) {
                update the modified object;
                schedule evaluation event for any process sensitive to the object;
            } else { /* E is an evaluation event */
                evaluate the process associated with the event and possibly
                schedule further events for execution;
            }
        }
    }
}
```


***Lexical conventions***
    - Number representation
        -  [sign][size]'[base][value]
    - Structure literals
        - 操作符：'{}

***Data types***
    - Logic：0, 1，x, z
    - Casting
        - 操作符: '()
    - Enumerations 
        - 操作符：enum
***Operators and expressions***
    - Operators 
    - 

***Procedural programming statements***
    - Case statements
        - unique case: 所有分支互斥(不会同时匹配多个)
        - priority case: 
        - unique0-case: 


***Utility system tasks and system functions***
    - Simulation control tasks
        - $stop [ ( n ) ] ;
        - $finish [ ( n ) ] ;
        - $exit [ ( ) ] ;

---
