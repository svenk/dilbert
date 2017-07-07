#include "tarch/logging/Log.h"
#include "peano/utils/Loop.h"

#include "peano/peano.h"

#include "peano/grid/aspects/CellLocalPeanoCurve.h"
#include "tarch/multicore/MulticoreDefinitions.h"


#ifdef SharedMemoryParallelisation
#include "tarch/multicore/Core.h"
#endif

#if defined(SharedTBBInvade)
#include "shminvade/SHMInvade.hpp"
#endif


#include "tarch/parallel/Node.h"
#include "tarch/parallel/NodePool.h"

/* DILBERT START */
#include "tarch/Assertions.h" // for accessing the mode storage
bool dilbert_Asserts; // Storage for the global

#include <cstdlib> // getenv
#include <strings.h> // strcasecmp
bool equals(const char* a, const char* b) { return (strcasecmp (a, b) == 0); }
/* DILBERT END */

void peano::fillLookupTables() {
  setupLookupTableForTwoPowI();
  setupLookupTableForThreePowI();
  setupLookupTableForFourPowI();
  setupLookupTableForDPowI();

  peano::utils::setupLookupTableForDLinearised();
  peano::utils::setupLookupTableForDDelinearised();
}


int peano::initParallelEnvironment(int* argc, char*** argv) {
  // This is a dilbert patch to the effective MAIN
  /* DILBERT START */ {
    char* mode;
    mode = std::getenv("MODE");
    // by default, if no environment variable is given, do no assertions.
    if(mode!=NULL) {
      dilbert_Asserts = (equals(mode, "Debug") || equals(mode, "Asserts"));
      printf("Dilbert patches Peano: Assertion MODE='%s' was given, therefore Asserts=%s\n",
        mode, dilbert_Asserts ? "true" : "false");
    } else {
      dilbert_Asserts = false;
      printf("Dilbert patches Peano: Assertion MODE env var not given, thus Asserts=%s\n", dilbert_Asserts ? "true" : "false");
    }
    // print the decision, for understanding what goes on.
  } /* DILBERT END */

  #ifdef Parallel
  if ( tarch::parallel::Node::getInstance().init(argc,argv) ) {
    tarch::parallel::NodePool::getInstance().init();
    return 0;
  }
  else {
    return -2;
  }
  #else
  return 0;
  #endif
}


void peano::shutdownParallelEnvironment() {
  tarch::parallel::NodePool::getInstance().shutdown();
  tarch::parallel::Node::getInstance().shutdown();
}


int peano::initSharedMemoryEnvironment() {
  #ifdef SharedMemoryParallelisation
    #if defined(SharedTBBInvade)
    SHMController::cleanup();

    #ifdef Parallel
    MPI_Barrier(MPI_COMM_WORLD);
    #endif
    #endif
  if ( tarch::multicore::Core::getInstance().isInitialised() ) {
    return 0;
  }
  else {
    return -3;
  }
  #else
  return 0;
  #endif
}


void peano::shutdownSharedMemoryEnvironment() {
  #ifdef SharedMemoryParallelisation
  tarch::multicore::Core::getInstance().shutDown();
  #endif
}


void peano::releaseCachedData() {
  peano::grid::aspects::CellLocalPeanoCurve::releaseCachedData();
}
