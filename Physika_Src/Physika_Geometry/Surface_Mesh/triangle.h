/*
 * @file triangle.h 
 * @Basic triangle class.
 * @author Sheng Yang
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#ifndef PHYSIKA_GEOMETRY_SURFACE_MESH_TRIANGLE_H_
#define PHYSIKA_GEOMETRY_SURFACE_MESH_TRIANGLE_H_


#include "Physika_Core/Vectors/vector.h"


using Physika::Vector3D;


namespace Physika{

template <typename Scalar> class Vertex;
template <typename Scalar> class Edge;

template <typename Scalar>
class Triangle
{
public:
    /* Constructions */
    Triangle();

    /* Get and Set */
    inline Scalar area() const { return area_; }
    inline Vector3D<Scalar> center() const { return center_; }
    inline Vector3D<Scalar> normal() const { return normal_; }
    inline Vertex<Scalar> * vertices(int i ) { return vertices_[i]; }
    inline Edge<Scalar> * edges(int i) { return edges_[i]; }

    inline void set_area(Scalar area) { area_ = area; }
    inline void set_normal(Scalar normal) { normal_ = normal; }
    inline void set_center(Scalar center) { center_ = center; }

    Vector3D<Scalar> computeNormals();

protected:
    Vertex<Scalar> *vertices_[3];
    Edge<Scalar> *edges_[3];
    Vector3D<Scalar> normal_;
    Vector3D<Scalar> center_;
    Scalar area_;
};

} //end of namespace Physika

#endif //PHYSIKA_GEOMETRY_SURFACE_MESH_TRIANGLE_H_

