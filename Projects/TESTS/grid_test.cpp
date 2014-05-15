/*
 * @file grid_test.cpp
 * @brief Test Physika grid and iterators.
 * @author FeiZhu
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#include <iostream>
#include "Physika_Core/Vectors/vector_2d.h"
#include "Physika_Core/Vectors/vector_3d.h"
#include "Physika_Core/Range/range.h"
#include "Physika_Geometry/Cartesian_Grid/grid.h"
using namespace std;
using Physika::Grid;
using Physika::Range;
using Physika::Vector;

int main()
{
    Range<float,2> domain = Range<float,2>::unitRange();
    int cell_num = 2;
    Grid<float,2> grid(domain,cell_num);
    cout<<"Node Number: "<<grid.nodeNum()<<"\n";
    cout<<"Cell Number: "<<grid.cellNum()<<"\n";
    cout<<"DX: "<<grid.dX()<<"\n";
    cout<<"Domain min corner: "<<grid.minCorner()<<"\n";
    cout<<"Domain max corner: "<<grid.maxCorner()<<"\n";
    cout<<"Min edge length: "<<grid.minEdgeLength()<<"\n";
    cout<<"Max edge length: "<<grid.maxEdgeLength()<<"\n";
    cout<<"Cell size: "<<grid.cellSize()<<"\n";
    //visit node with index
    cout<<"Visit node with index:\n";
    for(int i = 0; i < grid.nodeNum()[0]; ++i)
	for(int j = 0; j < grid.nodeNum()[1]; ++j)
	    cout<<"Node ("<<i<<","<<j<<"): "<<grid.node(i,j)<<endl;
    //visit node with iterator
    cout<<"Visit node with iterator:\n";
    Grid<float,2>::NodeIterator node_iterator = grid.nodeBegin();
    while(node_iterator != grid.nodeEnd())
    {
	Vector<int,2> index = node_iterator.nodeIndex();
	cout<<"Node "<<index<<": "<<grid.node(index)<<endl;
	++node_iterator;
    }
    //visit cell with index
    cout<<"Visit cell with index:\n";
    for(int i = 0; i < grid.cellNum()[0]; ++i)
	for(int j = 0; j < grid.cellNum()[1]; ++j)
	    cout<<"Cell ("<<i<<","<<j<<"): "<<grid.cellCenter(i,j)<<endl;
    //visit node with iterator
    cout<<"Visit cell with iterator:\n";
    Grid<float,2>::CellIterator cell_iterator = grid.cellBegin();
    while(cell_iterator != grid.cellEnd())
    {
	Vector<int,2> index = cell_iterator.cellIndex();
	cout<<"Cell "<<index<<": "<<grid.cellCenter(index)<<endl;
	++cell_iterator;
    }
    //test == operator
    Grid<float,2> grid2(domain,cell_num);
    if(grid==grid2)
	cout<<"Yes\n";
    else
	cout<<"No\n";
    //test iterator operations
    node_iterator = grid.nodeBegin();
    cout<<"NodeBegin: "<<node_iterator.nodeIndex()<<"\n";
    cout<<"NodeBegin+6: "<<(node_iterator+6).nodeIndex()<<"\n";
    cout<<"NodeEnd-5: "<<(grid.nodeEnd()-5).nodeIndex()<<"\n";
    cout<<"NodeEnd index: "<<(grid.nodeEnd()).nodeIndex()<<"\n";
    return 0;
}