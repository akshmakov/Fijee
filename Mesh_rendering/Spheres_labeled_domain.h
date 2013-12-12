#ifndef SPHERES_LABELED_DOMAIN_H_
#define SPHERES_LABELED_DOMAIN_H_
/*!
 * \file Spheres_labeled_domain.h
 * \brief brief describe 
 * \author Yann Cobigo
 * \version 0.1
 */
#include <iostream>
#include <fstream>      // std::ifstream, std::ofstream
//
// Eigen
//
#include <Eigen/Dense>
/*! \namespace Domains
 * 
 * Name space for our new package
 *
 */
namespace Domains
{
  /*! \class Spheres_labeled_domain
   * \brief classe representing whatever
   *
   *  This class is an example of class I will have to use
   */
  class Spheres_labeled_domain
  {
  private:
//    // aseg.nii NIFTI information
//    // image information
//    //! number_of_pixels_x_ is number of pixels on X
//    int number_of_pixels_x_;
//    //! number_of_pixels_y_ is number of pixels on Y
//    int number_of_pixels_y_;
//    //! number_of_pixels_z_ is number of pixels on Z
//    int number_of_pixels_z_;
//    //! size_of_pixel_size_x_ is size of pixel on X
//    float size_of_pixel_size_x_;
//    //! size_of_pixel_size_y_ is size of pixel on Y
//    float size_of_pixel_size_y_;
//    //! size_of_pixel_size_z_ is size of pixel on Z
//    float size_of_pixel_size_z_;
//    // Transformation information
//    //! rotation_ is the rotation matrix
//    Eigen::Matrix< float, 3, 3 > rotation_;
//    //! translation_ is the translation matrix
//    Eigen::Matrix< float, 3, 1 > translation_;
//    //! qfac adapte the transformation in case of an improper rotation matrix (| rotation_ | = -1)
//    int qfac_;

    //! Inrimage file format (.inr) for the labeled domains of the head. 
    //! file_inrimage_ stream builds head_model.inr file that can be checked with medInria.
    std::ofstream* file_inrimage_;

    //! data_model_ represent, for each voxel, the segmentation label.
    char   *data_label_;

    //! data_position_ is the center's position of data_label_'s voxels.
    double **data_position_;

  public:
    /*!
     *  \brief Default Constructor
     *
     *  Constructor of the class Spheres_labeled_domain
     *
     */
    Spheres_labeled_domain();
    /*!
     *  \brief Copy Constructor
     *
     *  Constructor is a copy constructor
     *
     */
    Spheres_labeled_domain( const Spheres_labeled_domain& ) = delete;
    /*!
     *  \brief Move Constructor
     *
     *  Constructor is a moving constructor
     *
     */
    Spheres_labeled_domain( Spheres_labeled_domain&& ) = delete;
    /*!
     *  \brief Destructeur
     *
     *  Destructor of the class Spheres_labeled_domain
     */
    virtual ~Spheres_labeled_domain();
    /*!
     *  \brief Operator =
     *
     *  Operator = of the class Spheres_labeled_domain
     *
     */
    Spheres_labeled_domain& operator = ( const Spheres_labeled_domain& ) = delete;
    /*!
     *  \brief Move Operator =
     *
     *  Move operator of the class Spheres_labeled_domain
     *
     */
    Spheres_labeled_domain& operator = ( Spheres_labeled_domain&& ) = delete;
    /*!
     *  \brief Operator ()
     *
     *  Object function for multi-threading
     *
     */
    void operator ()();

  public:
    /*!
     *  \brief Set pos_x_ value
     *
     *  This method set the x coordinate pos_x_.
     *
     *  \param Pos_X : The new position X.
     */
    //    inline void set_pos_x( int Pos_X ){pos_x_ = Pos_X;};

  public:
    /*!
     *  \brief Process the spheres segmentation
     *
     *  This method uses the head ressources (STL meshes, aseg.mgz) from FreeSurfer 
     *  to precess the segmented domains.
     *
     */
    void model_segmentation();
    /*!
     *  \brief Write inrimage
     *
     *  This method write the data_mode_ array in the head_model.inr inrimage file format.
     *
     */
    inline void write_inrimage_file()
    {
      file_inrimage_->write( data_label_, 256*256*256 );
    };

  };
  /*!
   *  \brief Dump values for Spheres_labeled_domain
   *
   *  This method overload "<<" operator for a customuzed output.
   *
   *  \param Point : new position to add in the list
   */
  std::ostream& operator << ( std::ostream&, const Spheres_labeled_domain& );
};
#endif