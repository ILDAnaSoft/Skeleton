

#ifndef _EXAMPLE_PROCESSOR_H_
#define _EXAMPLE_PROCESSOR_H_

#include "marlin/Processor.h"

class ExampleProcessor : public marlin::Processor {
public:
  /**
   *  @brief  Factory method to create a processor
   *
   *  This method is called internally by Marlin to create an instance of your processor
   */
  marlin::Processor* newProcessor() { return new ExampleProcessor(); }
  
  /**
   *  @brief  Constructor
   *
   *  Regiter your parameters in there. See ExampleProcessor.cc
   */
  ExampleProcessor();
  
  // These two lines avoid frequent compiler warnings when using -Weffc++
  ExampleProcessor( const ExampleProcessor& ) = delete;
  ExampleProcessor& operator=( const ExampleProcessor& ) = delete;
  
  /** 
   *  @brief  Called once at the begin of the job before anything is read.
   *  
   *  Use to initialize the processor, e.g. book histograms. The parameters that
   *  you have registered in the constructor are initialized
   */
  void init();

  /** 
   *  Called for every run read from the file. 
   *  
   *  If you use simulation data output from ddsim (e.g from production data on grid),
   *  this will be called before the first event and only once in the job.
   */
  void processRunHeader( EVENT::LCRunHeader* run );
  
  /** 
   *  @brief  Called for every event - the working horse.
   *
   *  Analyze your reconstructed particle objects from the event object here.
   *  See ExampleProcessor.cc for an example
   */
  void processEvent( EVENT::LCEvent * event );
  
  /** 
   *  @brief  Called after data processing for clean up.
   *
   *  You have allocated memory somewhere in your code ? 
   *  This is the best place to clean your mess !
   */
  void end();
  
private:
  // Initialize your members in the class definition to 
  // be more efficient and avoid compiler warnings

  /// The reconstructed particle collection name
  std::string            m_pfoCollectionName = {""};
  float                  m_pfoEnergyCut = {0.f};
};

#endif