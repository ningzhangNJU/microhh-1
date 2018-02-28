/*
 * MicroHH
 * Copyright (c) 2011-2017 Chiel van Heerwaarden
 * Copyright (c) 2011-2017 Thijs Heus
 * Copyright (c) 2014-2017 Bart van Stratum
 *
 * This file is part of MicroHH
 *
 * MicroHH is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * MicroHH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with MicroHH.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ADVEC_2
#define ADVEC_2

#include "advec.h"

class Master;
template<typename> class Advec;
template<typename> class Grid;
template<typename> class Fields;
class Input;

/**
 * Derived class for 2nd order advection scheme.
 */
template<typename TF>
class Advec_2 : public Advec<TF>
{
    public:
        Advec_2(Master&, Grid<TF>&, Fields<TF>&, Input&); ///< Constructor of the advection class.
        virtual ~Advec_2();              ///< Destructor of the advection class.

        virtual void exec(); ///< Execute the advection scheme.
        virtual unsigned long get_time_limit(long unsigned int, double); ///< Get the limit on the time step imposed by the advection scheme.
        virtual double get_cfl(double); ///< Get the CFL number.

    private:
        using Advec<TF>::master;
        using Advec<TF>::grid;
        using Advec<TF>::fields;
        using Advec<TF>::field3d_operators;

        using Advec<TF>::cflmax;
        using Advec<TF>::cflmin;
        using Advec<TF>::swadvec;
};
#endif
