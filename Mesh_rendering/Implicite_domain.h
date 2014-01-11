#ifndef IMPLICITE_DOMAIN_H_
#define IMPLICITE_DOMAIN_H_
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>      // std::stringstream
#include <map>
#include <set>
#include <vector>
//
// UCSF
//
#include "Access_parameters.h"
#include "Point_vector.h"
#include "Utils/enum.h"
//
// CGAL
//
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Implicit_surface_3.h>
#include <CGAL/Poisson_reconstruction_function.h>
#include <CGAL/Point_with_normal_3.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/compute_average_spacing.h>
//
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Point_with_normal_3<Kernel> Point_with_normal;
typedef CGAL::Poisson_reconstruction_function<Kernel> Poisson_reconstruction_function;
typedef Kernel::FT FT;
//
//
//
//http://franckh.developpez.com/tutoriels/outils/doxygen/
/*!
 * \file Implicite_domain.h
 * \brief brief explaination 
 * \author Yann Cobigo
 * \version 0.1
 */
/*! \namespace Domains
 * 
 * Name space for our new package
 *
 */
namespace Domains
{
  /*! \class Implicite_domain
   * \brief classe building a list of "vertex, normal".
   *
   *  This class build a list of "vertex, normal" associated to a STL format mesh. This list will be an input of CGAL oracle for the construction of an implicite surface.
   * The implicite functions will help cearting the INRIMAGE format 3D image.  
   *
   */
  class Implicite_domain
  {
  public:
    virtual ~Implicite_domain(){/* Do nothing */};
    /*!
     *  \brief Move Operator ()
     *
     *  Object function for multi-threading
     *
     */
    virtual void operator ()( double** ) = 0;

  public:
    /*!
     *  \brief Get extrema values
     *
     *  This method return the extrema of the poly data point set.
     *
     *  \return extrema
     */
    virtual inline const double* get_poly_data_bounds_() const = 0;
    /*!
     *  \brief Get point_normal vector
     *
     *  This method return point_normal_ of the STL mesh.
     *
     *  \return point_normal_
     */
    virtual inline
      std::list< Domains::Point_vector > get_point_normal_() const = 0;
 
  public:
    /*!
     *  \brief Check if a point is inside a domain
     *
     *  This method check if a point is inside a domain.
     *
     */
    virtual inline bool inside_domain( CGAL::Point_3< Kernel > Point ) = 0;

  };
};
#endif
