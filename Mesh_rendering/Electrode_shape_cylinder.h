#ifndef ELECTRODE_SHAPE_CYLINDER_H
#define ELECTRODE_SHAPE_CYLINDER_H
//http://franckh.developpez.com/tutoriels/outils/doxygen/
/*!
 * \file Electrode_shape_cylinder.h
 * \brief brief describe 
 * \author Yann Cobigo
 * \version 0.1
 */
#include <iostream>
#include <memory>
//
// UCSF
//
#include "Electrode_shape.h"
#include "Point.h"
#include "Point_vector.h"
#include "Access_parameters.h"
//
// Eigen
//
#include <Eigen/Dense>
//
//
//
/*! \namespace Domains
 * 
 * Name space for our new package
 *
 */
namespace Domains
{
  /*! \class Shape
   * \brief classe representing whatever
   *
   *  This class is an example of class 
   * 
   */
  class Electrode_shape_cylinder : public Electrode_shape
  {
  private:
    //! Cylinder radius of the cylindrical electrode
    float radius_;
    //! Cylinder height of the cylindrical electrode
    float height_;

  public:
    /*!
     *  \brief Default Constructor
     *
     *  Constructor of the class Electrode_shape_cylinder
     *
     */
    Electrode_shape_cylinder();
    /*!
     *  \brief Default Constructor
     *
     *  Constructor of the class Electrode_shape_cylinder
     *
     */
    Electrode_shape_cylinder( float Radius, float Height );
    /*!
     *  \brief Destructeur
     *
     *  Destructor of the class Electrode_shape_cylinder
     */
    virtual ~Electrode_shape_cylinder(){/* Do nothing*/};
    /*!
     *  \brief Copy Constructor
     *
     *  Constructor is a copy constructor
     *
     */
    Electrode_shape_cylinder( const Electrode_shape_cylinder& ){};
    /*!
     *  \brief Operator =
     *
     *  Operator = of the class Electrode_shape_cylinder
     *
     */
    Electrode_shape_cylinder& operator = ( const Electrode_shape_cylinder& ){return *this;};

  public:
    ucsf_get_macro(radius_, float);
    ucsf_get_macro(height_, float);

  public:
    /*!
     *  \brief inside 
     *
     *  This function check if the point (X, Y, Z) is inside the Cylinder Shape with the radius Shape_radius.
     *
     *  \param Center: center of the shape
     *  \param X: x-position of the checl point
     *  \param Y: y-position of the checl point
     *  \param Z: z-position of the checl point
     *
     */
    virtual bool inside( Domains::Point_vector& Center, 
			 float X, float Y, float Z ) const;
    /*!
     *  \brief Size of the contact surface
     *
     *  This function return the size of the contect surface between the electrode and the scalp.
     *
     */
    virtual float contact_surface()const{return PI * radius_ * radius_  /* mm^2 */;};
    /*!
     *  \brief print members
     *
     *  This function print the class members
     *
     */
    virtual void print( std::ostream& ) const;
  };
  /*!
   *  \brief Dump values for Electrode
   *
   *  This method overload "<<" operator for a customuzed output.
   *
   */
  std::ostream& operator << ( std::ostream&, const Electrode_shape_cylinder& );
};
#endif
