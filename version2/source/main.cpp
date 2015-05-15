/* main.cpp
 *
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 *
 */

#if 0
#elif ArchSkylake
#include "arch/arch_2015_Skylake.h"
#elif ArchHaswell
#include "arch/arch_2013_Haswell.h"
#elif ArchPiledriver
#include "arch/arch_2012_Piledriver.h"
#elif ArchBulldozer
#include "arch/arch_2011_Bulldozer.h"
#elif ArchSandyBridge
#include "arch/arch_2011_SandyBridge.h"
#elif ArchCore2
#include "arch/arch_2006_Core2.h"
#endif

using namespace flops;

int main(int argc, char *argv[]){
    int indefinite = 0;
    int max_flops = 0;

    for( int arg=1; arg < argc; arg++ ) {
        // If indefinite mode has been requested, run until interrupted
        if( strcmp(argv[arg], "--indefinite") == 0 ) {
            indefinite = 1;

            cout << "Running indefinitely - will continue until interrupted...";
            cout << endl;
        }
        // If 'max' flops has been requested, run only the most intense function
        else if( strcmp(argv[arg], "--max-flops") == 0 ) {
            max_flops = 1;

            cout << "Running only the maximum flops function...";
            cout << endl;
        }
        else {
            cout << endl;
            cout << "Run optimized, multi-threaded floating-point operations on CPU(s) and report results.";
            cout << endl << endl << endl;
            cout << "Usage: " << argv[0] << " [options]";
            cout << endl << endl;
            cout << "Optional arguments:";
            cout << endl;
            cout << "    --indefinite: run FLOPS tests until application is interrupted";
            cout << endl;
            cout << "    --max-flops: run only the most FLOPS-intense function";
            cout << endl << endl;
            cout << "Invalid command line option: " << argv[arg];
            cout << endl << endl;
            exit(0);
        }
    }

    // Run the test forever if in indefinite mode; otherwise, run once
    do {
        run_benchmark(1000000000, omp_get_max_threads(), max_flops);
    } while ( indefinite );


#ifdef _WIN32
    system("pause");
#endif
}
