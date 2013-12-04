#ifndef _BOUNDARY_H
#define _BOUNDARY_H
#include <dolfin.h>

//using namespace dolfin;

/*! \namespace Solver
 * 
 * Name space for our new package
 *
 */
//
// Sub domain for Dirichlet boundary condition
//
class Periphery : public dolfin::SubDomain
{
  bool inside(const dolfin::Array<double>& x, bool on_boundary) const
  {
    //    return ( on_boundary );
    return ( on_boundary  );
  }
};
#endif
