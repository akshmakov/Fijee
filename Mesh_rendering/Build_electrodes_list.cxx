#include "Build_electrodes_list.h"
//
// UCSF
//
#include "Utils/enum.h"
#include "Labeled_domain.h"
#include "VTK_implicite_domain.h"
//
//
//
#define PI 3.14159265359
//
// We give a comprehensive type name
//
typedef Domains::Build_electrodes_list DBel;
//
//
//
DBel::Build_electrodes_list()
{
  //
  // Load the MNI electrode positions
  pugi::xml_document     xml_file;
  pugi::xml_parse_result result = xml_file.load_file( (Domains::Access_parameters::get_instance())->get_electrodes_10_20_() );

  int number_electrods_;
  //
  switch( result.status )
    {
    case pugi::status_ok:
      {
	//
	// Check that we have a FIJEE XML file
	const pugi::xml_node fijee_node = xml_file.child("fijee");
	if (!fijee_node)
	  {
	    std::cerr << "Read data from XML: Not a FIJEE XML file" << std::endl;
	    exit(1);
	  }
	
	//
	// Get dipoles node
	const pugi::xml_node electrodes_node = fijee_node.child("electrodes");
	if (!electrodes_node)
	  {
	    std::cerr << "Read data from XML: Not a FIJEE XML file" << std::endl;
	    exit(1);
	  }
	// Get the number of dipoles
	number_electrods_ = electrodes_node.attribute("size").as_int();

	//
	//
	for( auto electrode : electrodes_node )
	  {
	    int index = electrode.attribute("index").as_uint();
	    // Name of the electrode
	    std::string label = electrode.attribute("label").as_string();
	    // Cartesian position
	    double position_x = electrode.attribute("x").as_double();
	    double position_y = electrode.attribute("y").as_double();
	    double position_z = electrode.attribute("z").as_double();
	    // Spherical position
	    double phi    = electrode.attribute("phi").as_double();
	    double theta  = electrode.attribute("theta").as_double();
	    double radius = electrode.attribute("radius").as_double();
	    // move in a regular spherical frame work
	    // x = r * cos(phi) * sin(theta)
	    // y = r * sin(phi) * sin(theta)
	    // z = r * cos(theta)
	    phi = phi * PI / 180.;
	    theta = PI/2. - theta * PI / 180.;

	    //
	    // Standard-10-20-Cap81
	    // Nz ~ (1,0,0) 
	    // Our framework: Nz ~ (0,1,0)
	    // We apply
	    //
	    //     | cos(Pi/2) = 0   -sin(Pi/2) = -1  0 |
	    // R = | sin(Pi/2) = 1    cos(Pi/2) =  0  0 |
	    //     |      0                0          1 |
	    // !!!Take automatique vectors from VTK_implicite _domain.cxx!!!
	    float temp_x = position_x;
	    position_x = -(position_y - 6); 
	    position_y =  temp_x; 
	    position_z = position_z + 38;
	    //
	    phi += PI/2.;

	    //
	    electrodes_.push_back( Domains::Electrode( index, label, 
						       position_x, position_y, position_z,
						       radius, phi, theta ) );
	  }
	//
	break;
      };
    default:
      {
	std::cerr << "Error reading XML file: " << result.description() << std::endl;
	exit(1);
      }
    }
}
////
////
////
//DBel::Build_electrodes_list( const DBel& that )
//{
//}
////
////
////
//DBel& 
//DBel::operator = ( const DBel& that )
//{
//
//  //
//  //
//  return *this;
//}
//
//
//
void
DBel::adjust_cap_positions_on( Labeled_domain< VTK_implicite_domain, GT::Point_3, std::list< Point_vector > >&  Sclap )
{
  for( auto electrode = electrodes_.begin() ; 
       electrode     != electrodes_.end() ; 
       electrode++  
       )
    {
//      std::cout << "================" << std::endl << std::endl;
//      std::cout << "avant" << std::endl;
//      std::cout << electrode.get_index_() << " " << electrode.get_label_()  << std::endl;
//      std::cout << electrode.x() << " " << electrode.y() << " " << electrode.z() << std::endl;
      while( Sclap.inside_domain(GT::Point_3( electrode->x(),
					      electrode->y(),
					      electrode->z() )) )
	{
	  electrode->x() += electrode->vx();
	  electrode->y() += electrode->vy();
	  electrode->z() += electrode->vz();
	}
//      std::cout << "Apres" << std::endl;
//      std::cout << electrode.get_index_() << " " << electrode.get_label_()  << std::endl;
//      std::cout << electrode.x() << " " << electrode.y() << " " << electrode.z() << std::endl;
    }
}
//
//
//
bool
DBel::inside_domain( GT::Point_3 Point )
{
  for( auto electrode : electrodes_ )
    {
      if(electrode.inside_domain( Point.x(), Point.y(), Point.z() ))
	return true;
    }
  
  //
  //
  return false;
}
//
//
//
std::ostream& 
Domains::operator << ( std::ostream& stream, 
		       const DBel& that)
{
//  std::for_each( that.get_list_position().begin(),
//		 that.get_list_position().end(),
//		 [&stream]( int Val )
//		 {
//		   stream << "list pos = " << Val << "\n";
//		 });
//  //
//  stream << "position x = " <<    that.get_pos_x() << "\n";
//  stream << "position y = " <<    that.get_pos_y() << "\n";
//  if ( &that.get_tab() )
//    {
//      stream << "tab[0] = "     << ( &that.get_tab() )[0] << "\n";
//      stream << "tab[1] = "     << ( &that.get_tab() )[1] << "\n";
//      stream << "tab[2] = "     << ( &that.get_tab() )[2] << "\n";
//      stream << "tab[3] = "     << ( &that.get_tab() )[3] << "\n";
//    }
  //
  return stream;
};
