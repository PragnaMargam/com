// MODULE main
// VAR
//    man : boolean;
//    goat: boolean;
//    wolf: boolean;
//    cabbage : boolean;
//    carry:{g, w, c, 0};

// ASSIGN
//    init(man) := FALSE;
//    init(goat) := FALSE;
//    init(wolf) := FALSE;
//    init(cabbage) := FALSE;
//    init(carry) := 0;

//    next(man) := {TRUE, FALSE};    

//    next(carry) := case             
//                     man = goat: g;     (next value of carry is made non deterministically by man) 
//                     TRUE : carry;       (if next value of carry is the goat value of man=goat)
//                 esac union
//                   case
//                     man = wolf: w;
//                     TRUE : carry;
//                 esac union
//                   case
//                      man = cabbage: c;
//                      TRUE : carry;
//                 esac union 0;          (he may choose to not carry anyting)                
     

//     next(goat) := case
//                     next(carry) = g: next(man);
//                     TRUE: goat;
//                   esac;

//     next(wolf):= case                                  (if the next value of carry is the wolf  then the value changes to wherever man goes next.)
//                     next(carry) = w: next(man);
//                     TRUE: wolf;
//                   esac;

//     next(cabbage) := case
//                     next(carry) = c: next(man);
//                     TRUE: cabbage;
//                   esac;


// LTLSPEC

// !(((goat = cabbage | goat = wolf) -> man = goat) U (man & cabbage & goat & wolf))


//(check !phi which gives a counter example), which gives a path that does not satisfy phi, that means it satisfies phi)





// Run commands:
// 1.Go to c directory cmd.
// 2.run command : 1.cd Users\pnmar\Downloads\NuSMV-2.5.4-x86_64-w64-mingw32\NuSMV-2.5.4-x86_64-w64-mingw32\bin
//                 2.nusmv -int
//                 3.read_model -i intro.smv
//                 4.flatten_hierarchy
//                 5.encode_variables
//                 6.build_model
//                 7.pick_state -i
//                 8.simulate -i -k 3
//                 9.check_ltlspec



