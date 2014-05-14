#ifndef ITERATIVE_MINIMIZER_H
#define ITERATIVE_MINIMIZER_H
#include <list>
#include <memory>
#include <string>
#include <functional>
//
// UCSF project
//
//#include "Utils/Thread_dispatching.h"
//
//
//
//using namespace dolfin;
//
/*!
 * \file Iterative_minimizer.h
 * \brief brief describe 
 * \author Yann Cobigo
 * \version 0.1
 */

/*! \namespace Solver
 * 
 * Name space for our new package
 *
 */
namespace Utils
{
  namespace Minimizers
  {
    typedef std::function< double( const Eigen::Vector3d& ) > Function;
    typedef std::tuple< 
      double,          /* - 0 - estimation */
      Eigen::Vector3d /* - 1 - sigma (0) skin, (1) skull spongiosa, (2) skull compacta */
      > Estimation_tuple;

   /*! \class Iterative_minimizer
     * \brief classe representing the dipoles distribution
     *
     *  This class is an example of class I will have to use
     */
    template < typename Minimizer_algo >
      class Iterative_minimizer
      {
      private:
	Minimizer_algo minimizer_;

      public:
	/*!
	 *  \brief Default Constructor
	 *
	 *  Constructor of the class Iterative_minimizer
	 *
	 */
	Iterative_minimizer(){};
	/*!
	 *  \brief Copy Constructor
	 *
	 *  Constructor is a copy constructor
	 *
	 */
	Iterative_minimizer( const Iterative_minimizer& ){};
	/*!
	 *  \brief Operator =
	 *
	 *  Operator = of the class Iterative_minimizer
	 *
	 */
	Iterative_minimizer& operator = ( const Iterative_minimizer& ){};
	//    /*!
	//     *  \brief Operator ()
	//     *
	//     *  Operator () of the class Iterative_minimizer
	//     *
	//     */
	//    void operator () ();

      public:
	/*!
	 *  \brief initialization function
	 *
	 *  This method initialized the minimizer
	 */
	void initialization( Function Fun,  
			     const std::vector< Estimation_tuple >& Simplex,
			     const std::map< Brain_segmentation, std::tuple<double, double> >& Boundaries)
	{
	  minimizer_.initialization( Fun, Simplex, Boundaries );
	};
	/*!
	 *  \brief minimize function
	 *
	 *  This method launch the minimization algorithm
	 */
	void minimize()
	{
	  minimizer_.minimize();
	};
      };
  }
}
#endif