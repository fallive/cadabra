/* 

	Cadabra: a field-theory motivated computer algebra system.
	Copyright (C) 2001-2011  Kasper Peeters <kasper.peeters@aei.mpg.de>

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
*/

/**

  Functions to handle the exchange properties of two or more symbols
  in a product. This module is only concerned with the exchange 
  properties of tensors as a whole, not with index permutation symmetries 
  (which are handled in the canonicalise class of algebra.cc).

*/

#ifndef exchange_hh_
#define exchange_hh_

#include "storage.hh"
#include <vector>
#include "modules/algebra.hh"
#include "modules/gamma.hh"

class exchange {
	public:
		struct identical_tensors_t {
				unsigned int                           number_of_indices;
				std::vector<exptree::sibling_iterator> tensors;
				std::vector<int>                       seq_numbers_of_first_indices;

				const SelfCommutingBehaviour *comm;
				const Spinor                 *spino;
				const TableauBase            *tab;
				const Traceless              *traceless;
				const GammaTraceless         *gammatraceless;
				int                           extra_sign;
		};

		// Obtain index exchange symmetries under tensor permutation. Returns 'false' if 
		// an identically zero expression is encountered.
		static int          collect_identical_tensors(exptree& tr, exptree::iterator it,
																	 std::vector<identical_tensors_t>& idts);
		static unsigned int possible_singlets(exptree&, exptree::iterator);
		static bool         get_node_gs(exptree&, exptree::iterator, std::vector<std::vector<int> >& );

//		static void get_index_gs(exptree::iterator, std::vector<std::vector<int> >& );

		struct tensor_type_t {
				nset_t::iterator name;
				unsigned int     number_of_indices;
		};

};

bool operator<(const exchange::tensor_type_t& one, const exchange::tensor_type_t& two);

#endif
