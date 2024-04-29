// Asynchronous composition of a system of traffic lights nusmv code


// MODULE light(other_state)
// VAR
//     state: {r, y, g};
// ASSIGN
//           init(state) := r ;
//           next(state) := case
//                     state=r & other_state=r : { r, y };
//                     state=y : g;
//                     state=g : {g , r};
//                     TRUE: state;
//                     esac;
// MODULE main
// VAR
//           tl1: process light(tl2.state);
//           tl2: process light(tl1.state);

// Run commands:
// 1.Go to c directory cmd.
// 2.run command : 1.cd Users\pnmar\Downloads\NuSMV-2.5.4-x86_64-w64-mingw32\NuSMV-2.5.4-x86_64-w64-mingw32\bin
//                 2.nusmv -int
//                 3.read_model -i intro.smv
//                 4.flatten_hierarchy
//                 5.encode_variables
//                 6.build_model
//                 7.check_ltlspec -p "!(F(tl1.state = g & tl2.stzte=g))"
//                 8.print_reachable_states -v
//                 9.pick_state -i
//                 10.simulate -i -k 3
