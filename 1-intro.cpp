//code:
// MODULE main
// VAR 
//     location:{l1,l2};
// ASSIGN
//     init(location):=l1;
//     next(location):=case
//              (location=l1):l2;
//              (location=l2):l1;      
//              esac;


// Run commands:
// 1.Go to c directory cmd.
// 2.run command : 1. cd Users\pnmar\Downloads\NuSMV-2.5.4-x86_64-w64-mingw32\NuSMV-2.5.4-x86_64-w64-mingw32\bin
//                 2.nusmv -int
//                 3.read_model -i intro.smv
//                 4.flatten_hierarchy
//                 5.encode_variables
//                 6.build_model
//                 7.pick_state -i
//                 8.simulate -i -k 3


//print_reachable_states -v
