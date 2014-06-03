//  Copyright (c) 2014, Yann Cobigo 
//  All rights reserved.     
//   
//  Redistribution and use in source and binary forms, with or without       
//  modification, are permitted provided that the following conditions are met:   
//   
//  1. Redistributions of source code must retain the above copyright notice, this   
//     list of conditions and the following disclaimer.    
//  2. Redistributions in binary form must reproduce the above copyright notice,   
//     this list of conditions and the following disclaimer in the documentation   
//     and/or other materials provided with the distribution.   
//   
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED   
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE   
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR   
//  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES   
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;   
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND   
//  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS   
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   
//     
//  The views and conclusions contained in the software and documentation are those   
//  of the authors and should not be interpreted as representing official policies,    
//  either expressed or implied, of the FreeBSD Project.  
#ifndef _EMPIRICAL_BAYESIAN_MODEL_H
#define _EMPIRICAL_BAYESIAN_MODEL_H
#include <list>
#include <memory>
#include <string>
#include <mutex>
#include <stdexcept>      // std::logic_error
//
// pugixml
// same resources than Dolfin
//
#include "Utils/pugi/pugixml.hpp"
//
// UCSF project
//
#include "Inverse_solver.h"
//
//
//
/*!
 * \file Empirical_bayesian_model.h
 * \brief brief describe 
 * \author Yann Cobigo
 * \version 0.1
 */

/*! \namespace Solver
 * 
 * Name space for our new package
 *
 */
namespace Inverse
{
  /*! \class Empirical_bayesian_model
   * \brief classe representing the source localisation with subtraction method.
   *
   *  This class representing the Physical model for the source localisation using the subtraction method.
   */
  class Empirical_bayesian_model : Inverse_solver
  {
  private:
    //! Number of dipoles
    int number_dipoles_;

//    //! Dipoles list
//    std::list< Solver::Phi > dipoles_list_;
    
  private:
    std::mutex critical_zone_;

  public:
    /*!
     *  \brief Default Constructor
     *
     *  Constructor of the class Empirical_bayesian_model
     *
     */
    Empirical_bayesian_model();
    /*!
     *  \brief Copy Constructor
     *
     *  Constructor is a copy constructor
     *
     */
    Empirical_bayesian_model( const Empirical_bayesian_model& ){};
    /*!
     *  \brief Destructeur
     *
     *  Destructor of the class Empirical_bayesian_model
     */
    virtual ~Empirical_bayesian_model(){/* Do nothing */};
    /*!
     *  \brief Operator =
     *
     *  Operator = of the class Empirical_bayesian_model
     *
     */
    Empirical_bayesian_model& operator = ( const Empirical_bayesian_model& ){return *this;};
    /*!
     *  \brief Operator ()
     *
     *  Operator () of the class Empirical_bayesian_model
     *
     */
    virtual void operator () ();
    
  public:
    /*!
     *  \brief Get number of physical events
     *
     *  This method return the number of parallel process for the Physics solver. 
     *  In the case of source localization the number of events is the number of dipoles simulated.
     *
     */
    virtual inline
      int get_number_of_physical_events(){return number_dipoles_;};
  };
}
#endif