// code:

// MODULE main
// VAR
//    location:{l1, l2};
//    x : 0..100;
// ASSIGN
//    init(location):=l1;
//    init(x):=0;
//    next(location):=case
//          (location=l1) & (x<10) : l2;
//          (location = l2) : l1;
//          TRUE:location;          (if above 2 conditions are not satisfied do not change location)
//          esac;
//    next(x):=case
//          (location = l2) & x<100 : x+1; (if locatonis l2 and x is strictly less than 100 then increase x by 1)
//          TRUE : x; (else do not increase x)
//          esac;


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